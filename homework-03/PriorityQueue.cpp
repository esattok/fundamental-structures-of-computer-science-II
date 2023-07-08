/*
* Title: Heaps
* Author: Esad Ýsmail Tök
* ID: 21801679
* Section: 2
* Assignment: 3
* Description: Implementation (.cpp) file of the PriorityQueue class which is a heap based ADT to be used
*/

#include "PriorityQueue.h"
using namespace std;

PriorityQueue::PriorityQueue() {}

bool PriorityQueue::isEmpty() const {
	return h.isEmpty();
}

bool PriorityQueue::insert(const QueueItem& item) {
	return h.insert(item);
}

bool PriorityQueue::getItem(QueueItem& item) const {
	return h.getItem(item);
}

bool PriorityQueue::remove(QueueItem& item) {
	return h.remove(item);
}

void PriorityQueue::traverseForWait() {
	h.traverseHeapForWait();
}
