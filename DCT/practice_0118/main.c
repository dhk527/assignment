#include <stdio.h>
#include "rdata.h"
#include "DCT.h"


unsigned char buffer[ROWS][COLS]={0};
int makeRdatafile();



int main() {
//call function of making random data
	makeRdatafile();
	
	FILE* input_rdata;
	input_rdata=fopen("rdata.bin","rb");
	if(input_rdata != NULL){
		fread(buffer, sizeof(unsigned char), ROWS*COLS, input_rdata);
		fclose(input_rdata);
	}else{
		perror("fail to read input_file");
		return 1;
	}
// Random data will transforms DCT_data.
		DCT_stdout(buffer);
	






	return 0;
}
