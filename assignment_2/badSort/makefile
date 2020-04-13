CC = gcc
CFLAGS = -g -Wall -std=c99

all: badSort

badSort: main.o badSort.o
	$(CC) $(CFLAGS) -o $@ $^ -lm

main.o: main.c badSort.h

badSort.o: badSort.c badSort.h

memCheck :
	valgrind --tool=memcheck --leak-check=yes main

clean:
	rm *.o
	rm badSort 
