/*
* Title: Heaps
* Author: Esad Ýsmail Tök
* ID: 21801679
* Section: 2
* Assignment: 3
* Description: Header (.h) file of the simulator in which the simulation is done
*/

#ifndef __SIMULATOR_H
#define __SIMULATOR_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Request.h"
#include "Printer.h"
#include "Heap.h"
#include "PriorityQueue.h"
using namespace std;

class Simulator {
public:
	// Constructors
	Simulator();
	Simulator(string name, double time);

	// Destructor
	~Simulator();

	// Accessor Functions
	string getFileName() const;
	double getAvgWaitingTime() const;
	int getNumOfRequests() const;

	// Mutator Functions
	void setFileName(string name);
	void setAvgWaitingTime(double time);
	void setNumOfRequests(int num);

	// Functions related with simulation
	double simulation(int printerCount, bool resultFount);

private:
	string fileName; // Name of the request log file
	double avgWaitingTime; // The waiting time limit
	int numOfRequests; // Total number of requests

	PriorityQueue priorityQueue; // It is used to store the requests that are  sent and waiting for a printer
	Request* requestList; // It is used for reading all the requests from the txt file and pass the appropriate ones to the priority queue
};

#endif