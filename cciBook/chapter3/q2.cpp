// Design a stack with push, pop, and min (put isEmpty() as well).Min returns
// the minimum element of the stack, should all be O(1) time. So clear just need
// to store the min element as we add things.
// This is a simple problem it seems but is a bit more complicated 
// as there could be multiple minima and we must remove them one at a time.
// We also need to have the correct min when the current one is removed from
// stack. Seems like we need a very heavy stack. We could do it with an ordered
// list. Every time we remove something we need to update min, but it has to be
// O(1) time so we can't hide it in pop or push. No requirement on space. Okay 
// I think I have found a way we have a second linked list, we add elements 
// if and only if they are less than or equal to the current value, then for
// each pop we remove one if it matches the current value that we are popping 
// and not otherwise, we use the fact one cannot remove later elements before.

#include <iostream>
#include "linkedlist.h"
#include <exception>

template <typename T>
class MinStack {
	LinkedListSingle<T> data_stack;
	LinkedListSingle<T> min_stack;


	public:
		MinStack(); // No need for destructor.
		T peek();
		T pop();
		void push(T input);
		bool isEmpty();
		T min();
		void print();
};

int main() {
	MinStack<int> stack;
	stack.print();
	std::cout<<std::endl;
	for( int i=0; i<5; ++i ) {
		stack.push(i);
	}
	for( int i=0; i<5; ++i ) {
		stack.push(i);
	}
	stack.print();
	std::cout<<std::endl<<"Min:"<<stack.min()<<std::endl;
	
	stack.push(-1);
	stack.print();
	std::cout<<std::endl<<"Min:"<<stack.min()<<std::endl;
	std::cout<<stack.pop();
	std::cout<<std::endl;
	stack.print();
	std::cout<<std::endl<<"Min:"<<stack.min()<<std::endl;

	// This checks that the min is correctly dealt with if 
	// we remove the previous min.
	for( int i=0; i<5; ++i ) {
		std::cout<<stack.pop()<<"\t";
	}
	std::cout<<std::endl;
	stack.print();
	std::cout<<std::endl<<"Min:"<<stack.min()<<std::endl;
	

	stack.push(-1);
	for( int i=0; i<5; ++i ) {
		stack.push(i);
	}
	stack.print();
	std::cout<<std::endl<<"Min:"<<stack.min()<<std::endl;
	stack.push(-17);
	stack.print();		
	std::cout<<std::endl<<"Min:"<<stack.min()<<std::endl;

	stack.print();
	std::cout<<std::endl<<"Peek:"<<stack.peek()<<std::endl;
	stack.print();
	std::cout<<std::endl<<"Pop:"<<stack.pop()<<std::endl;
	stack.print();
	std::cout<<std::endl<<"Min:"<<stack.min()<<std::endl;
	stack.print();
	



	return 0;
}

template <typename T>
MinStack<T>::MinStack() {
	data_stack.head = NULL; // Strictly speaking this is unnecessary as 
				  // linkedlist already does this but making it
				  // explicity is perhaps easier.
	min_stack.head = NULL;
}

template <typename T>
T MinStack<T>::peek() {
	if( isEmpty() ) {
		throw std::out_of_range("No data to return.");
	}	

	return data_stack.head->data;	
}

template <typename T> 
T MinStack<T>::pop() {
	T output = peek();
	// Check if the output is the current min
	// If so remove the current min as well as
	// the current data from the stack
	if( output == min_stack.head->data ) {
		NodeSingle<T>* old_min = min_stack.head;
		min_stack.head = old_min->next;
		delete old_min;
	}
	NodeSingle<T>* old_data = data_stack.head;
	data_stack.head = old_data->next;
	delete old_data;

	return output;
}

template <typename T>
void MinStack<T>::push(T input) {
	NodeSingle<T>* new_node = new NodeSingle<T>(input);
	// If the stack is empty initialise it with the new data.
	if( isEmpty() ) {
		data_stack.head = new_node;
		NodeSingle<T>* new_min = new NodeSingle<T>(input);
		min_stack.head = new_min;
		return;
	} 
	NodeSingle<T>* previous_node = data_stack.head;
	data_stack.head = new_node;
	new_node->next = previous_node;
	// Check if we have a new min. Note we require < or = as we must have
	// one element in the list for each time this appears.
	if( input <= min_stack.head->data ) {
		NodeSingle<T>* previous_min = min_stack.head;
		NodeSingle<T>* new_min = new NodeSingle<T>(input);
		min_stack.head = new_min;
		new_min->next = previous_min;
	}
	return;

}

template <typename T>
bool MinStack<T>::isEmpty() {
	if( data_stack.head == NULL ) {
		return true;
	}
	return false;
}

template <typename T>
T MinStack<T>::min() {
	if( isEmpty() ) {
		throw std::out_of_range("No data to return");
	}
	return min_stack.head->data;
}

template <typename T>
void MinStack<T>::print() {
	if( isEmpty() ) {
		std::cout<<"The stack is empty.";
		return;
	}
	NodeSingle<T>* current_node = data_stack.head; 
	std::cout<<"Data Stack (current = "<<peek()<<")"<<std::endl;
	std::cout<<"{";
	while( current_node != NULL ) {
		std::cout<<current_node->data<<"\t";
		current_node = current_node->next;
	}
	std::cout<<"}"<<std::endl;
	
	std::cout<<"Min Stack (min = "<<min()<<")"<<std::endl;
	current_node = min_stack.head; 
	std::cout<<"{";
	while( current_node != NULL ) {
		std::cout<<current_node->data<<"\t";
		current_node = current_node->next;
	}
	std::cout<<"}"<<std::endl;


	return;
}

