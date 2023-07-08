/*
* Title: Heaps
* Author: Esad Ýsmail Tök
* ID: 21801679
* Section: 2
* Assignment: 3
* Description: Driver (.cpp) file of the Homework 3
*/

#include <iostream>
#include <string>
#include <sstream>
#include "simulator.h"
using namespace std;

// Main function is only used to save the command line arguments and to pass those arguments to the simulator object
int main(int argc, char* argv[]) {

	// Saving the command line arguments
	string fileName = argv[1]; // First argument is the filename
	string strAvgWaitingTime = argv[2]; // Second argument is the waiting time but in a string format
	double avgWaitingTime;

	// Converting string into double
	stringstream convert(strAvgWaitingTime);
	convert >> avgWaitingTime;

	// The simulation is done in the simulator object
	Simulator sim(fileName, avgWaitingTime);

	return 0;
}