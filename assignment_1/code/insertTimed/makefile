CC = gcc
CFLAGS = -g -Wall -std=c99

all: insertTimed 

insertTimed: main.o insertTimed.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c insertTimed.h

insertsort.o: insertTimed.c insertTimed.h

memCheck :
	valgrind --tool=memcheck --leak-check=yes main

clean:
	rm *.o
	rm insertTimed