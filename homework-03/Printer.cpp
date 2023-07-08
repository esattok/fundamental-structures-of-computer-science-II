/*
* Title: Heaps
* Author: Esad Ýsmail Tök
* ID: 21801679
* Section: 2
* Assignment: 3
* Description: Implementation (.cpp) file of the Printer class which represents a printer that can handle a single request each time
*/

#include <iostream>
#include <string>
#include "Printer.h"
#include "Request.h"
using namespace std;

Printer::Printer() {} // Default Constructor

// Constructor
Printer::Printer(int exeTime, bool available, Request req) {
	executionTime = exeTime;
	isAvailable = available;
	request = req;
}


// Accessors
int Printer::getExecutionTime() const {
	return executionTime;
}

bool Printer::getIsAvailable() const {
	return isAvailable;
}

Request Printer::getRequestInside() const {
	return request;
}


// Mutators
void Printer::setExecutionTime(const int time) {
	executionTime = time;
}

void Printer::setIsAvailable(const bool available) {
	isAvailable = available;
}

void Printer::setRequestInside(Request newRequest) {
	request = newRequest;
}
