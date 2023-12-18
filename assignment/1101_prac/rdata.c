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
    unsigned char data[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            data[i][j] = rand() % 256;
        }
    }

    FILE *file = fopen("rdata.bin", "wb");
    if (file == NULL) {
        perror("fopen error");
        return 1;
    }

    fwrite(data, sizeof(unsigned char), N * N, file);
    fclose(file);
    printf("complete 'rdata.bin' \n");

    return 0;
}

