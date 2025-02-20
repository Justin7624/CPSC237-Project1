# Makefile for Project 1

CXX = g++
CXXFLAGS = -std=c++11 -Wall
SRC_FILES = main.cpp WordData.cpp
HEADER_FILES = WordData.h
OBJ_FILES = $(SRC_FILES:.cpp=.o)

# Default target: build the executable named p1
p1: $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ_FILES)

# Compile source files
main.o: main.cpp $(HEADER_FILES)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

WordData.o: WordData.cpp $(HEADER_FILES)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean the generated files
clean:
	rm -f p1 $(OBJ_FILES)