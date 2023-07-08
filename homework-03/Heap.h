/*
* Title: Heaps
* Author: Esad Ýsmail Tök
* ID: 21801679
* Section: 2
* Assignment: 3
* Description: Header (.h) file of the Heap class which is used to hold the requests
*/

#ifndef __HEAP_H
#define __HEAP_H

#include <iostream>
#include <string>
#include "Request.h"
using namespace std;

typedef Request HeapItem;

class Heap {
public:
	Heap(); // Constructor
	Heap(const Heap& right); // Copy Constructor
	~Heap(); // Destructor

	bool isEmpty() const; // Check whether the heap is empty or not
	bool insert(const HeapItem& item); // Inserts a new item into the heap
	bool getItem(HeapItem& item) const; // Gets the root item
	bool remove(HeapItem& item); // Gets the root item and removes it 
	void traverseHeapForWait(); // Traverses the heap and does operations

protected:
	void rebuild(int rootIndex); // Preserves the heap property
	void expandSize(); // Doubles the size when needed

private:
	int size;
	int currentSize;
	HeapItem* items;
};

#endif