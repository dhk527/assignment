#include <stdio.h>
#include "rdata.h"

unsigned char buffer[N][N]={0};
int makeRdatafile();

#ifdef def_DCT
#include "DCT.h"
#endif

#ifdef def_T_DCT
#include "T_DCT.h"
void calculate2DDCT(unsigned char input[N][N], float output[N][N]);
void inv2DDCT(float input[N][N],float output[N][N],float Trnaspose[N][N]);
float T[N][N];
#endif

int main(){ 
//call function of making random data
	makeRdatafile();
	
	FILE* input_rdata;
	input_rdata=fopen("rdata.bin","rb");
	if(input_rdata != NULL){
		fread(buffer, sizeof(unsigned char), N*N, input_rdata);
		fclose(input_rdata);
	}else{
		perror("fail to read input_file");
		return 1;
	}

// Random data,'rdata.bin', transforms DCT_data.

       float  result[N][N];
        int u, v;
	
#ifdef def_DCT
        DCT(buffer, result); // call DCT_rdata
	printf("\ncomplete DCT transfomation\n");
#endif
     
#ifdef def_T_DCT  
	calculate2DDCT(buffer, result);
	printf("\n\ncomplete!! T_ DCT transfomation\n\n");

//	test(result, );
//	printf("\ntest inverse T_DCT", test);
#endif


        for(u = 0 ; u < N ; u++){
                for(v = 0 ; v< N ; v++){
				printf( "%0.2f ", result[u][v]);
                                        }
			printf("\n");
                        }
	
#ifdef def_T_DCT
printf("\n=======test DCT=========================================\n");
	float output[N][N];
	inv2DDCT(result,output,T);

  for(u = 0 ; u < N ; u++){
                for(v = 0 ; v< N ; v++){
                                printf( "%0.2f ", output[u][v]);
                                        }
                        printf("\n");
                        }


#endif

// dumping to hex from DCT_rdata    
        FILE* DCT_rdata_file;

        DCT_rdata_file = fopen("DCT_rdata.bin","wb");

        if(DCT_rdata_file == NULL){
                perror("fopen error");
                                }

        fwrite(result, sizeof(char), N*N, DCT_rdata_file);
        fclose(DCT_rdata_file);

        printf("complete 'DCT_rdata_file'\n");
    
	
		
        return 0;
}
