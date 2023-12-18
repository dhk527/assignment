CC = gcc
DEFINE =-DN=16
CFLAGS = -Wall -Wextra -Werror $(DEFINE)
LDFLAG = -lm

#define exe file
TARGET = RUN_DCT_Rdata 
TARGET1 = RUN_T_DCT_Rdata

#random16*16 bin file
BINARY_FILE1 = rdata.bin
BINARY_FILE2 = DCT_rdata.bin

#'all' doesen't need in simple code, but when many targeting function exits it'd better to use.

all : $(TARGET) $(TARGET1) 

$(TARGET) : main.o rdata.o DCT.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAG) 
	@echo "\nMake complete and 'make run'\nIf you want to see bin.file 'make hexadump'"

$(TARGET1) : main1.o rdata.o T_DCT.o
	$(CC) $(CFLAGS) -o $@ $^ -lm
	@echo "\nMake complete and 'make run1'\nIf you want to see bin.file 'make hexadump'"


run : $(TARGET)
	./$(TARGET)

run1 : $(TARGET1)
	./$(TARGET1)


main.o: main.c rdata.h DCT.h
	$(CC) $(CFLAGS) -Ddef_DCT -c -o $@ $<

main1.o: main.c rdata.h T_DCT.h
	$(CC) $(CFLAGS) -Ddef_T_DCT -c -o $@ $<

rdata.o:rdata.c rdata.h 
	$(CC) $(CFLAGS) -c -o $@ $<

DCT.o: DCT.c DCT.h
	$(CC) $(CFLAGS) -c -o $@ $< 

T_DCT.o: T_DCT.c T_DCT.h
	$(CC) $(CFLAGS) -c -o $@ $< 

hexadump : rdata.bin DCT_rdata.bin   
	xxd $(BINARY_FILE1)
	@echo "\nRdata transfoms DCT_Rdata\n"  
	@xxd DCT_rdata.bin   

clean: 
	rm -f $(TARGET) $(TARGET1) $(BINARY_FILE) *.gch *.exe *.bin *.o

#blocking duplication
.PHONY: all clean hexadump

