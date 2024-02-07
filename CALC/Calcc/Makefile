cc=gcc
CFLAGS = -Wall -Wextra -Werror

TARGET = Calculator 

all: $(TARGET)

$(TARGET) : main.o calc.o ui.o
			$(CC) $(CFLAGS) -o $@ $^
			@echo "\n Calculator Book Program On\n"
					 
run:$(TARGET)
	./$(TARGET)

main.o: main.c calc.h ui.h
	$(CC) $(CFLAGS) -c -o $@ $<

calc.o: calc.c calc.h
	$(CC) $(CFLAGS) -c -o $@ $<

ui.o: ui.c ui.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) *.gch *.exe *.o

.PHONY: all clean
