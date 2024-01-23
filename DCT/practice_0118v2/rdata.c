#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rdata.h"

int makeRdatafile() {
    // set time for dynaic seed
    unsigned int seed = (unsigned int)time(NULL);

    // set seed
    srand(seed);

    // 0~255 2^8 unsigned char byte = 8bit 	
    unsigned char data[ROWS][COLS];
    printf("\n[[");

    for (int i = 0; i < ROWS; i++) {
	for (int j = 0; j < COLS; j++) {
	    data[i][j] = rand() % 256;

	    if(j != 15)
	    {
		printf("%d, ", data[i][j]);
	    }
	    else
	    { if(i!=15)
		printf("%d],",data[i][j]);
		else
		    printf("%d]]",data[i][j]);
	    }
	}
	if(i !=15)
	    printf("\n[");
    }
    //print stdout rdata(random data)

    FILE *file = fopen("rdata.bin", "wb");
    if (file == NULL) {

	perror("fopen error");
    }

    fwrite(data, sizeof(unsigned char), ROWS * COLS, file);
    fclose(file);
    printf("\ncomplete 'rdata.bin' \n");

    return 0;
}

