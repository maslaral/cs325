CC = gcc
CFLAGS = -g -Wall -std=c99

all: insertsort 

insertsort: main.o insertsort.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c insertsort.h

insertsort.o: insertsort.c insertsort.h

memCheck :
	valgrind --tool=memcheck --leak-check=yes main

clean:
	rm *.o
	rm insertsort 