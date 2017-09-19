#Makefile for particle generators of the combined df - June 8/94 - JJD
#
#
CC=g++

CFLAGS = -std=c++11

all: clean Create_Galaxy_Treecode

Create_Galaxy_Treecode: *.cpp
	$(CC) $(CFLAGS) *.cpp *.h


clean:
	rm -f *.o *.gch

