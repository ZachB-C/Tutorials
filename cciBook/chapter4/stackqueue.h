// Here we will write declare the queue and stack classes, which will be       
// implemented in stackqueue.cpp
#ifndef STACKQUEUE_H
#define STACKQUEUE_H

#include <iostream>
#include <vector>
#include "linkedlist.h"

///
///
///
///
///
///
///
///  Stack
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
class Stack {
	LinkedList<T> list;
	//size_t n_elements; // Store how many elements in the stack. Not needed
	//			as we can get it from the linked list structure

	public:
//		Stack(); // Constructor (don't need destructor as we will
			  // use linked lists which have a destructor defined.
//		~Stack(); // Put in a destructor to set n_elements to zero
		T pop(); // Removes first item from stack and hands it back
		void push(T element); // Puts an item on stack 
		T peek(); // Returns top item in stack but leaves it in place
		bool isEmpty(); // Returns true if empty and false if not.
		void pushVector( std::vector<T> input_data); // Bonus to load 
						      // multiple at once
		void print(); // Print all elements.
		size_t length(); // Gives current length of stack.
};

template <typename T>
T Stack<T>::peek() {
	return list.peekHead();
}


template <typename T>
T Stack<T>::pop() {
	return list.popHead();
}

template <typename T>
void Stack<T>::push(T element) {
	list.insertAtHead(element);
	return;
}

template <typename T>
bool Stack<T>::isEmpty() {
	return list.isEmpty();	
}



template <typename T>
void Stack<T>::pushVector( std::vector<T> input_data ) {
	list.insertVectorAtHead(input_data);
	return;
}

template <typename T>
void Stack<T>::print() {
	list.print();
	return;
}

template <typename T> 
size_t Stack<T>::length() {
	return list.length();
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
/// Queue
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
class Queue {
	LinkedList<T> list;

	public:
//		QueueOld(); // Constructor
//		~QueueOld(); // Make sure to NULL the pointers when destroying
		void add(T item); // Add item to end of list
		T remove();    // Remove item from head of list
		T peek();     // Return first item of list but do not remove
		bool isEmpty();   // Return true if and only if list is empty
		void addVector( std::vector<T> data); // Bonus to load 
						      // multiple data at once.
		void print(); // Print all elements
		size_t length(); // Gives current length of list.
};
		
template <typename T>
void Queue<T>::add(T item) {
	list.insertAtTail(item);
	return;
}

template <typename T>
T Queue<T>::remove() {
	return list.popHead();
}

template <typename T>
T Queue<T>::peek() {
	return list.peekHead();
}

template <typename T>
bool Queue<T>::isEmpty() {
	return list.isEmpty();
}

template <typename T>
void Queue<T>::addVector(std::vector<T> data) {
	return list.insertVectorAtTail(data);
}

template <typename T>
void Queue<T>::print() {
	return list.print();
}

template <typename T>
size_t Queue<T>::length() {
	return list.length();
}



#endif

