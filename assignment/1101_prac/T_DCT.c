#include <stdio.h>
#include "T_DCT.h"

// 2D DCT 계산 함수
void calculate2DDCT(unsigned char buffer[N][N], float output[N][N]) {

	if(buffer == NULL){
		printf ("error\n");
	}

	printf("'read rdata.bin'\n");
	for(int k = 0; k< N; k++){
		for (int n = 0; n < N; n++) {
			printf("%d ", buffer[k][n]);
		}
		printf("\n");
	}    
	printf("====================k===========================================================\n");

	float temp1[N][N];
	float temp2[N][N];

	for (int p = 0; p < N; p++) {
		for (int q = 0; q < N; q++) {
			float alpha_p = (p == 0) ? 1.0 / sqrt(N) : sqrt(2.0 / N);
			float alpha_q = (q == 0) ? 1.0 / sqrt(N) : sqrt(2.0 / N);
			T[p][q] = alpha_p * alpha_q 
			          *cos(((2.0 * p + 1) * M_PI * q) / 2 *  (2.0 * N));


			printf("%f ", T[p][q]);
		}
		printf("\n");
	}



	// T * buffer
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp1[i][j] = 0.0;
			for (int k = 0; k < N; k++) {
				for (int l = 0; l < N; l++) {
					temp1[i][j] += T[i][k] * buffer[k][l];
				}
			}
		}
	}

	// (T * buffer) * T'
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp2[i][j] = 0.0;
			for (int k = 0; k < N; k++) {
				for (int l = 0; l < N; l++) {
					temp2[i][j] += temp1[i][k] * T[j][l];
				}
			}
		}
	}

	// 결과 복사
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			output[i][j] = temp2[i][j];
		}
	}
}

void inv2DDCT(float input[N][N],float output[N][N],float T[N][N]){

	float temp1[N][N];
	float temp2[N][N];
	float Transpose[N][N];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Transpose[i][j] = T[j][i];
		}
	}   


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp1[i][j] = 0.0;
			for (int k = 0; k < N; k++) {
				for (int l = 0; l < N; l++) { 
					temp1[i][j] += Transpose [i][k] * input[k][l];
				}
			}
		}
	}   

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp2[i][j] = 0.0;
			for (int k = 0; k < N; k++) {
				for (int l = 0; l < N; l++) {
					temp2[i][j] += temp1[i][k] * Transpose[j][l];
				}
			}
		}
	}   

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			output[i][j] = temp2[i][j];
		}   
	}   
}



















