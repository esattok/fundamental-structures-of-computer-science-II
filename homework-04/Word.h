/*
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Esad Ýsmail Tök
* ID: 21801679
* Section : 2
* Assignment : 4
* Description : Header (.h) file of the Word class that represents a word in the graph
*/

#ifndef __WORD_H
#define __WORD_H

#include <iostream>
#include <string>
using namespace std;

class Word {
public:
	Word();
	Word(const string str, const int ind);

	string getItem() const;
	int getIndex() const;

	void setItem(const string str);
	void setIndex(const int ind);

private:
	string item;
	int index;
};

#endif