CXX=g++
CFLAGS = -Wall -Wextra -Werror

TARGET = Calculator 

all: $(TARGET)

$(TARGET) : main.o cal.o ui.o
			$(CXX) $(CFLAGS) -o $@ $^
			@echo "\n CXXalculator Book Program On\n"
					 
run:$(TARGET)
	./$(TARGET)

main.o: main.cpp cal.h ui.h
	$(CXX) $(CFLAGS) -c -o $@ $<

cal.o: cal.cpp cal.h
	$(CXX) $(CFLAGS) -c -o $@ $<

ui.o: ui.cpp ui.h
	$(CXX) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) *.gch *.exe *.o

.PHONY: all clean
