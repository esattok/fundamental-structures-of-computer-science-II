/*
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Esad Ýsmail Tök
* ID: 21801679
* Section : 2
* Assignment : 4
* Description : Header (.h) file of the Grap that represents the word network
*/

#ifndef __WORDNETWORK_H
#define __WORDNETWORK_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "HashTable.h"
#include "Stack.h"
#include "Queue.h"
using namespace std;

class WordNetwork {
public:
	WordNetwork(const string vertexFile, const string edgeFile);
	~WordNetwork();

	void listNeighbors(const string word);
	void listNeighbors(const string word, const int distance);
	void listConnectedComponents();
	void findShortestPath(const string word1, const string word2);

	
private:
	int numOfVertices;
	int numOfEdges;

	HashTable hashTable; // Hash table is used for word -> index mapping
	bool** adjMatrix; // Adjacency matrix locations include the names in that column
	string* indexToWord; // Alows us to perform index -> word lookup in O(1) time

};

#endif