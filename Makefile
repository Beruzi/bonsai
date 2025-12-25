
# Project Variables
SRC = src
TARGET = bonsai

# Compiler
CXX := g++
CXXFLAGS := -O0 -g -Wall -Wextra -Wpedantic
LDLIBS := -lncurses


all: $(TARGET)

$(TARGET):
	$(CXX) $(wildcard $(SRC)/*.cpp) $(CXXFLAGS) $(LDLIBS) -o $(TARGET)
	./$(TARGET)

