#include <std.h>

#include <log.h>

#include "biocfg.h"
#include "ezdsp5535.h"
#include "stdint.h"
#include "aic3204.h"
#include "ezdsp5535_i2s.h"
#include "csl_i2s.h"
#include "FIR.h"
#include "Dsplib.h"
#include "NCO.h"

//size of audio sample chunks used in processing
#define NUM_SAMPLES 48

extern CSL_I2sHandle   hI2s;
extern int state;
extern Int32 GD;

Int16 delayLine[30];
Uint32 rxctr = 0;
Uint32 txctr = 48;
Int16 buf1[48];
Int16 buf2[48];
Int16 buf3[60];
Int16 processedSamps[48];
Int16 temp[48];
Int32 NCOpa = 0;
Int16 NCOout = 0;

int i;
int j = 0;
int test = -1;



void audioProcessingInit(void)
{
	//zero out delayLine
	for(i = 0; i<60; i++){
		delayLine[i] = 0;
	}
	for (i = 0; i<60; i++){
		buf3[i]=0;
	}

	for(i = 0; i < 48; i++){
		buf1[i] = 0;
		buf2[i] = 0;
	}

	//Fill first two slots of MBX
	MBX_post(&MBXpostProcess, buf1, 0);
	MBX_post(&MBXpostProcess, buf1, 0);
    LOG_printf(&trace, "All buffers filled with 0");

}


void HWI_I2S_Rx(void)
{
	/*
	 * called at sampled rate i.e. 48kHz
	 */

	buf1[rxctr++] = (hI2s->hwRegs->I2SRXLT1);

	if(rxctr == 48){

		rxctr = 0;
		test = MBX_post(&MBXinSamples, buf1, 0);
		if(test == 0){
		    LOG_printf(&trace, "rx cant open mbx");
		}
	}


}

void HWI_I2S_Tx(void)
{
	/*
	 * called at sampled rate i.e. 48kHz
	 */

	if (state == 0){
		hI2s->hwRegs->I2STXLT1 = 0;
	}else if(state == 2){
		if((GD >> 16) < 3){
		if (j < 1){		// if (j < DS)
			hI2s->hwRegs->I2STXLT1 = buf2[txctr] << 2;
			j++;
		}else{
			hI2s->hwRegs->I2STXLT1 = buf2[txctr++] << 2;
			j = 0;
		}}
		else{
			if (j < 8){		// if (j < DS)
						hI2s->hwRegs->I2STXLT1 = buf2[txctr] << 2;
						j++;
					}else{
						hI2s->hwRegs->I2STXLT1 = buf2[txctr++] << 2;
						j = 0;
					}
		}
	}else if (state == 3){
		hI2s->hwRegs->I2STXLT1 = buf2[txctr++];
	}else if(state == 5){
		hI2s->hwRegs->I2STXLT1 = (buf2[txctr++] << (GD >> 16));
	}else{
	hI2s->hwRegs->I2STXLT1 = buf2[txctr++]; }

	if(txctr == 48){

		test = MBX_pend(&MBXpostProcess, buf2, 0);

		if(test == 0){
			LOG_printf(&trace, "tx can't open mbx");
		}
	    //LOG_printf(&trace, "postProcess Pended %d", test);
		txctr = 0;
	}
}


void TSK_audProcess(void){

	Int16 postProcessedSamps[48];
	while(1){

		test = MBX_pend(&MBXinSamples, processedSamps, SYS_FOREVER);
		//memcpy(temp, processedSamps, 48*sizeof(Int16));

		if (state == 0){	//mute
		}else if(state == 1){//normal playthrough
			maintainDL(processedSamps, buf3, NUM_SAMPLES);
			MBX_post(&MBXpostProcess, processedSamps, SYS_FOREVER);
		}else if(state == 2){//Downsampler that sounds like it downsamples way more than it actually is
				if((GD >> 16) < 3){
					myFir(processedSamps, LowPass, buf3, NUM_SAMPLES, NUM_TAPS);
				}
				else{
					myFir(processedSamps, LowPass1, buf3, NUM_SAMPLES, NUM_TAPS);
				}
			//maintainDL(processedSamps, delayLine, NUM_SAMPLES);
			MBX_post(&MBXpostProcess, processedSamps, SYS_FOREVER);
		}else if(state == 3){//Ring Mod?
			for (i = 0; i < 48; i++){
				temp[i] = outputNCOSample(&NCOpa,0, 5 + (GD >> 16));
				postProcessedSamps[i] = (processedSamps[i] * (32768 + (temp[i]))) >> 15;
				}
			MBX_post(&MBXpostProcess, postProcessedSamps, SYS_FOREVER);
			maintainDL(processedSamps, buf3, NUM_SAMPLES);
		}else if(state == 4){//Bass Boost, filter cutoff is 250Hz (more like 500)
			//maintainDL(processedSamps, buf3, NUM_SAMPLES);
			memcpy(temp, processedSamps, 48*sizeof(Int16));
			myFir(processedSamps, LowPass, buf3, NUM_SAMPLES, NUM_TAPS);
			for (i=0; i<48; i++){
				postProcessedSamps[i] = (processedSamps[i] << (GD >> 16)) + temp[i];
			}
			MBX_post(&MBXpostProcess, postProcessedSamps, SYS_FOREVER);
		}else if(state == 5){
			myFir(processedSamps, BandPass1, buf3, NUM_SAMPLES, NUM_TAPS);
			MBX_post(&MBXpostProcess, processedSamps, SYS_FOREVER);
		}else {}


	}

}

