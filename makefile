CC=g++
CFLAGS=-std=c++11
all : PahlAssignment1

PahlAssignment1: PahlAssignment1.o
	$(CC) $(CFLAGS) PahlAssignment1.o -o PahlAssignment1

PahlAssignment1.o: PahlAssignment1.cpp
	$(CC) $(CFLAGS) -c PahlAssignment1.cpp
