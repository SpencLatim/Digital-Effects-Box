
#include "aic3204.h"
#include "stdio.h"
#include "ezdsp5535.h"
#include "stdint.h"
#include "FIR.h"


void myFir(Int16 * restrict x, //input samples
		 Int16 * restrict h, //taps
		 Int16 * restrict delayLine,
		 Uint32 nx, //# of input samples
		 const Uint32 nh //# of taps
		 )
{
	Int16 i = 0;
	Int16 j = 0;
	Int16 k = 0;

	#pragma MUST_ITERATE(1,,)
	for(i = 0; i < nx; i++){

		Int32 result = 32768; // 2^15 for rounding
		delayLine[0] = x[i];

		#pragma MUST_ITERATE(1,,2)
		for(j = 0; j < nh; j++){

			result = _smac(result, delayLine[j], h[j]);
		}

	    for ( k = nh - 1; k > 0; k--) {
	        delayLine[k] = delayLine[k - 1];  // Shift the elements
	    }

	    delayLine[0] = 0;  // Place zero at the first index
	    x[i] = (Int16) _lshrs(result, 16);
	}

}

void myFir2(Int16 * restrict x, //input samples
		 Int16 * restrict h, //taps
		 Int16 * restrict delayLine,
		 Uint32 nx, //# of input samples
		 const Uint32 nh //# of taps
		 )
{
	Int16 i = 0;
	Int16 j = 0;
	Int16 k = 0;

	#pragma MUST_ITERATE(1,,)
	for(i = 0; i < nx; i+=2){

		Int32 result = 32768; // 2^15 for rounding
		delayLine[0] = x[i];
		delayLine[1] = x[i+1];

		#pragma MUST_ITERATE(1,,2)
		for(j = 0; j < nh; j++){

			result = _smac(result, delayLine[j], h[j]);
		}

	    for ( k = nh - 1; k > 0; k--) {
	        delayLine[k] = delayLine[k - 1];  // Shift the elements
	    }

	    delayLine[0] = 0;  // Place zero at the first index
	    x[i] = (Int16) _lshrs(result, 16);
	}

}


void maintainDL(Int16 *restrict sampleArray, Int16 *restrict delayLine, Uint32 arraySize) {
    Uint32 i, j;
    for (i = 0; i < arraySize; i++) {
        delayLine[0] = sampleArray[i];  // Update the first element with the new sample
        // Shift the elements
        for (j = NUM_TAPS - 1; j > 0; j--) {
            delayLine[j] = delayLine[j - 1];
        }
        delayLine[0] = 0;  // Place zero at the first index
    }
}


