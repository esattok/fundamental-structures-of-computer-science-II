/*
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Esad Ýsmail Tök
* ID: 21801679
* Section : 2
* Assignment : 4
* Description : Implementation (.cpp) file of the Grap that represents the word network
*/

#include <iostream>
#include <string>
#include "WordNetwork.h"
using namespace std;


// Constructor
WordNetwork::WordNetwork(const string vertexFile, const string edgeFile) {
	ifstream vertexInput;
	ifstream edgeInput;
	string name, source, dest;
	Word sourceObj, destObj;
	int count = 0;

	numOfVertices = 0;
	numOfEdges = 0;

	// Opening the input streams
	vertexInput.open(vertexFile.c_str(), ios_base::in);
	edgeInput.open(edgeFile.c_str(), ios_base::in);

	// Reading the vertex file
	while (vertexInput.eof() == false) {
		getline(vertexInput, name, '\n');

		// At the end of the file there is one empty line. This condition avoids the empty lines
		if (name != "") {
			hashTable.insert(name);
			numOfVertices++;
		}
	}

	indexToWord = new string[numOfVertices];

	// Clear the file stream
	vertexInput.clear();
	vertexInput.seekg(0, ios::beg);

	// Reading the vertex file
	while (vertexInput.eof() == false) {
		getline(vertexInput, name, '\n');

		// At the end of the file there is one empty line. This condition avoids the empty lines
		if (name != "") {
			indexToWord[count] = name;
			count++;
		}
	}


	// Creating the adj matrix with the size of V x V
	adjMatrix = new bool* [numOfVertices];
	for (int i = 0; i < numOfVertices; i++) {
		adjMatrix[i] = new bool[numOfVertices];

		// Initially all locations are false (includeing there is no edge)
		for (int j = 0; j < numOfVertices; j++) {
			adjMatrix[i][j] = false;
		}
	}

	// Reading the edge file
	while (edgeInput.eof() == false) {
		getline(edgeInput, source, ',');
		getline(edgeInput, dest, '\n');

		// At the end of the file there is one empty line. This condition avoids the empty lines
		if (source != "") {
			// Retrieve the word objects of the names that include their Indicies
			hashTable.retrieve(source, sourceObj);
			hashTable.retrieve(dest, destObj);

			// Creade the edge
			adjMatrix[sourceObj.getIndex()][destObj.getIndex()] = true;

			// The edge file does not contain the symmetric connections between edges. So fill the symmetric portion of the adj matrix as well to have an undirected graph
			adjMatrix[destObj.getIndex()][sourceObj.getIndex()] = true;

			numOfEdges++;
		}
	}

	// Closing the streams
	vertexInput.close();
	edgeInput.close();
}

// Destructor
WordNetwork::~WordNetwork() {
	// Deallocation of the adjacency matrix
	for (int i = 0; i < numOfVertices; i++) {
		delete[] adjMatrix[i];
	}
	delete[] adjMatrix;

	delete[] indexToWord;
}


// Operations
void WordNetwork::listNeighbors(const string word) {
	Word temp;
	if (hashTable.retrieve(word, temp)) {
		cout << "Neighbors of " << word << ":" << endl;

		for (int i = 0; i < numOfVertices; i++) {
			if (adjMatrix[temp.getIndex()][i] == true) {
				cout << indexToWord[i] << endl;
			}
		}
	}

	else {
		cout << "Warning: The word \"" << word << "\" is NOT included in the Word Network" << endl;
	}
}

// Uses BFT logic to traverse the vertices level by level and finds the vertices within the input level
void WordNetwork::listNeighbors(const string word, const int distance) {
	Word temp;

	if (hashTable.retrieve(word, temp) && (distance > 0)) {
		cout << "The original word: " << word << endl;
		cout << "Words withing the distance of " << distance << ":" << endl;

		Queue q;
		bool* isVisited = new bool[numOfVertices];
		int* distList = new int[numOfVertices]; // Keeps the distances of vertices to the source vertex

		// Initialization of the arrays
		for (int i = 0; i < numOfVertices; i++) {
			isVisited[i] = false;
			distList[i] = -1; // Initially distances of the vertices are unknown
		}

		q.enqueue(temp.getIndex());
		isVisited[temp.getIndex()] = true;
		distList[temp.getIndex()] = 0;

		while (!q.isEmpty()) {
			int tempIndex;
			q.dequeue(tempIndex);

			// If the distance exceeds then break the loop and done
			if (distList[tempIndex] > distance) {
				break;
			}

			// Do not print the original word again
			if (distList[tempIndex] != 0) {
				cout << indexToWord[tempIndex] << endl;
			}

			// Add all the neighbours
			for (int i = 0; i < numOfVertices; i++) {
				if (adjMatrix[tempIndex][i] && !isVisited[i]) {
					q.enqueue(i);
					isVisited[i] = true;
					distList[i] = distList[tempIndex] + 1; // Each vertex has a distance of one more than its previous vertex
				}
			}
		}

		delete[] isVisited;
		delete[] distList;
	}
	
	else if (distance <= 0) {
		cout << "Warning: The distance must be greater than 0" << endl;
	}

	else {
		cout << "Warning: The word \"" << word << "\" is NOT included in the Word Network" << endl;
	}
}


void WordNetwork::listConnectedComponents() {
	Stack stack; // Stack holds the indices of the words
	bool* isVisited = new bool[numOfVertices];
	int count = 1;
	bool found;

	for (int i = 0; i < numOfVertices; i++) {
		isVisited[i] = false;
	}

	// Untill all vertices are visited find the different connected components
	for (int i = 0; i < numOfVertices; i++) {
		if (!isVisited[i]) {
			cout << "Connected component " << count << ":" << endl;

			stack.push(i);
			isVisited[i] = true;
			cout << indexToWord[i] << endl;


			// DFT for each connected component
			while (!stack.isEmpty()) {
				int currentIndex;
				stack.getTop(currentIndex);

				// Search for a vertex that is neighbour with the current vertex and also is not visited yet
				found = false;
				for (int j = 0; j < numOfVertices; j++) {
					if (adjMatrix[currentIndex][j] && !isVisited[j]) {
						stack.push(j);
						isVisited[j] = true;
						found = true;
						cout << indexToWord[j] << endl;
						break;
					}
				}

				// If there is no neighbour vertex then pop the top
				if (!found) {
					stack.pop();
				}
			}

			count++;
			cout << endl;
		}
	}

	delete[] isVisited;
}


void WordNetwork::findShortestPath(const string word1, const string word2) {
	Word sourceObj, destObj;

	if (!(hashTable.retrieve(word1, sourceObj)) && !(hashTable.retrieve(word2, destObj))) {
		cout << "Warning: The words \"" << word1 << "\" and \"" << word2 << "\" are NOT included in the Word Network" << endl;
	}

	else if (!(hashTable.retrieve(word1, sourceObj))) {
		cout << "Warning: The word \"" << word1 << "\" is NOT included in the Word Network" << endl;
	}

	else if (!(hashTable.retrieve(word2, destObj))) {
		cout << "Warning: The word \"" << word2 << "\" is NOT included in the Word Network" << endl;
	}

	else if (word1 == word2) {
		cout << "Warning: The source and destination words must be different" << endl;
	}

	else {
		hashTable.retrieve(word1, sourceObj);
		hashTable.retrieve(word2, destObj);

		int sourceIndex = sourceObj.getIndex();
		int destIndex = destObj.getIndex();

		Queue q;
		bool* isVisited = new bool[numOfVertices];
		int* distList = new int[numOfVertices]; // Keeps the distances of vertices to the source vertex
		int* preList = new int[numOfVertices]; // Keeps the predecessor's index in the path from source to the dest
		bool isFound = false;

		// Initialization of the arrays
		for (int i = 0; i < numOfVertices; i++) {
			isVisited[i] = false;
			distList[i] = -1; // Initially distances of the vertices are unknown
			preList[i] = -1; // All values of the preList array is initally unvalid
		}

		q.enqueue(sourceIndex);
		isVisited[sourceIndex] = true;
		distList[sourceIndex] = 0;
		preList[sourceIndex] = -2; // There is no predecessor that we are conserned for the source word so its preList value is special

		while (!q.isEmpty()) {
			int tempIndex;
			q.dequeue(tempIndex);

			for (int i = 0; i < numOfVertices; i++) {
				if (adjMatrix[tempIndex][i] && !isVisited[i]) {
					q.enqueue(i);
					isVisited[i] = true;
					distList[i] = distList[tempIndex] + 1;
					preList[i] = tempIndex; // Stores the previous vertex index for a neighbor


					if (indexToWord[i] == word2) {
						isFound = true;
						break;
					}
				}
			}

			if (isFound) {
				break;
			}
		}

		if (!isFound) {
			cout << "There is no path between \"" << word1 << "\" and \"" << word2 << "\"" << endl;
		}

		else {
			// Load the path to stack to reverse it
			Stack s;
			int prevIndex = destIndex;
			
			while (prevIndex != -2) { // -2 is the prev index of the source
				s.push(prevIndex);
				prevIndex = preList[prevIndex];
			}

			// Print the results
			cout << "Shortest path from " << word1 << " to " << word2 << ":" << endl;

			int printIndex;
			while (!s.isEmpty()) {
				s.pop(printIndex);
				cout << indexToWord[printIndex] << endl;
			}
		}

		delete[] isVisited;
		delete[] distList;
		delete[] preList;
	}
}
