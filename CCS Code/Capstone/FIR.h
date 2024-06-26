#ifndef CAPSTONE_FIR_H_
#define CAPSTONE_FIR_H_
#include "ezdsp5535.h"

#define NUM_TAPS 60
#define INPUT_SIZE 1

//30 Taps (500 cf)
//cutoff at around 300
static Int16 LowPass[] =
{
       408,    410,    412,    414,    416,    418,    420,    422,    423,    425,    427,    428,    429,    431,    432,    433,
       434,    435,    436,    437,    438,    438,    439,    440,    440,    440,    441,    441,    441,    441,    441,    441,
       441,    441,    440,    440,    440,    439,    438,    438,    437,    436,    435,    434,    433,    432,    431,    429,
       428,    427,    425,    423,    422,    420,    418,    416,    414,    412,    410,    408,
};

//cutoff at around 12100
static Int16 AAFilter[] =
{
      -110,    155,    -50,   -136,    208,    -53,   -196,    266,    -33,   -285,    327,     15,   -407,    389,    102,   -571,
       447,    249,   -800,    499,    499,  -1150,    541,    974,  -1805,    571,   2215,  -3849,    586,  17761,  17761,    586,
     -3849,   2215,    571,  -1805,    974,    541,  -1150,    499,    499,   -800,    249,    447,   -571,    102,    389,   -407,
        15,    327,   -285,    -33,    266,   -196,    -53,    208,   -136,    -50,    155,   -110,
};

//bandpass from 1.5k to 3k
static Int16 BandPass1[] =
{
   	223,	139, 	59,  	2,	-17, 	10, 	84,	193,	316,	425,	489,	479,	373,	162,   -146,   -528,
  	-943,  -1340,  -1662,  -1858,  -1882,  -1712,  -1345,   -803,   -135,	595,   1311,   1933,   2392,   2636,   2636,   2392,
  	1933,   1311,	595,   -135,   -803,  -1345,  -1712,  -1882,  -1858,  -1662,  -1340,   -943,   -528,   -146,	162,	373,
   	479,	489,	425,	316,	193, 	84, 	10,	-17,  	2, 	59,	139,	223,
};

//low pass up to 6k

static Int16 LowPass1[] =
{
  	-217,   -263,   -138, 	96,	294,	319,	132,   -168,   -393,   -383,   -112,	273,	528,	461, 	69,   -435,
  	-725,   -567, 	17,	711,   1061,	743,   -203,  -1302,  -1834,  -1181,	817,   3704,   6541,   8294,   8294,   6541,
  	3704,	817,  -1181,  -1834,  -1302,   -203,	743,   1061,	711, 	17,   -567,   -725,   -435, 	69,	461,	528,
   	273,   -112,   -383,   -393,   -168,	132,	319,	294, 	96,   -138,   -263,   -217,
};


//low pass up to 1.5k
static Int16 LowPass2[] =
{
   	106, 	55, 	-6,	-74,   -147,   -220,   -290,   -353,   -403,   -436,   -449,   -438,   -400,   -332,   -235,   -108,
    	47,	228,	431,	650,	881,   1117,   1350,   1575,   1783,   1968,   2124,   2246,   2329,   2372,   2372,   2329,
  	2246,   2124,   1968,   1783,   1575,   1350,   1117,	881,	650,	431,	228, 	47,   -108,   -235,   -332,   -400,
  	-438,   -449,   -436,   -403,   -353,   -290,   -220,   -147,	-74, 	-6, 	55,	106,
};


extern void myFir(Int16 * restrict x, //input samples
		 Int16 * restrict h, //taps
		 Int16 * restrict delayLine,
		 Uint32 nx, //# of input samples
		 Uint32 nh //# of taps
		 );

void myFir2(Int16 * restrict x, //input samples
		 Int16 * restrict h, //taps
		 Int16 * restrict delayLine,
		 Uint32 nx, //# of input samples
		 const Uint32 nh //# of taps
		 );

extern void maintainDL(Int16 *sampleArray, Int16 *restrict delayLine, Uint32 arraySize);

#endif /* CAPSTONE_FIR_H_ */
