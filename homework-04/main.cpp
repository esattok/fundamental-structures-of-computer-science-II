/*
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Esad Ýsmail Tök
* ID: 21801679
* Section : 2
* Assignment : 4
* Description : Driver (.cpp) file of the Grap that represents the word network
*/

#include <iostream>
#include <string>
#include "WordNetwork.h"
using namespace std;

int main() {
	WordNetwork network("words_vertices.txt", "words_edges.txt");

	

	network.listConnectedComponents();
	cout << endl;
	
	network.listNeighbors("roger");
	cout << endl;
	network.listNeighbors("rover");
	cout << endl;
	network.listNeighbors("rower");
	cout << endl;
	network.listNeighbors("roper");
	cout << endl;

	network.listNeighbors("mezzo");
	cout << endl;
	network.listNeighbors("mezzo", 5);
	cout << endl;

	network.listNeighbors("aided", 4);
	cout << endl;

	network.listNeighbors("roger", 2);
	cout << endl;

	network.findShortestPath("abcdef", "abcdeg");
	network.findShortestPath("abcdef", "graph");
	network.findShortestPath("nodes", "abcdef");
	network.findShortestPath("nodes", "nodes");
	network.findShortestPath("salvo", "solve");
	network.findShortestPath("helix", "weber");
	network.findShortestPath("nodes", "graph");
	

	return 0;
}