/*
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Esad Ýsmail Tök
* ID: 21801679
* Section : 2
* Assignment : 4
* Description : Header (.h) file of the Stack class that will be used fo DFT in the Word Network
*/

#ifndef __STACK_H
#define __STACK_H

#include <iostream>
#include <string>
using namespace std;

typedef int StackItemType;

class Stack {
public:
	Stack(); // Constructor
	Stack(const Stack&); //Copy Constructor for the deep copy
	~Stack(); // Destructor

	// Stack operations
	bool isEmpty() const; // Checks whether the stack is empty or not
	bool push(const StackItemType&); // Adds a new item to the top of the stack
	bool pop(); // Removes the last added item from the stack
	bool pop(StackItemType&); // Removes the last added item from the stack and returns the value by parameter list
	bool getTop(StackItemType&); // Gets te top item of the stack


private:
	StackItemType* items;
	int size; // Max size of the array
	int top; // Keeps the index of the top of the stack

	void expandSize(); // Doubles the size of the stack when it is full
};

#endif
