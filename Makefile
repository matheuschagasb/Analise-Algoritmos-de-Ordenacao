# Makefile simples
CC = gcc
TARGET = sort

all: $(TARGET)

$(TARGET): src/main.c src/sorting_algorithms.c src/utils.c 
	$(CC) $(CFLAGS) -o $(TARGET) src/main.c src/sorting_algorithms.c src/utils.c

clean:
	rm -f $(TARGET) *.exe

run: $(TARGET)
	.\$(TARGET)

.PHONY: all clean run
