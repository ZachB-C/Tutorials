// Here we will write declare the queue and stack classes, which will be       
// implemented in stackqueue.cpp
#ifndef STACKQUEUE_H
#define STACKQUEUE_H

#include <iostream>
#include <vector>
#include "linkedlist.h"
#include <string>
#include <exception>

///
///
///
///
///
///
///
///  MyStack
///
///
///
///
///
///
///
///
///
///



template <typename T>
class MyStack {
	LinkedListSingle<T> list;
	size_t n_elements; // Store how many elements in the stack.

	public:
		MyStack(); // Constructor (don't need destructor as we will
			  // use linked lists which have a destructor defined.
		~MyStack(); // Put in a destructor to set n_elements to zero
		T pop(); // Removes first item from stack and hands it back
		void push(T element); // Puts an item on stack 
		T peek(); // Returns top item in stack but leaves it in place
		bool isEmpty(); // Returns true if empty and false if not.
		void pushVector( std::vector<T> input_data); // Bonus to load 
						      // multiple at once
		void print(); // Print all elements.
		size_t length(); // Gives current length of stack.
};


// Stack stuff
template <typename T> 
MyStack<T>::MyStack() {
	// I don't think I should specify types when I initialise
	// otherwise it makes a new local variable so not int n_elements = 0
	// just n_elements = 0;
	
	// I think I could just refer to head and not list.head as it is local
	list.head = NULL;
	n_elements = 0;	
}

template <typename T>
MyStack<T>::~MyStack() {
	// Destroy data
	list.~LinkedListSingle();
	// Reset number of elements
	n_elements = 0;
}

template <typename T>
T MyStack<T>::pop() {
	// Get the data
	T data = peek();
	// Move the head and remove the previous node
	NodeSingle<T>* old_node = list.head;
	list.head = old_node->next;
	delete old_node;
	// Change n_elements
	--n_elements;
	return data;
}

template <typename T>
T MyStack<T>::peek() {
	// Check the data exists
	if( isEmpty() ) {
		throw std::length_error(std::to_string(n_elements) 
				+ " elements in string.");
	}
	// If the data exists then return it
	return list.head->data;
}

template <typename T>
bool MyStack<T>::isEmpty() {
	if( n_elements == 0 ) {
		if( list.head == NULL ) {
			return true;
		} else {
			throw std::logic_error(
				"No elements but first element at "
				 + std::to_string( (unsigned long long) list.head)
				);
		}	
	} else if( list.head == NULL ) {
		throw std::logic_error(std::to_string(n_elements) 
				+ " elements but pointer is missing.");
	} else {
		return false;
	}	
}

template <typename T>
void MyStack<T>::push(T element) {
	NodeSingle<T>* new_node = new NodeSingle<T>(element);
	// If currently empty then just add the new node
       	if( isEmpty() ) {
       		list.head = new_node;
       	} else {
		// Add node to top of the list.
		new_node->next = list.head;
		list.head = new_node;
	}
	// Increment number of elements
	++n_elements;
	return;
}

template <typename T>
void MyStack<T>::pushVector( std::vector<T> input_data ) {
	for(T datum : input_data ) {
		push( datum);	
	}
	return;
}

template <typename T>
void MyStack<T>::print() {
	list.print();
	return;
}

template <typename T> 
size_t MyStack<T>::length() {
	return n_elements;
}




///
///
///
///
///
///
///
///
///
///
/// MyQueue
///
///
///
///
///
///
///
///
///
/// 
///
template <typename T>
class MyQueueOld {
	LinkedListSingle<T> list;
	NodeSingle<T>* first;
	NodeSingle<T>* last;
	size_t n_elements;

	public:
		MyQueueOld(); // Constructor
		~MyQueueOld(); // Make sure to NULL the pointers when destroying
		void add(T item); // Add item to end of list
		T remove();    // Remove item from head of list
		T peek();     // Return first item of list but do not remove
		bool isEmpty();   // Return true if and only if list is empty
		void addVector( std::vector<T> data); // Bonus to load 
						      // multiple data at once.
		void print(); // Print all elements
		size_t length(); // Gives current length of list.
};
		


#endif

