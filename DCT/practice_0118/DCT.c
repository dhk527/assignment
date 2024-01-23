/*
   feedback 기능단위 분리가 부족 -> 차원 변환 따로 만들기, DCT, iDCT 연산도 따로 만들기...
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "DCT.h"
#include <string.h>

float getCval(int x, int y){
	if (x==0 && y==0)
		return (1.0f/1.0f*N);
	else if(x != 0&& y!= 0)
		return (2.0f/1.0f*N);
	else
		return sqrt (2.0f/1.0f*N); 
}  

void DCT1d(unsigned char buffer[ROWS][COLS], float result[ROWS*COLS]){

	if(buffer == NULL){
		perror("error\n");
	}

	printf ("\n========================================================\n");

	int u, v, i, j;
	int m = ROWS, n = COLS;
	float k;
	float csum = 0.0f;
	float iresult[ROWS*COLS]; 
	unsigned char change_buffer[ROWS*COLS];

/*	printf("size unsigned char= %ld \n",sizeof(unsigned char));

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++){  
			printf("%p ",&buffer[i][j]); // 1D 의 주소를 보여줌
		}
		//printf("\n");
	}
*/
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) { 
			change_buffer[i*n+j] = buffer[i][j];
		//	printf("%d ",change_buffer[i*n+j]); // 2D를 1D로 변환완료.
		}
		//printf("\n");
	}

	printf("\n\nDCT 1-Dimension  변환 시 : \n");
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			csum = 0;

			for (u = 0; u < m; u++)
				for (v = 0; v < n; v++)
					csum += change_buffer[u*n + v]
						*cos((2 * u + 1) * i * M_PI / (2 * m))
						*cos((2 * v + 1) * j * M_PI / (2 * n));

			if (!i && !j) k = 0.5;
			else if ((!i && j) || (i && !j)) k = 1 / sqrt(2);
			else k = 1;

			result[i * n + j] = (2 * csum * k) / n;
			printf("%.1f ", result[i*n + j]); // fractio 아래 1자리
		}
		printf("\n");
	}    
	printf("\nInverse DCT 1-Dimension  변환시 \n");
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			csum = 0;

			for (u = 0; u < m; u++)
				for (v = 0; v < n; v++) {
					if (!u && !v) k = 0.5;
					else if ((!u && v) || (u && !v)) k = 1 / sqrt(2);
					else k = 1;
					csum += k * result[u * n + v]
						* cos((2 * i + 1) * M_PI * u / (2 * m))
						* cos((2 * j + 1) * M_PI * v / (2 * n));
				}
			iresult[i * n + j] =  csum *(2.0 / n);

			printf("%.1f ", iresult[i * n + j]);
		}
		printf("\n");
	}
}

void DCT(unsigned char buffer[ROWS][COLS], float result[ROWS][COLS]){

	if(buffer == NULL){
		perror("error\n");
	}
	printf("\n===============================================================================\n"); 

	int u,v,m,n,i,j;
	m= ROWS, n=COLS;
	float k;
	float csum = 0;
	float iresult[ROWS][COLS];

	printf("\nDCT 변환 시 : \n");
	for(i = 0;i < m;i++){
		for(j = 0;j < n;j++){

			for(u = 0;u < m;u++)
				for(v = 0;v < n;v++)
					csum += buffer[u][v]
						*cos((2*u+1)*i*M_PI/(2*m))
						*cos((2*v+1)*j*M_PI/(2*n));
			if(!i && !j) k = 0.5;
			else if((!i && j) || (i && !j)) k = 1/sqrt(2);
			else k = 1;
			result[i][j] = 2*csum*k/n;

			printf("%.1f ",result[i][j]);//fraction 1자리
			csum = 0;
		}
		printf("\n");
	}

	printf("\nInverse DCT 변환시 \n");
	csum = 0;
	for(i = 0;i < m;i++){
		for(j = 0;j < n;j++){
			for(u = 0;u < m;u++)
				for(v = 0;v < n;v++){
					if(!u && !v) k = 0.5;
					else if((!u && v) || (u && !v)) k = 1/sqrt(2);
					else k = 1;
					csum += k*result[u][v]
						*cos((2*i+1)*M_PI*u/(2*m))
						*cos((2*j+1)*M_PI*v/(2*n));
				}
			iresult[i][j] = csum*2/n;
			csum = 0;
			printf("%0.1f ",iresult[i][j]);
		}
		printf("\n");
	}

}

float** dynamic_DCT_1Dto2D(unsigned char buffer[ROWS][COLS], float **ppResult_2D)
{
	int i, j;
	float csum = 0.0f;
	float k = 0.0f;
	unsigned char* dynamicArray_1d = (unsigned char*)malloc(ROWS * COLS * sizeof(unsigned char)); // input 1d;

	for (i = 0; i < ROWS; i++)
		for (j = 0; j < COLS; j++)
			dynamicArray_1d[i*COLS + j] = buffer[i][j];//1차원 동적배열시 순서대로 출력됐음.

	printf("\n\n DCT malloc-1-Dimension 변환 시 : \n");
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLS; j++) {
			csum =0;

			for (int u = 0; u < ROWS; u++)
				for (int v = 0; v < COLS; v++)
					csum += dynamicArray_1d[u*COLS + v]
						* cos((2 * u + 1) * i * M_PI / (2 * ROWS))
						* cos((2 * v + 1) * j * M_PI / (2 * COLS));

			if (!i && !j) k = 0.5;
			else if ((!i && j) || (i && !j)) k = 1 / sqrt(2);
			else k = 1;

		   ppResult_2D[i][j]= (2 * csum * k) / COLS; // DCT 연산 이후 값들에 대해 동적 배열로 할당된 메모리에 값을 저장.
			printf("%.1f ", ppResult_2D[i][j]); 
		}
		printf("\n");
	}
	free(dynamicArray_1d);
	return ppResult_2D;
}

void  DCT_stdout(unsigned char buffer[ROWS][COLS]){


#ifdef DCT_1d
	float result[ROWS*COLS];
	DCT1d(buffer, result);
#elif defined(malloc_DCT_1d)
	float** ppResult_2D = (float**)malloc(sizeof(float*)*ROWS);// 2차원 포인터 배열을 가지는 포인터 

	for(int i=0; i<COLS; i++)
		ppResult_2D[i]=(float*)malloc(sizeof(float)*COLS); //i는 ROWS의 index주소를 가리키고( 간접 주소 지정 방식) 그 주소가 가리키는 곳은  malloc()을 써서 float타입의 COLS 수만큼을 크기를 할당 받은 메모의 첫 주소[0]번째 열(항)임... 
	    
	dynamic_DCT_1Dto2D(buffer, ppResult_2D);

	float**result = (float**)malloc(sizeof(float*) * ROWS);
	for (int i = 0; i < ROWS; i++) {
		result[i] = (float*)malloc(sizeof(float) * COLS);
		memcpy(result[i], ppResult_2D[i], sizeof(float) * COLS);
	}

	for(int i=0; i<ROWS;i++)
		free(ppResult_2D[i]);

	free(ppResult_2D);
#else
	float result[ROWS][COLS];
	DCT(buffer, result); // buffer는 fread한 주소 가리킴 , result는 DCT 변환 된 것
#endif
	printf("\ncomplete DCT transfomation\n");


	FILE* DCT_rdata_file;

	DCT_rdata_file = fopen("DCT_rdata.bin","wb");
	if(DCT_rdata_file == NULL){
		perror("fopen error");
	}

	fwrite(result, sizeof(char), ROWS*COLS, DCT_rdata_file);
	fclose(DCT_rdata_file);

#ifdef malloc_DCT_1d
	for(int i=0; i<COLS; i++)
		free(result[i]);
	free(result);
	printf("메모리해제\n");// 종료되는 시점이 명확하다면 free를 안해도 종료 시 반환이 되나, 그게 아니라면... 멀티 쓰레딩이든 시점이 명확하지 않을 시 지속적으로 memory leak이 발생할 수 있음.
#endif 

	printf("complete 'DCT_rdata_file'\n");
}


