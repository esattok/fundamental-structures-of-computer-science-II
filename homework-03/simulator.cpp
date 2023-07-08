/*
* Title: Heaps
* Author: Esad Ýsmail Tök
* ID: 21801679
* Section: 2
* Assignment: 3
* Description: Implementation (.cpp) file of the simulator in which the simulation is done
*/

#include <iostream>
#include <string>
#include "simulator.h"
using namespace std;

// Default Constructor
Simulator::Simulator() {
	fileName = "";
	avgWaitingTime = 0;
	numOfRequests = 0;
}

// Constructor
Simulator::Simulator(string name, double time) {
	fileName = name;
	avgWaitingTime = time;

	// Declare variables for the file handling
	string strId, strPriority, strRequestTime, strProcessTime, strNumOfRequests;
	int id, priority, requestTime, processTime;
	int count = 0;
	int index = 0;

	ifstream inputFile;

	// Open the stream
	inputFile.open(fileName.c_str(), ios_base::in);

	// Reading the data
	while (inputFile.eof() == false) {
		if (count == 0) {
			getline(inputFile, strNumOfRequests, '\n');

			// Convert the string to integer
			stringstream convert1(strNumOfRequests);
			convert1 >> numOfRequests;

			// Allocate the dynamic memory to store the file
			requestList = new Request[numOfRequests];
		}

		else {
			getline(inputFile, strId, ' ');
			getline(inputFile, strPriority, ' ');
			getline(inputFile, strRequestTime, ' ');
			getline(inputFile, strProcessTime, '\n');

			// Converting the strings to integers
			stringstream convert2(strId);
			stringstream convert3(strPriority);
			stringstream convert4(strRequestTime);
			stringstream convert5(strProcessTime);

			convert2 >> id;
			convert3 >> priority;
			convert4 >> requestTime;
			convert5 >> processTime;

			// Create the request object
			Request newRequest(id, priority, requestTime, processTime, 0);

			// Insert this request into the allocated dynamic memory
			requestList[index] = newRequest;
			index++;
		}

		count++;
	}

	// Closing the input file
	inputFile.close();


	// -----Handling the Simulation-----
	int printerCount = 1; // Number of printers needed is initially 1
	double requiredTime; // Time that takes to do all requests with a specific number of printers
	bool resultFound = false; // The flag that indicates whether the min number of printers is found or not

	// At the end of this loop the printerCount will hold the number of needed printers
	while (true) {
		requiredTime = simulation(printerCount, resultFound);

		if (requiredTime <= avgWaitingTime) {
			resultFound = true;
			break;
		}

		else {
			printerCount++;
		}
	}

	
	// After the min number of printers is found, first print the min number of printers
	// Then call the simulation with only the resulting number of printers to display the simulation
	cout << "Minimum number of printers required: " << printerCount << endl << endl;
	cout << "Simulation with " << printerCount << " printers: " << endl << endl;

	simulation(printerCount, resultFound);
	
}

// Destructor
Simulator::~Simulator() {
	delete [] requestList;
}


// Accessors
string Simulator::getFileName() const {
	return fileName;
}

double Simulator::getAvgWaitingTime() const {
	return avgWaitingTime;
}

int Simulator::getNumOfRequests() const {
	return numOfRequests;
}


// Mutators
void Simulator::setFileName(string name) {
	fileName = name;
}

void Simulator::setAvgWaitingTime(double time) {
	avgWaitingTime = time;
}

void Simulator::setNumOfRequests(int num) {
	numOfRequests = num;
}


// Function that takes the number of printers and returns the average wating time calculated with those printers
double Simulator::simulation(int printerCount, bool resultFound) {
	// Create the array of printers
	Printer* printerList = new Printer[printerCount];

	// Initiate the properties of each printer
	for (int i = 0; i < printerCount; i++) {
		printerList[i].setIsAvailable(true);
		printerList[i].setExecutionTime(0);
	}

	int timer = 1;
	int cursor = 0;
	double totalWaitTime = 0; // Summation of all the wait times
	double averageWaitTime = 0; // Average of the wait times
	bool isAllPrintersAvailable;

	while (true) {
		// If the request time of a request is equal to the current timer then insert this request to the priority queue
		while ((cursor < numOfRequests) && requestList[cursor].getRequestTime() == timer) {
			priorityQueue.insert(requestList[cursor]);
			cursor++;
		}

		isAllPrintersAvailable = true; // At the beggining of each loop set flag to true

		for (int i = 0; i < printerCount; i++) {
			if (printerList[i].getIsAvailable()) {
				// If there is no more item in the priority queue then do not do anyting
				if (!(priorityQueue.isEmpty())) {
					// Delete the taken request from the priority queue and hold it in a temp request variable
					Request temp;
					priorityQueue.remove(temp);

					// Add the wait time of the removed item to the total wait time
					totalWaitTime = totalWaitTime + temp.getWaitTime();

					// Put this request into the available printer and make it unavailable then set the execution time to 1 initially
					printerList[i].setRequestInside(temp);
					printerList[i].setIsAvailable(false);
					printerList[i].setExecutionTime(1);

					// Print if the simulation is called for displaying
					if (resultFound) {
						cout << "Printer " << i << " prints print request " << printerList[i].getRequestInside().getId() <<
							" at minute " << timer << " (wait: " << printerList[i].getRequestInside().getWaitTime() << " mins)" << endl;
					}
				}
			}

			// If the printer is not available then update the time that it holds the request inside
			else {
				int currentExeTime = printerList[i].getExecutionTime();
				printerList[i].setExecutionTime(currentExeTime + 1);
			}
		}

		// If a printer in the list finishes the process inside then make it available and set its execution time to 0
		for (int i = 0; i < printerCount; i++) {
			if (printerList[i].getExecutionTime() == printerList[i].getRequestInside().getProcessTime()) {
				printerList[i].setIsAvailable(true);
				printerList[i].setExecutionTime(0);
			}
		}

		// Increase the wait time of all items in the priority queue
		priorityQueue.traverseForWait();

		// Increment the timer by one
		timer++;

		// Check whether all the printers are available or not
		for (int i = 0; i < printerCount; i++) {
			if (!(printerList[i].getIsAvailable())) {
				isAllPrintersAvailable = false;
			}
		}

		// If there is no more request to insert into priority queue AND if the priority queue is empty and if all the printers are empty then exit the loop
		if ((cursor == numOfRequests) && priorityQueue.isEmpty() && isAllPrintersAvailable) {
			break;
		}
	}

	// Deallocate the memory of the printers
	delete [] printerList;
	
	// Calculating and returning the average wait time
	averageWaitTime = (totalWaitTime / numOfRequests);

	// Print if the simulation is called for displaying
	if (resultFound) {
		cout << "\nAverage waiting time: " << averageWaitTime << " minutes" << endl;
	}

	return averageWaitTime;
}

