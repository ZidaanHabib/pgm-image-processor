CC=g++
INCLUDES=-Iinclude
CCFLAGS=-std=c++2a 
SRCDIR=src/
BINDIR=bin/
OBJDIR=obj/
OUTDIR=output/
TESTDIR=tests/

SRC_FILES = $(wildcard $(SRCDIR)*.cpp)
OBJECTS = $(patsubst $(SRCDIR)%.cpp,$(OBJDIR)%.o,$(SRC_FILES))
TARGET=$(BINDIR)driver

.PHONY: clean


$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	$(CC) $(CCFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	rm $(OBJECTS) ; rm  $(TARGET); rm -r $(OUTDIR)*
run:
	$(TARGET) -t 200 -w test.pgm images/chess.pgm	
boundary:
	$(TARGET) -t 200 -b test_boundary.pgm images/chess.pgm
print:
	$(TARGET) -t 200 -p images/chess.pgm
coloured: 
	$(TARGET) -t 200 -c test_coloured.pgm images/chess.pgm

