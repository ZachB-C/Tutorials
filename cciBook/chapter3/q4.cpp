// Implement MyQueue which is a queue class implemented using two stacks.
// Queues need add to back of queue, remove from front of queue, peek at
// front of queue, and isEmpty. If we use two stacks we could use them to
// upload one stack onto another then add the new element to the empty stack 
// and reload all the others, this means add is O(n) and remove is O(1). Can't
// think of another way though.
//
#include <iostream>
#include "stackqueue.h"


template <typename T>
class MyQueue {
	MyStack<T> main_stack;
	MyStack<T> sidings_stack;
	
	public:
		MyQueue() {}; // Constructor is trivial.
		void add(T input);
		T remove();
		T peek();
		bool isEmpty();
		void print();
	private:
		bool sidingsInUse();
		void clearSidings();
		void loadSidings();
};	

int main() {
	MyQueue<int> queue;
	queue.print();

	queue.add(0);
	queue.print();
	std::cout<<std::endl;

	std::cout<<" Peek: "<<queue.peek()<<std::endl;
	queue.print();
	std::cout<<std::endl;
	
	std::cout<<" Remove: "<<queue.remove()<<std::endl;
	queue.print();
	std::cout<<std::endl;
	
	std::cout<<" Add: "<<std::endl;	
	for(size_t i=0; i<16; ++i) {
		queue.add(i);
	}

	queue.print();
	std::cout<<std::endl;

	std::cout<<"Remove : "<<std::endl;	
	for(size_t i=0; i<7; ++i) {
		queue.remove();
	}
	queue.print();
	std::cout<<std::endl;
}

template <typename T>
void MyQueue<T>::add(T input) {
	// Move all the data onto the sidings so last element is first
	loadSidings();
	// Add the new data to the sidings, don't bother to put back
	// as the calls that need it on the main stack will clear the sidings
	// first.
	sidings_stack.push(input);

	return;
}

template <typename T>
T MyQueue<T>::peek() {
	clearSidings();
	return main_stack.peek();
}

template <typename T>
T MyQueue<T>::remove() {
	clearSidings();
	return main_stack.pop();
}

template <typename T>
bool MyQueue<T>::isEmpty() {
	if( main_stack.isEmpty() ) {
		return true;
	} 
	return false;
}

template <typename T>
bool MyQueue<T>::sidingsInUse() {
	if( sidings_stack.isEmpty() ) {
		return false;
	}
	return true;
}

template <typename T>
void MyQueue<T>::print() {
	std::cout<<"Main: ";
	main_stack.print();
	std::cout<<std::endl;
	std::cout<<"Sidings: ";
	sidings_stack.print();
	std::cout<<std::endl;
}

template <typename T>
void MyQueue<T>::clearSidings() {
	while( !(sidings_stack.isEmpty()) ) {
		// Shift everything currently on the main stack
		// into the sidings.
		main_stack.push(sidings_stack.pop());
	}
	return;	
}

template <typename T>
void MyQueue<T>::loadSidings() {
	while( !(main_stack.isEmpty()) ) {
		// Shift everything currently on the main stack
		// into the sidings.
		sidings_stack.push(main_stack.pop());
	}
	return;
}
