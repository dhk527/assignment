CC =gcc
CFLAGS = -Wall -Wextra -Werror 

TARGET = Euclid

all: $(TARGET)

$(TARGET) : main.o GCD.o ui.o
	$(CC) $(CFLAGS) -o $@ $^ 

run:$(TARGET)
	./$(TARGET)

main.o: main.c GCD.h ui.h
	$(CC) $(CFLAGS) -c -o $@ $<

GCD.o: GCD.c GCD.h
	$(CC) $(CFLAGS) -c -o $@ $<

ui.o : ui.c ui.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -f $(TARGET) *.gch *.exe *.o

.PHONY: all clean
