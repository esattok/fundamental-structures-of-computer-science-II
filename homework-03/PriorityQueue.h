/*
* Title: Heaps
* Author: Esad Ýsmail Tök
* ID: 21801679
* Section: 2
* Assignment: 3
* Description: Header (.h) file of the PriorityQueue class which is a heap based ADT to be used
*/

#ifndef __PRIORITYQUEUE_H
#define __PRIORITYQUEUE_H

#include <iostream>
#include <string>
#include "Request.h"
#include "Heap.h"
using namespace std;

typedef HeapItem QueueItem;

class PriorityQueue {
public:
	PriorityQueue(); // Default and empty constructor

	// No destructor since there is no dynamic memory allocation

	bool isEmpty() const;
	bool insert(const QueueItem& item);
	bool getItem(QueueItem& item) const;
	bool remove(QueueItem& item);
	void traverseForWait();

private:
	Heap h;
};

#endif