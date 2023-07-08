# Title: Sorting and Algorithm Efficiency
# Author: Esad İsmail Tök
# ID: 21801679
# Section: 2
# Assignment: 1
# Description: Makefile to compile and generate an executable for the Selection, Merge, Quick, and Radix sort algorithms and their helper functions

hw1: main.o sorting.o
	g++ main.o sorting.o -o hw1

main.o: main.cpp
	g++ -c main.cpp

sorting.o: sorting.cpp sorting.h
	g++ -c sorting.cpp


# Cleans the object files and the executable
clean:
	rm *.o hw1

