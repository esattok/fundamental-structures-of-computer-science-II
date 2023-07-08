/*
* Title: Heaps
* Author: Esad Ýsmail Tök
* ID: 21801679
* Section: 2
* Assignment: 3
* Description: Header (.h) file of the Request class which represents a request in a log file
*/

#ifndef __REQUEST_H
#define __REQUEST_H

#include <iostream>
#include <string>
using namespace std;

class Request {
public:
	// Constructors
	Request();
	Request(const int reqId, const int reqPriority, const int reqRequestTime, const int reqProcessTime, const int reqWaitTime);

	// No destructor since there is no dynamic memory allocation

	// Accessor Functions
	int getId() const;
	int getPriority() const;
	int getRequestTime() const;
	int getProcessTime() const;
	int getWaitTime() const;

	// Mutator Functions
	void setId(const int newId);
	void setPriority(const int newPriority);
	void setRequestTime(const int newRequestTime);
	void setProcessTime(const int newProcessTime);
	void setWaitTime(const int newWaitTime);

private:
	int id;
	int priority;
	int requestTime;
	int processTime;
	int waitTime;
};

#endif