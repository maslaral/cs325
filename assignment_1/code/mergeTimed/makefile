CC = gcc
CFLAGS = -g -Wall -std=c99

all: mergeTimed 

mergeTimed: main.o mergeTimed.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c mergeTimed.h

mergeTimed.o: mergeTimed.c mergeTimed.h

memCheck :
	valgrind --tool=memcheck --leak-check=yes main

clean:
	rm *.o
	rm mergeTimed