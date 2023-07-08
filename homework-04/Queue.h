/*
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Esad Ýsmail Tök
* ID: 21801679
* Section : 2
* Assignment : 4
* Description : Header (.h) file of the Queue class that is used for BST in Word Network
*/

#ifndef __QUEUE_H
#define __QUEUE_H

#include <iostream>
#include <string>
using namespace std;

typedef int ItemType;

class Queue {
public:
	Queue(); // Default constructor
	Queue(const Queue&); // Copy constructor
	~Queue(); // Destructor

	bool isEmpty() const;
	bool enqueue(const ItemType&);
	bool dequeue();
	bool dequeue(ItemType&);
	bool getFront(ItemType&) const;

private:
	struct QueueNode {
		ItemType data;
		QueueNode* next;
	};

	QueueNode* frontPtr; // Points to the front of the list
	QueueNode* backPtr; // Points to the end of the list
};

#endif