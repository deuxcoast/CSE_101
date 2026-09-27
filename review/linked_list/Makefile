# Makefile for the List ADT
#   make           build ListTest
#   make run       build and run
#   make memcheck  run under valgrind to find leaks and bad memory access
#   make clean     remove build products

CC     = gcc
CFLAGS = -std=c17 -Wall -Wextra -g

ListTest: ListTest.o List.o
	$(CC) -o ListTest ListTest.o List.o

ListTest.o: ListTest.c List.h
	$(CC) $(CFLAGS) -c ListTest.c

List.o: List.c List.h
	$(CC) $(CFLAGS) -c List.c

run: ListTest
	./ListTest

memcheck: ListTest
	valgrind --leak-check=full ./ListTest

clean:
	rm -f ListTest *.o

.PHONY: run memcheck clean
