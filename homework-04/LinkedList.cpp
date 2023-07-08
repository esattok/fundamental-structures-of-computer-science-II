/*
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Esad Ýsmail Tök
* ID: 21801679
* Section : 2
* Assignment : 4
* Description : Implementation (.cpp) file of the Linked List data structure that is used as the chains in the Hash Table
*/

#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() {
    size = 0;
    head = NULL;
}

LinkedList::LinkedList(const LinkedList& formerList) {
    this->size = formerList.size;

    if (formerList.head == NULL) {
        head = NULL;
    }

    else {
        // First copy the first node
        head = new Node;
        head->data = formerList.head->data;

        // Then copy the rest of the list
        Node* newPtr = head;
        Node* origPtr = formerList.head->next;

        while (origPtr != NULL) {
            newPtr->next = new Node;
            newPtr = newPtr->next;
            newPtr->data = origPtr->data;

            origPtr = origPtr->next;
        }

        newPtr->next = NULL;
    }
}

LinkedList::~LinkedList() {
    // Until the list is empty call the remove function
    // Remove will handle the delete operations for each node
    while (!this->isEmpty()) {
        this->remove(1);
    }
}

bool LinkedList::isEmpty() const {
    if (size == 0) {
        return true;
    }

    else {
        return false;
    }
}

int LinkedList::getLength() const {
    return size;
}

// Private function implementation
LinkedList::Node* LinkedList::find(const int index) const {
    if (index < 1 || index > getLength()) {
        return NULL;
    }

    else {
        // Define a pointer as a cursor for the list nodes
        Node* current = head;

        for (int i = 1; i < index; i++) {
            current = current->next;
        }

        return current;
    }
}

bool LinkedList::retrieve(const string key, ListItemType& item) const {
    Node* cur = head;

    while (cur != NULL) {
        if ((cur->data).getItem() == key) {
            item = cur->data;
            return true;
        }

        cur = cur->next;
    }

    return false;
}


bool LinkedList::insert(const int index, const ListItemType& item) {
    if (index < 1 || index >(getLength() + 1)) {
        return false;
    }

    else {
        Node* newPtr = new Node;
        newPtr->data = item;
        size++;

        if (index == 1) {
            newPtr->next = head;
            head = newPtr;
        }

        else {
            Node* cur = find(index); // If we are adding to the last position newPtr's next will be NULL anyway sind find will return NULL
            Node* prev = find(index - 1);

            newPtr->next = cur;
            prev->next = newPtr;
        }

        return true;
    }
}

bool LinkedList::remove(const int index) {
    if (index < 1 || index > getLength()) {
        return false;
    }

    else {
        Node* cur = find(index);

        if (index == 1) {
            head = head->next;
        }

        else {
            Node* prev = find(index - 1);
            prev->next = cur->next;
        }

        cur->next = NULL;
        delete cur;
        cur = NULL;
        size--;

        return true;
    }
}

bool LinkedList::remove(const string key, ListItemType& item) {
    Node* cur = head;
    int count = 1; // Keeps the index

    while (cur != NULL) {
        if ((cur->data).getItem() == key) {
            item = cur->data;
            return remove(count);
        }

        count++;
        cur = cur->next;
    }

    return false;
}