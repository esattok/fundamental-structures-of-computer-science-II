/*
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Esad Ýsmail Tök
* ID: 21801679
* Section : 2
* Assignment : 4
* Description : Implementation (.cpp) file of the Hash Table that is implemented using seperate chaning
*/

#include <iostream>
#include <string>
#include "HashTable.h"
using namespace std;


HashTable::HashTable() {
	// The table size is deliberately choosen to be a large prime number so that it minimizes the load factor 
	// And prevents the long chains even if there are collusions. 
	tableSize = 6007; 
	totalItemSize = 0;
	alpha = 0;

	table = new LinkedList[tableSize];
}

HashTable::HashTable(const int size) {
	tableSize = size;
	totalItemSize = 0;
	alpha = 0;

	table = new LinkedList[tableSize];
}

HashTable::~HashTable() {
	delete [] table;
}

// Accessor Functions
int HashTable::getTableSize() const {
	return tableSize;
}

int HashTable::getTotalItemSize() const {
	return totalItemSize;
}

double HashTable::getAlpha() const {
	return alpha;
}


// Table Operations
bool HashTable::isEmpty() const {
	return (totalItemSize == 0);
}

bool HashTable::insert(const string item) {
	int hashValue = hashFunct(item); // Find the index of a linked list in the table to insert the item

	Word temp(item, totalItemSize); // Each linked list node both contains the word itself and the corresponding index of it
	table[hashValue].insert(1, temp); // Insert the new item at the beginning of the linked list so that it is O(1) complexity

	totalItemSize++;
	setAlpha();
	return true;
}

bool HashTable::retrieve(const string key, Word& item) const {
	int hashValue = hashFunct(key); // Find the index of a linked list in the table to search for the item

	return (table[hashValue].retrieve(key, item)); // If it can find the item with the string key, then it returns true and returns the word. Otherwise return false
}

bool HashTable::remove(const string key, Word& item) {
	int hashValue = hashFunct(key); // Find the index of a linked list in the table to search for the item

	return (table[hashValue].remove(key, item)); // If it can find the item with the string key, then it returns true, removes item and returns the word. Otherwise return false
}



// Private Functions
void HashTable::setAlpha() {
	alpha = ((double)totalItemSize / tableSize);
}

int HashTable::hashFunct(const string key) const {
	int hashValue = 0;

	for (unsigned int i = 0; i < key.length(); i++) {
		hashValue = 37 * hashValue + key[i];
	}

	hashValue = hashValue % tableSize;

	if (hashValue < 0) {
		hashValue = hashValue + tableSize;
	}

	return hashValue;
}