#ifndef _DCT_H_
#define _DCT_H_

#define ROWS 16
#define COLS 16
#define N 16 

void DCT(unsigned char buffer[ROWS][COLS], float result[ROWS][COLS]);
void DCT1d(unsigned char buffer[ROWS][COLS], float result[ROWS*COLS]);
float** dynamic_DCT_1Dto2D(unsigned char buffer[ROWS][COLS], float** ppresult);
void DCT_stdout(unsigned char buffer[ROWS][COLS]);

#endif
