/*
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Esad Ýsmail Tök
* ID: 21801679
* Section : 2
* Assignment : 4
* Description : Header (.h) file of the Word class that represents a word in the graph
*/

#include <iostream>
#include <string>
#include "Word.h"
using namespace std;

Word::Word() {
	item = "";
	index = 0;
}

Word::Word(const string str, const int ind) {
	item = str;
	index = ind;
}

string Word::getItem() const {
	return item;
}

int Word::getIndex() const {
	return index;
}


void Word::setItem(const string str) {
	item = str;
}

void Word::setIndex(const int ind) {
	index = ind;
}
