CC=gcc
CFLAGS=-I.

test: main.o
	$(CC) -o test main.o

main.o: main.c
	$(CC) -c main.c

clean:
	rm test main.o
