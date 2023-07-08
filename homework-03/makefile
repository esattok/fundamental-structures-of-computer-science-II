# Title: Heaps
# Author: Esad İsmail Tök
# ID: 21801679
# Section: 2
# Assignment: 3
# Description: Makefile to compile and generate an executable for the hw3

simulator: main.o Printer.o Request.o Heap.o PriorityQueue.o simulator.o
	g++ main.o Printer.o Request.o Heap.o PriorityQueue.o simulator.o -o simulator

main.o: main.cpp
	g++ -c main.cpp

Printer.o: Printer.cpp Printer.h
	g++ -c Printer.cpp

Request.o: Request.cpp Request.h
	g++ -c Request.cpp

Heap.o: Heap.cpp Heap.h
	g++ -c Heap.cpp

PriorityQueue.o: PriorityQueue.cpp PriorityQueue.h
	g++ -c PriorityQueue.cpp

simulator.o: simulator.cpp simulator.h
	g++ -c simulator.cpp


# Cleans the object files and executable
clean:
	rm *.o simulator
