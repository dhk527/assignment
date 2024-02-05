CC=g++
CFLAGS = -Wall -Wextra -Werror

TARGET = Calculator 

all: $(TARGET)

$(TARGET) : main.o cal.o ui.o
			$(CC) $(CFLAGS) -o $@ $^
			@echo "\n CCalculator Book Program On\n"
					 
run:$(TARGET)
	./$(TARGET)

main.o: main.cpp cal.h ui.h
	$(CC) $(CFLAGS) -c -o $@ $<

cal.o: cal.cpp cal.h
	$(CC) $(CFLAGS) -c -o $@ $<

ui.o: ui.cpp ui.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) *.gch *.exe *.o

.PHONY: all clean
