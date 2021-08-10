#Makefile for unit tests

CC=g++
INCLUDES=-I../include
CCFLAGS=-std=c++2a 

OBJDIR=../obj/
OBJECTS = program_test.o $(OBJDIR)PGMImageProcessor.o $(OBJDIR)ConnectedComponent.o
TARGET=./test

.PHONY: clean


$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

.cpp.o:
	$(CC) $(CCFLAGS) $(INCLUDES) -c -w $<

clean:
	rm *.o test
run:
	$(TARGET)	
