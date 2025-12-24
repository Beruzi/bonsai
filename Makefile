
# Project Variables
SRC = src
TARGET = bonsai
BUILD_DIR = bin
DATA_DIR = ~/.local/share/bonsai


# Compiler
CXX := g++
CXXFLAGS := -


dev: 
	g++ src/main.cpp -lncurses -O0 -g -o bonsai
	./bonsai


