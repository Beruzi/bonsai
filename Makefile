
# Project Variables
SRC = src
TARGET = bonsai

# Compiler
CXX := g++
CXXFLAGS := -O0 -g -Wall -Wextra -Wpedantic
LDLIBS := -lncurses
SOURCES := $(shell find $(SRC) -type f -name '*.cpp')


all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(SOURCES) $(CXXFLAGS) $(LDLIBS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

