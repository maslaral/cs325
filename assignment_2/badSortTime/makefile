CC = gcc
CFLAGS = -g -Wall -std=c99

all: badSortTime

badSortTime: main.o badSortTime.o
	$(CC) $(CFLAGS) -o $@ $^ -lm

main.o: main.c badSortTime.h

badSortTime.o: badSortTime.c badSortTime.h

memCheck :
	valgrind --tool=memcheck --leak-check=yes main

clean:
	rm *.o
	rm badSortTime 
