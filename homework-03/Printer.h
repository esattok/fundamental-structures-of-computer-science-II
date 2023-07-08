/*
* Title: Heaps
* Author: Esad Ýsmail Tök
* ID: 21801679
* Section: 2
* Assignment: 3
* Description: Header (.h) file of the Printer class which represents a printer that can handle a single request each time
*/

#ifndef __PRINTER_H
#define __PRINTER_H

#include <iostream>
#include <string>
#include "Request.h"
using namespace std;

class Printer {
public:
	Printer(); // Default Constructor
	Printer(int exeTime, bool available, Request req); // Constructor

	// No destructor since there is no dynamic memory allocation

	// Accessor Functions
	int getExecutionTime() const;
	bool getIsAvailable() const;
	Request getRequestInside() const;

	// Mutator Functions
	void setExecutionTime(const int time);
	void setIsAvailable(const bool available);
	void setRequestInside(Request newRequest);

private:
	int executionTime;
	bool isAvailable;
	Request request;
};

#endif