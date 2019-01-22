# File: 	makefile
# Author: 	Sandro Aguilar
# Date: 	February 2019
# Description:	Makefile for Project 2 Zoo Tycoon

# Variables to control Makefile operation

CXX = g++

CXXFLAGS = -Wall
CXXFLAGS += -g
CXXFLAGS += -std=c++0x

OBJECTS = main.o
OBJECTS += zoo.o
OBJECTS += menu.o
OBJECTS += animal.o
OBJECTS += tiger.o
OBJECTS += penguin.o
OBJECTS += turtle.o


HPPs = zoo.hpp
HPPs += menu.hpp
HPPs += animal.hpp
HPPs += tiger.hpp
HPPs += penguin.hpp
HPPs += turtle.hpp


CPPs = main.cpp
CPPs += zoo.cpp
CPPs += menu.hpp
CPPs += animal.hpp
CPPs += tiger.hpp
CPPs += penguin.hpp
CPPs += turtle.hpp


# Targets needed to bring the executable up to date
Zoo: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o Zoo $(OBJECTS)

main.o: main.cpp $(HPPs)
	$(CXX) $(CXXFLAGS) -c main.cpp

zoo.o: zoo.cpp

menu.o: menu.hpp

animal.o: animal.hpp

tiger.o: tiger.hpp

penguin.o: penguin.hpp

Turtle.o: turtle.hpp


# Clean-up operations
clean:
	rm Zoo *.o

debug:
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes ./Zoo

zip:
	zip -D Project2_Aguilar_Sandro.zip $(CPPs) $(HPPs) $(TXTS) makefile *.txt *.pdf
