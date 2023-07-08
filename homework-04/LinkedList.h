/*
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Esad Ýsmail Tök
* ID: 21801679
* Section : 2
* Assignment : 4
* Description : Header (.h) file of the Linked List data structure that is used as the chains in the Hash Table
*/

#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

#include <iostream>
#include <string>
#include "Word.h"
using namespace std;

typedef Word ListItemType; // For reusability

class LinkedList {
public:
    LinkedList(); // Default Constructor
    LinkedList(const LinkedList&); // Copy Constructor
    ~LinkedList(); // Destructor

    // Operations
    bool isEmpty() const; // Checks whether the list is empty or not
    int getLength() const; // Determines the length of the linked list
    bool retrieve(const string key, ListItemType& item) const; // Gets an item from the linked list and returns it as parameter
    bool insert(const int index, const ListItemType& item); // Inserts an item to the specified index in the list
    bool remove(const int index); // Removes the item at the specified index from the linked list
    bool remove(const string key, ListItemType& item); // Removes an item with a key value

private:
    // Objects of this Node "structure" represents the nodes in the linked list.
    struct Node {
        ListItemType data;
        Node* next;
    };

    int size; 
    Node* head;

    Node* find(const int index) const; // Returns a pointer that holds the address of the node at specified index
};

#endif