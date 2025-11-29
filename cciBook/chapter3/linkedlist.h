// This is the helper file for the linked list programs, it defines the linked
// list class so that we can use it. Have two definitions, single and 
// double linked list.
// If we have not included this helper file before then 
// include it now.
// Can we define a default constructor here and non-default in cpp file.
#ifndef LINKEDLIST_H
// Define to prevent multiple inclusions
#define LINKEDLIST_H

#include <vector>
#include <iostream>
#include <exception>
//
///
///
///
///
///
/// Node Single
///
///
///
///
///
//
//

// Define classes
//template <typename T = int> // This gives default type.
template <typename T>
class NodeSingle {
	public:
		T data;
		NodeSingle<T>* next;
		// Constructor
		NodeSingle(T input_data=0);

};

template <typename T>
NodeSingle<T>::NodeSingle(T input_data): data(input_data), next(NULL) {}


///
///
///
///
///
/// NodeDouble
///
///
///
///
///
///
///

class NodeDouble {};

//
///
///
///
///
/// LinkedListSingle
///
///
///
///
///
///
///
//



template <typename T>
class LinkedListSingle {

	public:
		NodeSingle<T>* head;
		// Default constructor
		LinkedListSingle();
		// Destructor
		~LinkedListSingle();
		// Function to insert node at beginning of linked list
		void insertAtHead(T Data);
		void insertVectorAtHead(std::vector<T> data_in);
		void removeFromHead();
		void deleteNode(T d);
		void deleteNthNode(size_t n);
		NodeSingle<T>* accessNthNode(size_t n);
//		void deleteAllNodes();
		// Function to print linked list
		void print();
};


// Class definitions
// Can default to int but won't do it to make sure it works.
template <typename T>
LinkedListSingle<T>::LinkedListSingle(): head(NULL) {}
// Destructor
template <typename T>
LinkedListSingle<T>::~LinkedListSingle() {
	NodeSingle<T>* current = head;
	NodeSingle<T>* next = head;
	while( current != NULL ) {
		next = current->next;
		delete current;
		current = next;
	}
	head = NULL;
}
// Function to insert a node at beginning
// of linked list

template <typename T>
void LinkedListSingle<T>::insertAtHead(T data) {
	// Create a new node
	NodeSingle<T>* newNode = new NodeSingle<T>(data);
	// Assign to head of the list if empty
	if( head == NULL ) {
		head = newNode;
		return;
	}
	// Insert the newly created linked list at the head
	// this is unnecessary
	newNode->next = this->head;
	this->head = newNode;
}

template <typename T>
void LinkedListSingle<T>::insertVectorAtHead(std::vector<T> data_in) {
	for( size_t i = data_in.size(); i-- > 0; ) {
		insertAtHead(data_in[i]);
	}
}

template <typename T>
void LinkedListSingle<T>::deleteNode(T d) {
	NodeSingle<T>* current = head;
	NodeSingle<T>* next = head;

	// If the data is at head move head.
	if( current->data == d ) {
		head = current->next;
		delete current;
		return;
	}

	while( current->next != NULL ) {
		if( current->next->data == d ) {
			next = current->next;
			current->next = current->next->next;
			delete next;
			return;
		}
		current = current->next;
	}
	return;
}


template <typename T>
void LinkedListSingle<T>::removeFromHead() {
	if( head == NULL ) {
		throw std::out_of_range("No data to remove");
	}
	// Find current node
	NodeSingle<T>* current = head;
	// Change head to point to the next node
	head = current->next;
	// Delete current top node.
	delete current;
	return;
}

// Zero indexed.

template <typename T>
void LinkedListSingle<T>::deleteNthNode(size_t n) {
	NodeSingle<T>* current = head;
	NodeSingle<T>* next = head;
	if( n == 0 ) {
		head = head->next;
		delete current;
		return;
	}
	// Careful of this we end up one before
	// the one we want to delete.	
	for( size_t i=1; i<n; ++i) {
		current = current->next;
	}	
	next = current->next;
	current->next = current->next->next;
	delete next;
	return;
}

// Zero indexed.

template <typename T>
NodeSingle<T>* LinkedListSingle<T>::accessNthNode(size_t n) {
	NodeSingle<T>* current = head;
	for( size_t i=0; i<n; ++i) {
		current = current->next;
	}	
	return current;
}	


// Function to print the linked list
// Must make sure the data type is compatible with <<
template <typename T>
void LinkedListSingle<T>::print() {
	NodeSingle<T> *temp = head;
	// Check for empty list
	if( head == NULL ) {
		std::cout<<"List empty" << std::endl;
		return;
	}
	// Traverse the list
	while( temp != NULL ) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
}

///
///
///
///
///
///
///
///  LinkedListDouble
///
///
///
///
///
///
///
///
///
class LinkedListDouble {};
#endif
