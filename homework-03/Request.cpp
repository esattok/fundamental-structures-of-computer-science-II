/*
* Title: Heaps
* Author: Esad Ýsmail Tök
* ID: 21801679
* Section: 2
* Assignment: 3
* Description: Implementation (.cpp) file of the Request class which represents a request in a log file
*/

#include <iostream>
#include <string>
#include "Request.h"
using namespace std;

Request::Request() {
	id = 0;
	priority = 0;
	requestTime = 0;
	processTime = 0;
	waitTime = 0;
}

Request::Request(const int reqId, const int reqPriority, const int reqRequestTime, const int reqProcessTime, const int reqWaitTime) {
	id = reqId;
	priority = reqPriority;
	requestTime = reqRequestTime;
	processTime = reqProcessTime;
	waitTime = reqWaitTime;
}

// Accessors
int Request::getId() const {
	return id;
}

int Request::getPriority() const {
	return priority;
}

int Request::getRequestTime() const {
	return requestTime;
}

int Request::getProcessTime() const {
	return processTime;
}

int Request::getWaitTime() const {
	return waitTime;
}


// Mutators
void Request::setId(const int newId) {
	id = newId;
}

void Request::setPriority(const int newPriority) {
	priority = newPriority;
}

void Request::setRequestTime(const int newRequestTime) {
	requestTime = newRequestTime;
}

void Request::setProcessTime(const int newProcessTime) {
	processTime = newProcessTime;
}

void Request::setWaitTime(const int newWaitTime) {
	waitTime = newWaitTime;
}