#Makefile for particle generators of the combined df - June 8/94 - JJD
#
#
CC=g++

CFLAGS = -std=c++11

all: clean Create_Galaxy_N2

Create_Galaxy_N2: *.cpp
	$(CC) $(CFLAGS) *.cpp *.h


clean:
	rm -f *.o *.gch

