#include <std.h>

#include <log.h>

#include "biocfg.h"
#include "ezdsp5535.h"
#include "stdint.h"
#include "aic3204.h"
#include "ezdsp5535_i2s.h"
#include "csl_i2s.h"
#include "ezdsp5535_led.h"
#include "csl_i2c.h"
#include "ezdsp5535_sar.h"
#include "fir.h"
#include "ezdsp5535_i2c.h"
#include "stdio.h"
#include "csl_gpio.h"
#include "ezdsp5535_gpio.h"
#include "inits.h"
#include "Conversion.h"
extern void audioProcessingInit(void);


char inputCMD[2];
int state = 1;
Int32 GD = 0;
void main(void)
{
    /* Initialize BSL */
    EZDSP5535_init( );

    audioProcessingInit();

    /* init LEDs */
    EZDSP5535_LED_init( );

    // configure the Codec chip
    ConfigureAic3204();

    /* Initialize I2S */
    //I2S_opening();
    EZDSP5535_I2S_init( );
    //Init buttons
    EZDSP5535_SAR_init();

    //init OLED

    /* enable the interrupt with BIOS call */
    //C55_enableInt(13); // UART Interrupt?
    C55_enableInt(14); // reference technical manual, I2S2 tx interrupt
    C55_enableInt(15); // reference technical manual, I2S2 rx interrupt

    // after main() exits the DSP/BIOS scheduler starts

    //UART STUFF BELOW

    EZDSP5535_GPIO_init();
    EZDSP5535_GPIO_setDirection( 15, GPIO_OUT );
    EZDSP5535_GPIO_setOutput( 15, 0 );
    UART_open();

}



void TSK_UserInterface(void)
{

	while(1){
Int16 pstate;

		EVM5515_UART_getChar( &inputCMD[0] );
		EVM5515_UART_getChar( &inputCMD[1] );
		//UART_str(inputCMD);






		//EVM5515_UART_putChar( inputCMD[0] );
		//EVM5515_UART_putChar( inputCMD[1] );

		//EVM5515_UART_getChar( &inputCMD[3] );
		//EVM5515_UART_getChar( &inputCMD[4] );



		if (inputCMD[0] == '~'){ state = 0;} //mute
		else if (inputCMD[0] == '}'){ state = 1; pstate = 1;}//normal operation, set state 1 to char
		else if (inputCMD[0] == '2'){ state = 2; pstate = 2;}//DownSampling, set state 2 to char
		else if (inputCMD[0] == '3'){state = 3; pstate = 3;}//ring modulation
		else if(inputCMD[0] == '1'){state = 4; pstate = 1;}//Bass Boost
		else if (inputCMD[0] == '0'){state = 5; pstate = 0;}//bit crushing/distortion?
		else {}  //no change

		GD = ConversionTable(inputCMD[1]);
	}
}
/*
void PRD_twoHzLED(void){
	//toggle le LED
	EZDSP5535_LED_toggle(2);


}*/



