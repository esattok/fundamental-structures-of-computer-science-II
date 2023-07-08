/*
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Esad Ýsmail Tök
* ID: 21801679
* Section : 2
* Assignment : 4
* Description : Header (.h) file of the Hash Table that is implemented using seperate chaning
*/

#ifndef __HASHTABLE_H
#define __HASHTABLE_H

#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

class HashTable {
public:
	HashTable(); // Default Constructor
	HashTable(const int size); // Constructor

	~HashTable(); // Destructor

	// Accessor Functions
	int getTableSize() const;
	int getTotalItemSize() const;
	double getAlpha() const;

	// Hash Table Operations
	bool isEmpty() const;
	bool insert(const string item);
	bool retrieve(const string key, Word& item) const;
	bool remove(const string key, Word& item); // Removes the item with the given key and returns the deleted item

private:
	int tableSize; // Number of rows in the table
	int totalItemSize; // Total number of items in the hash table
	double alpha; // Load factor of the hash table

	LinkedList* table; // The table is an array of linked lists (seperate chaning)

	void setAlpha();
	int hashFunct(const string key) const;
};

#endif