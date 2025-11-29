// We need to have a set of stacks each with a defined capacity and it should
// swap to the next stack when the first is full. We need pop and push to 
// behave as they would for a single stack. We also need to define popAt. Which
// pops a particular substack. So I guess I use linked list and have a macro
// for the stack size. Then record how many are in the stack and start a new 
// one if the stack gets too big. The main issue I see is what to do when we 
// are using multiple stacks and we pop of the first one. No that is okay as the
// first one should be the latest stack. So we will always pop the higher stack
// maybe have method currentStack that returns index of current stack, which is
// also the number of stacks that are currently active. I will use linkedlist 
// and delete it if we pop of its last element. Check delete calls the 
// destructor. I guess it should.
//
//
// Need to check this I think I have made a mistake the data of the stackSet
// is the pointer I think so we need to do stackSet.head->data to get the 
// pointer to the first stack and then stackSet.head->data->head->data to get
// the first data from the first stack. I should wrap these in separate 
// functions to make things easier. I need a function that returns the pointer
// to the nth stack, and another function that gets the data from the nth stack
// when given a pointer, another that removes the first piece of data from the
// nth stack when given a pointer, and finally one that removes the nth stack
// when given n and tidies up the two connections, I think that is a built in 
// actually so that should be easier. It is deleteNthNode(size_t n) that is 
// easier.
//
#include <iostream>
#include <exception>
#include "linkedlist.h"

#define MAX_SIZE 3 

template <typename T>
class SetOfStacks {
	LinkedListSingle<LinkedList<T>*> stackSet; // This has a pointer to 
				      // the current stack om the top
	LinkedListSingle<size_t> stackCount; // This has the number of elements
					     // in each linked list, required 
					     // to allow us to pop off stacks
					     // easily without checking how much
					     // is in it.
	size_t n_stacks; // The number of stacks currently initialised.
	
	public: 
		// Here nth stack is nth from start so current stack is 0.
		// We could make one that works from final stack using double 
		// runners.
		SetOfStacks(); // Don't need a destructor as only items
			       // it knows how to destroy.
		T peek(); // Peeks at most recent stack.
		T pop(); // Pops from the most recent stack.
		T peekAt(size_t n); // Peeks from nth stack
		T popAt(size_t n); // Pops from nth stack.
		void push(T input); // Pushes onto most recent stack.
		void pushAt(T input, size_t n); // Pushes onto nth stack (only 
						// if there is space.
		bool isEmpty(); // True iff the whole set of stacks is empty.
		void print(); // Prints out the full content of the stack.
	
	private:
		bool isFull(); // True iff current stack is full.
		void initialiseNewStack(); // Makes a new stack that links
					   // to the previous one.
		void deleteEmptyStack(size_t n); // Deletes the nth stack.
		void incrementCount(); // Increments the counter for how 
				       // many elements in the stack.
		bool isEmptyLocal(LinkedListSingle<T>* stack);
		LinkedListSingle<T>* findStack(size_t n); // Returns pointer
							  // to nth stack
};


int main() {
	SetOfStacks<int> set;
	set.print();
	for(int i = 0; i<21; ++i) {
		set.push(i);
	}
	set.print(); // Print each stack out under each other in order.

	std::cout<<"Peek: "<<set.peek()<<std::endl;
	set.print();
	std::cout<<"Pop: "<<set.pop()<<std::endl;
	set.print();
	std::cout<<"Peek At: 2: "<<set.peekAt(2)<<std::endl;
	set.print();
	std::cout<<"Pop At: 2: "<<set.popAt(2)<<std::endl;
	set.print();
	for( int i = 0; i<6; ++i) {
		std::cout<<"Pop At: 2: "<<set.popAt(2)<<std::endl;
	}
	set.print();
	for( int i = 0; i<6; ++i) {
		std::cout<<"Push At: 2: "<<set.pushAt(2)<<std::endl;
	}
	set.print();
	std::cout<<"Pop: "<<set.pop()<<std::endl;
	set.print();


	return 0;
}


template <typename T> 
SetOfStacks<T>::SetOfStacks() {
	stackSet = NULL;
	// Current value is zero.
	stackCount.push(0);
	n_stacks = 0;
}


//template <typename T>
//T SetOfStacks<T>::peekLocal(LinkedListSingle<T>* stack) {
//	// Why not use local peek
//	if( isEmptyLocal( stack ) ) {
//		throw out_of_range("There are no elements to return.");
//	}
//	return stack->head->data;
//}

//template <typename T>
//void SetOfStacks<T>::removeLocal(LinkedListSingle<T>* stack) {
//	if( isEmptyLocal( stack ) ) {
//		throw out_of_range("There are no nodes to remove.");
//	}
//	NodeSingle<T>* old_node = stack->head;
//	stack->head = old_node;
//	delete old_node;
//	return;
//}

// We could just use the built in push functions for this...
//template <typename T>
//void SetOfStacks<T>::pushLocal(T input, LinkedListSingle<T>* stack) {
//	// Make a new node
//	NodeSingle<T>* new_node = NodeSingle<T>(input);
//	// Link the new node to the old node
//	new_node->head = stack->head;
//	// Redefine head
//	stack->head = new_node;
//	return;
//}

template <typename T>
T SetOfStacks<T>::peek() {
	if( isEmpty() ) {
		throw out_of_range("No data to find.");
	}
	LinkedListSingle<T>* current_stack = stackSet.head;
	return current_stack->head->data;
}



template <typename T>
T SetOfStacks<T>::pop() {
	T output = peek();
	// Now link the current stack head to the next node and
	// delete the first node.
	LinkedListSingle<T>* current_stack = stackSet.head;
	// Remove the most recent node.
	(*current_stack).removeFromHead();
	// Now we have to update stack
	if( current_stack->head == NULL ) {
		// If this stack is empty we remove it.
		stackSet.removeFromHead();
		// Decrement the number of stacks
		--n_stacks;
	}

	return output;
}

template <typename T>
LinkedListSingle<T>* findStack(size_t n) {
	if( isEmpty() ) {
		throw out_of_range("No data to find.");
	}
	LinkedListSingle<T>* current_stack = stackSet.head;
	// Obtain the correct stack
	for( int m=0; m<n; ++m) {
		if( isEmptyLocal(current_stack) )
		{
			throw out_of_range("No data to find");
		}
		// Keep looking until we find the right stack
		// Would be quicker with vector or hash
		current_stack = current_stack->next;
	}
	return current_stack;
}


template <typename T>
void SetOfStacks<T>::deleteEmptyStack(size_t n) {
	if( isEmpty() ) {
		throw out_of_range("No data to find.");
	}
	LinkedListSingle<T>* current_stack = stackSet.head;
	// Obtain the correct stack, stop at the stack before
	// our target
	for( int m=0; m<n-1; ++m) {
		if( isEmptyLocal(current_stack) )
		{
			throw out_of_range("No data to find");
		}
		// Keep looking until we find the right stack
		// Would be quicker with vector or hash
		current_stack = current_stack->next;
	}
	target_stack = current_stack->next;
	current_stack->next = target_stack->next;
	delete target_stack;
	return;
}

template <typename T>
T SetOfStacks<T>::peekAt(size_t n) {
	// Apply peek to that stack
	return find_stack(n)->head->data;

}

template <typename T>
T SetOfStacks<T>::popAt(size_t n) {
	LinkedListSingle<T>* current_stack = find_stack(n);
	// Get data
	output = current_stack->head->data;
	// Remove node
	current_stack->removeFromHead();
	// If current stack is empty we remove it, this is a bit complex
	if( current_stack->head == NULL)
	return output;
}

// Maybe better if we have popLocal that takes a pointer to a linked list
// and applies pop and also peekLocal and pushLocal then we can defined peekAt
// to just navigate to the correct place and call that. Can redefine peek
// and pop to use the same thing.



	LinkedListSingle<LinkedListSingle<T>&> stackSet; // This has a reference to 
				      // the current stack om the top
	LinkedListSingle<size_t> stackCount; // This has the number of elements
					     // in each linked list, required 
					     // to allow us to pop off stacks
					     // easily without checking how much
					     // is in it.
	size_t n_stacks; // The number of stacks currently initialised.
	
	public: 
		// Here nth stack is nth from start so current stack is 0.
		// We could make one that works from final stack using double 
		// runners.
		SetOfStacks(); // Don't need a destructor as only items
			       // it knows how to destroy.
		T peek(); // Peeks at most recent stack.
		T pop(); // Pops from the most recent stack.
		T peekAt(size_t n); // Peeks from nth stack
		T popAt(size_t n); // Pops from nth stack.
		void push(T input); // Pushes onto most recent stack.
		void pushAt(T input, size_t n); // Pushes onto nth stack (only 
						// if there is space.
		bool isEmpty(); // True iff the whole set of stacks is empty.
		void print(); // Prints out the full content of the stack.
	
	private:
		bool isFull(); // True iff current stack is full.
		void initialiseNewStack(); // Makes a new stack that links
					   // to the previous one.
		void deleteEmptyStack(size_t n); // Deletes the nth stack.

