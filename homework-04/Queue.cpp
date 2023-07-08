/*
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Esad Ýsmail Tök
* ID: 21801679
* Section : 2
* Assignment : 4
* Description : Implementation (.cpp) file of the Queue class that is used for BST in Word Network
*/

#include <iostream>
#include <string>
#include "Queue.h"
using namespace std;

Queue::Queue() {
	frontPtr = NULL;
	backPtr = NULL;
}

Queue::Queue(const Queue& right) {
	// If the queue is empty
	if (right.isEmpty()) {
		frontPtr = NULL;
		backPtr = NULL;
	}

	else {
		frontPtr = new QueueNode;
		frontPtr->data = right.frontPtr->data;

		QueueNode* newPtr = frontPtr;
		for (QueueNode* origPtr = right.frontPtr->next; origPtr != NULL; origPtr = origPtr->next) {
			newPtr->next = new QueueNode;
			newPtr = newPtr->next;
			newPtr->data = origPtr->data;
		}

		newPtr->next = NULL;
		backPtr = newPtr;
	}
}

Queue::~Queue() {
	while (!isEmpty()) {
		dequeue();
	}
}

bool Queue::isEmpty() const {
	if (this->backPtr == NULL) {
		return true;
	}

	else {
		return false;
	}
}

bool Queue::enqueue(const ItemType& item) {
	// Flling the new node
	QueueNode* newPtr = new QueueNode;
	newPtr->next = NULL;
	newPtr->data = item;

	// Adding the new node to the queue
	if (isEmpty()) {
		frontPtr = newPtr;
		backPtr = newPtr;
	}

	else {
		backPtr->next = newPtr;
		backPtr = newPtr;
	}

	return true;
}

bool Queue::dequeue() {
	if (isEmpty()) {
		return false;
	}

	else {
		QueueNode* temp = frontPtr;

		if (frontPtr == backPtr) {
			frontPtr = NULL;
			backPtr = NULL;
		}

		else {
			frontPtr = frontPtr->next;
		}

		temp->next = NULL;
		delete temp;
		temp = NULL;

		return true;
	}
}

bool Queue::dequeue(ItemType& item) {
	if (isEmpty()) {
		return false;
	}

	else {
		QueueNode* temp = frontPtr;

		if (frontPtr == backPtr) {
			frontPtr = NULL;
			backPtr = NULL;
		}

		else {
			frontPtr = frontPtr->next;
		}

		item = temp->data;

		temp->next = NULL;
		delete temp;
		temp = NULL;

		return true;
	}
}

bool Queue::getFront(ItemType& item) const {
	if (isEmpty()) {
		return false;
	}

	else {
		item = frontPtr->data;

		return true;
	}
}
