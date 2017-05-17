# simple Makefile
CC := g++
SRCDIR := src
BUILDDIR := obj/Debug
BINDIR := bin/Release/
TARGET := $(BINDIR)/stackit.linux64

SRCEXT := cpp
SOURCES:= $(wildcard $(SRCDIR)/*.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%, $(BUILDDIR)/%, $(SOURCES:.$(SRCEXT)=.o))

CFLAGS := -Wall -std=c++11
LIB := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
INC := -I include

$(TARGET): main.cpp $(OBJECTS)
	@mkdir -p $(dir $@)
	@echo " Linking..."
	@echo " $(CC) $^ -g -o $(TARGET) $(LIB)"; $(CC)  $(INC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	@echo " $(CC) $(CFLAGS) $(INC) -g -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning...";
	@echo " $(RM) $(TARGET) $(BUILDDIR)/*"; $(RM) $(TARGET) $(BUILDDIR)/*

.PHONY: clean
