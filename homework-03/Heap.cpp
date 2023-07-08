/*
* Title: Heaps
* Author: Esad Ýsmail Tök
* ID: 21801679
* Section: 2
* Assignment: 3
* Description: Implementation (.cpp) file of the Heap class which is used to hold the requests
*/

#include <iostream>
#include <string>
#include "Heap.h"
using namespace std;

Heap::Heap() {
	this->size = 10;
	this->currentSize = 0;
	items = new HeapItem[size];
}

Heap::Heap(const Heap& right) {
	this->size = right.size;
	this->currentSize = right.currentSize;
	items = new HeapItem[size];

	for (int i = 0; i < currentSize; i++) {
		items[i] = right.items[i];
	}
}

Heap::~Heap() {
	delete [] items;
}

bool Heap::isEmpty() const {
	return (currentSize == 0);
}

bool Heap::insert(const HeapItem& item) {
	if (currentSize >= size) {
		expandSize();
	}

	items[currentSize] = item;
	int dataIndex = currentSize;
	int parentIndex = (dataIndex - 1) / 2;

	while ((dataIndex > 0) && (items[dataIndex].getPriority() >= items[parentIndex].getPriority())) {

		if (items[dataIndex].getPriority() > items[parentIndex].getPriority()) {
			HeapItem temp = items[dataIndex];
			items[dataIndex] = items[parentIndex];
			items[parentIndex] = temp;
		}

		// If the priorities are equal then check the request time and if the request time of the child is smaller then swap 
		else if (items[dataIndex].getPriority() == items[parentIndex].getPriority()) {
			if (items[dataIndex].getRequestTime() < items[parentIndex].getRequestTime()) {
				HeapItem temp = items[dataIndex];
				items[dataIndex] = items[parentIndex];
				items[parentIndex] = temp;
			}

			// Else exit the loop
			else {
				break;
			}
		}
		

		dataIndex = parentIndex;
		parentIndex = (dataIndex - 1) / 2;
	}

	currentSize++;
	return true;
}

bool Heap::getItem(HeapItem& item) const {
	if (isEmpty()) {
		return false;
	}

	else {
		item = items[0];
		return true;
	}
}

bool Heap::remove(HeapItem& item) {
	if (isEmpty()) {
		return false;
	}

	else {
		item = items[0];
		items[0] = items[currentSize - 1];
		currentSize--;

		rebuild(0);

		return true;
	}
}

void Heap::traverseHeapForWait() {
	int curWaitTime;

	for (int i = 0; i < currentSize; i++) {
		curWaitTime = items[i].getWaitTime();
		curWaitTime++;

		items[i].setWaitTime(curWaitTime);
	}
}

void Heap::rebuild(int rootIndex) {
	int childIndex = (2 * rootIndex) + 1; // It cannot contain a right child without a left child

	// If there is no child return
	if (childIndex < currentSize) {

		// Finding the child that has the max value
		int rightChildIndex = childIndex + 1;

		if (rightChildIndex < currentSize) {
			if (items[rightChildIndex].getPriority() >= items[childIndex].getPriority()) {
				if (items[rightChildIndex].getPriority() > items[childIndex].getPriority()) {
					childIndex = rightChildIndex;
				}

				// If the Priorities are equal then the smallest request time will be the biggest child
				else if (items[rightChildIndex].getPriority() == items[childIndex].getPriority()) {
					if (items[rightChildIndex].getRequestTime() < items[childIndex].getRequestTime()) {
						childIndex = rightChildIndex;
					}
				}
				
			}
		}

		// If the child is bigger then its parent swap and call function again
		if (items[childIndex].getPriority() >= items[rootIndex].getPriority()) {

			if (items[childIndex].getPriority() > items[rootIndex].getPriority()) {
				HeapItem temp = items[childIndex];
				items[childIndex] = items[rootIndex];
				items[rootIndex] = temp;

				rebuild(childIndex); // Call the function again with the child
			}

			else if (items[childIndex].getPriority() == items[rootIndex].getPriority()) {
				if (items[childIndex].getRequestTime() < items[rootIndex].getRequestTime()) {
					HeapItem temp = items[childIndex];
					items[childIndex] = items[rootIndex];
					items[rootIndex] = temp;

					rebuild(childIndex); // Call the function again with the child
				}
			}
		}
	}
}

void Heap::expandSize() {
	size = size * 2;
	HeapItem* temp = items;

	items = new HeapItem[size];

	for (int i = 0; i < currentSize; i++) {
		items[i] = temp[i];
	}

	delete[] temp;
}
