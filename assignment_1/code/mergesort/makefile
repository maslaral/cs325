CC = gcc
CFLAGS = -g -Wall -std=c99

all: mergesort 

mergesort: main.o mergesort.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c mergesort.h

mergesort.o: mergesort.c mergesort.h

memCheck :
	valgrind --tool=memcheck --leak-check=yes main

clean:
	rm *.o
	rm mergesort 