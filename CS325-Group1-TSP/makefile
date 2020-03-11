# CS325 TSP Project Group 29  
# 11/26/2017

PROJ = TSP 
SRC = main file_handler tsp  

CXX = g++
CXXFLAGS = -std=c++11 
CXXFLAGS += -Wall -g
CXXFLAGS += -pedantic-errors
CPP = $(SRC:=.cpp)
OBJ = $(SRC:=.o)

all:
	$(CXX) $(CXXFLAGS) $(CPP) -o $(PROJ)

clean:
	rm $(OBJ)
