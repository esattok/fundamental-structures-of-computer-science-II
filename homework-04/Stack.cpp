/*
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Esad Ýsmail Tök
* ID: 21801679
* Section : 2
* Assignment : 4
* Description : Header (.h) file of the Stack class that will be used fo DFT in the Word Network
*/

#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

Stack::Stack() {
	size = 10;
	items = new StackItemType[size];
	top = -1; // Stack is currently empty
}

Stack::Stack(const Stack& right) {
	size = right.size;
	items = new StackItemType[size];

	if (right.top == -1) {
		top = -1;
	}

	else {
		top = right.top;
		for (int i = 0; i <= right.top; i++) {
			items[i] = right.items[i];
		}
	}
}

Stack::~Stack() {
	delete[] items;
}

void Stack::expandSize() {
	StackItemType* temp = items;

	int newSize = (size * 2);
	items = new StackItemType[newSize];

	for (int i = 0; i <= top; i++) {
		items[i] = temp[i];
	}

	size = newSize;
	delete[] temp;
}

bool Stack::isEmpty() const {
	if (top < 0) {
		return true;
	}

	else {
		return false;
	}
}

bool Stack::push(const StackItemType& newItem) {
	if (top >= (size - 1)) {
		this->expandSize();
	}

	top++;
	items[top] = newItem;
	return true;
}

bool Stack::pop() {
	if (this->isEmpty()) {
		return false;
	}

	else {
		top--;
		return true;
	}
}

bool Stack::pop(StackItemType& value) {
	if (this->isEmpty()) {
		return false;
	}

	else {
		value = items[top];
		top--;
		return true;
	}
}

bool Stack::getTop(StackItemType& value) {
	if (this->isEmpty()) {
		return false;
	}

	else {
		value = items[top];
		return true;
	}
}
