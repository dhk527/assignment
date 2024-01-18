CC = gcc
CFLAGS = -Wall -Wextra -Werror 

ifdef DCT_1d
CFLAGS +=-DDCT_1d
endif

ifdef malloc_DCT_1d
CFLAGS +=-Dmalloc_DCT_1d
endif



TARGET = RUN_DCT_Rdata2

#random16*16 bin file
BINARY_FILE1 = rdata.bin
BINARY_FILE2 = DCT_rdata.bin

#run rdata

all: $(TARGET) 

$(TARGET) : main.o rdata.o DCT.o
	$(CC) $(CFLAGS) -o $@ $^ -lm
	@echo  "\nMake complete and 'make run'\nIf you want to see bin.file 'make hexadump'"

run : $(TARGET)
	./$(TARGET)

main.o: main.c rdata.h DCT.h
	$(CC) $(CFLAGS) -c -o $@ $<

rdata.o:rdata.c rdata.h 
	$(CC) $(CFLAGS) -c -o $@ $<

DCT.o: DCT.c DCT.h
	$(CC) $(CFLAGS) -c -o $@ $< 

hexadump : rdata.bin DCT_rdata.bin   
	xxd $(BINARY_FILE1)
	@echo "\nRdata transfoms DCT_Rdata\n"  
	@xxd $(BINARY_FILE2)  

clean: 


	rm -f $(TARGET) $(BINARY_FILE) *.gch *.exe *.bin *.o

#blocking duplication
.PHONY: all clean hexadump

