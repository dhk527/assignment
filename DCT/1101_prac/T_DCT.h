#ifndef T_DCT_H
#define T_DCT_H

#include <math.h>
extern float T[N][N];
void calculate2DDCT(unsigned char input[N][N], float output[N][N]);
void inv2DDCT(float input[N][N],float output[N][N] , float T[N][N]);


#endif
