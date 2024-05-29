#ifndef NCO
#define NCO

#include "ezdsp5535.h"

extern Int16 data[];
extern Uint32 delta;
extern Int32 outputNCOSample(Int32* pa,Uint16 attenuation, Uint32 freq);

#endif
