CC=g++
CFLAGS=-std=c++11
all : AmorizationTable

AmorizationTable: AmorizationTable.o
	$(CC) $(CFLAGS) AmorizationTable.o -o AmorizationTable

AmorizationTable.o: AmorizationTable.cpp
	$(CC) $(CFLAGS) -c AmorizationTable.cpp
