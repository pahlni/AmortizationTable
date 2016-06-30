CC=g++

all : AmorizationTable

AmorizationTable: AmorizationTable.o
	$(CC) AmorizationTable.o -o AmorizationTable

AmorizationTable.o: AmorizationTable.cpp
	$(CC) -c AmorizationTable.cpp
