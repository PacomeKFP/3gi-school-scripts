CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -std=c11 
INCLUDE=include
lib=lib/*.c
EXEC=bin/main


.PHONY: all clean

all: main launch

main: main.c
	$(CC) $(CFLAGS) -o $(EXEC) main.c $(lib) -I $(INCLUDE)

clean:
	rm -f bin/main

launch:
	valgrind --leak-check=full ./$(EXEC)

