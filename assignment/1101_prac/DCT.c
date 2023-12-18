#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "DCT.h"



void DCT(unsigned char buffer[N][N], float result[N][N]){
	int u, v, x, y;
	float alpha_u, alpha_v, sum, cu, cv;
	float C[N][N];

	// read 'rdata.bin' to see buffer

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
	printf("===============================================================================");

	// Use DCT (normally DCT) 	

	for (u = 0; u < N; u++) {
		for (v = 0; v < N; v++) {

			alpha_u = (u == 0) ? 1.0f / sqrt(2.0f):1.0;
			alpha_v = (v == 0) ? 1.0f / sqrt(2.0f):1.0;

			// coeffiecient method

			C[u][v] = alpha_u * alpha_v;

		}
	}	 	


	for (u = 0; u < N; u++) {
		for (v = 0; v < N; v++) {
			sum = 0.0f; // initiallize sum to assign next index

			for (x = 0; x < N; x++) {
				for (y = 0; y < N; y++) {
					cu = (x == 0) ? 1.0f / sqrt(2) : 1.0f;
					cv = (y == 0) ? 1.0f / sqrt(2) : 1.0f;
					// where cu=cv=1/sqrt(2) for m, n= 0 and cu, cv, = 1 otherwise

					sum += cu * cv * buffer[x][y] *
					    cosf(((2 * x + 1) * u * M_PI) / (2.0f * N)) *
					    cosf(((2 * y + 1) * v * M_PI) / (2.0f * N)); // += means SIGMA  
				}
			}
			result[u][v] =(2.0f/(sqrt(N*N)))*C[u][v]*sum;
		}
	}
}
