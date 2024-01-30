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
	int u, v, i, j;
	int m = ROWS, n = COLS;
	float k;
	float csum = 0.0f;
	float iresult[ROWS*COLS]; 
	unsigned char change_buffer[ROWS*COLS];

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) { 
			change_buffer[i*n+j] = buffer[i][j];
		}
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
			printf("%.1f ", result[i*n + j]); // fraction 아래 1자리
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

void dyn_DCT_1D(unsigned char* input_dynArr, float *output_1D_dynarr)
{
	int i, j;
	float csum = 0.0f;
	float k = 0.0f;

	//printf("\n\n DCT malloc-1-Dimension 변환 시 : \n");
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLS; j++) {
			for (int u = 0; u < ROWS; u++)
				for (int v = 0; v < COLS; v++)
					csum += input_dynArr[u*COLS + v]
						* cos((2 * u + 1) * i * M_PI / (2 * ROWS))
						* cos((2 * v + 1) * j * M_PI / (2 * COLS));

			if (!i && !j) k = 0.5;
			else if ((!i && j) || (i && !j)) k = 1 / sqrt(2);
			else k = 1;

			output_1D_dynarr[i*COLS+j] = 2*csum*k/COLS;
			csum=0;		
		}
	}
	free(input_dynArr);

	float(*casting_output_2D)[COLS] = (float(*)[COLS])output_1D_dynarr;
	//1차원 배열을 2차원배열로 casting
	//l-value는 COLS 열만큼을 가지는 배열의 첫 주소를 가리킴
	//r-value는 type casting으로 l-value의 형식과 동일하고 1D를 2D처럼 casting시킴.
	printf("1차원을 2차원으로 casting하기\n");
	for (int i = 0; i < ROWS; i++){ 
		for (int j = 0; j < COLS; j++){ 
			printf("%.1f ", casting_output_2D[i][j]);//실제로 2차원 캐스팅으로 표현 됨.
		}
		printf("\n");
	}

}

void  DCT_stdout(unsigned char buffer[ROWS][COLS]){
#ifdef DCT_1d // 조건부 컴파일, 매크로 정의 때 사용.
	float result[ROWS*COLS];
	DCT1d(buffer, result);
#elif defined(malloc_DCT_1d)
	unsigned char* input_dynArr = (unsigned char*)malloc(ROWS * COLS * sizeof(unsigned char));// input 1차원 동적 배열

	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			input_dynArr[i*COLS + j] = buffer[i][j];// rdata.bin 2D to 1d, deep copy 

	float* output_1D_dynarr=(float*)malloc(sizeof(float)*COLS*COLS); //output 1차원 동적배열

	dyn_DCT_1D(input_dynArr, output_1D_dynarr); // 1차원 input, output 동적 할당 return 반환은 output으로 

	float* result=output_1D_dynarr;//메모리 해제를 output_1Dto2Darr 한다면 result가 가리키는 주소의 값은 메모리가 해제된 값이 되므로 dummy값을 가짐. shallow copy
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
	printf("메모리해제 해야 완료 \n");
	free(output_1D_dynarr);
	output_1D_dynarr=NULL;
	result=NULL;
#endif
	printf("complete 'DCT_rdata_file'\n");
}


