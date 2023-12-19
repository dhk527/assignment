#include <stdio.h>
#include <math.h>
#include "DCT.h"



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

    printf("size unsigned char= %ld \n",sizeof(unsigned char));

  for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++){  
                 printf("%p ",&buffer[i][j]); // 2D를 1D로 변환완료.
}printf("\n");
}
     printf("\n\n");      
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) { 
            change_buffer[i*n+j] = buffer[i][j];
        printf("%p ",&change_buffer[i*n+j]); // 2D를 1D로 변환완료.
	}
        printf("\n");
  }
   
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) { 
            change_buffer[i*n+j] = buffer[i][j];
        printf("%d ",change_buffer[i*n+j]); // 2D를 1D로 변환완료.
	}
        printf("\n");
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
            printf("%.1f", result[i*n + j]); // fraction 1자리
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

void  DCT_stdout(unsigned char buffer[ROWS][COLS]){


#ifdef DCT_1d
	
	float result[ROWS*COLS];
        DCT1d(buffer, result);

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

	printf("complete 'DCT_rdata_file'\n");



}


