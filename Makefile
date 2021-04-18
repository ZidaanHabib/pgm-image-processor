CC=g++
INCLUDES=-Iinclude
CCFLAGS=-std=c++2a 
SRCDIR=src/
BINDIR=bin/
OBJDIR=obj/
OUTDIR=output/

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
