CC=gcc
CFLAGS = -Wall -Wextra -Werror

TARGET = AddressBook

all: $(TARGET)

$(TARGET) : main.o singleList.o ui.o
			$(CC) $(CFLAGS) -o $@ $^
			@echo "\n Address Book Program On\n"
					 
run:$(TARGET)
	./$(TARGET)

main.o: main.c singleList.h ui.h
	$(CC) $(CFLAGS) -c -o $@ $<

sinlgleList.o: singleList.c singleList.h
	$(CC) $(CFLAGS) -c -o $@ $<

ui.o: ui.c ui.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) *.gch *.exe *.o

.PHONY: all clean
