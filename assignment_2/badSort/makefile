CC = gcc
CFLAGS = -g -Wall -std=c99

all: badSort

badSort: main.o badsort.o
	$(CC) $(CFLAGS) -o $@ $^ -lm

main.o: main.c badsort.h

insertsort.o: badsort.c badsort.h

memCheck :
	valgrind --tool=memcheck --leak-check=yes main

clean:
	rm *.o
	rm badSort 
