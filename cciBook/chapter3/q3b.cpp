// Second attempt, for set of stacks, I'll use a vector to simplify things.
// Okay do not call a destructor and then use the item again, Can make a 
// separate clean up funciton that is called by the destructor to empty an
// object.
#include <iostream>
#include <vector>
#include <exception>
#include <string>
#include "stackqueue.h"

// Classes
template <typename T>
class SetOfStacks {
	std::vector<MyStack<T>*> stack_ptrs;
	std::vector<size_t> stack_count; // counts the elements in each stack
	size_t num_stacks; // The number of stacks
	size_t n_curr_stack; // The current stack index
	size_t stack_max; // The number of elements permitted in a stack.
	
	public:
		SetOfStacks(size_t stack_max_input);
		~SetOfStacks();
		size_t n_stacks();
		T peek();
		T peekAt(size_t n);
		T pop();
		T popAt(size_t n);
		void push(T input);
		void pushAt(T input, size_t n);
		void print();
		bool isEmpty();
		bool isEmptyAt(size_t n);
		void clean_up();
	private:
		bool isStackAt(size_t n);
		bool isFullAt(size_t n);

};


int main() {
	SetOfStacks<int> set(3);
	std::cout<<"Start: "<<std::endl;
	set.print();
	std::cout<<"Push: "<<std::endl;
	set.push(0);
	std::cout<<"Print: "<<std::endl;
	set.print();
	std::cout<<"Pop: "<<std::endl;
	set.pop();
	std::cout<<"Print: "<<std::endl;
	set.print();
	std::cout<<"Push 2: "<<std::endl;
	set.push(0);
	set.print();

	std::cout<<"Push 3: "<<std::endl;
	for(int i = 1; i<21; ++i) {
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
	for( int i = 0; i<2; ++i) {
		std::cout<<"Pop At: 2: "<<set.popAt(2)<<std::endl;
	}
	set.print();
	for( int i = 0; i<3; ++i) {
		set.pushAt(i, 2);
	}
	set.print();
	std::cout<<"Pop: "<<set.pop()<<std::endl;
	std::cout<<"Pop: "<<set.pop()<<std::endl;
	std::cout<<"Pop: "<<set.pop()<<std::endl;
	std::cout<<"Pop: "<<set.pop()<<std::endl;
	std::cout<<"Pop: "<<set.pop()<<std::endl;
	std::cout<<"Pop: "<<set.pop()<<std::endl;
	set.print();

	set.clean_up();
	std::cout<<"Deleted"<<std::endl;
	set.print();
	set.push(21);
	set.print();
	std::cout<<"Finished."<<std::endl;

	return 0;
}
// Let's try an define a clear operation that is defined differently as 
// see if it is a property of the destructor.

template <typename T>
SetOfStacks<T>::SetOfStacks(size_t stack_max_input) {
	//stack_ptrs.push_back(NULL);
	//stack_count.push_back(0); 
	num_stacks = 0;
	n_curr_stack = 0;
	stack_max = stack_max_input;
}

template <typename T>
void SetOfStacks<T>::clean_up() {
	// n is the number of pointers (1 indexed) so we need to subtract
	// 1 to get the pointer we are aiming at.
	for( size_t n = n_stacks(); n>0; --n) {
		// Call destructors on all assigned stacks
		// and set the counts to zero.
		if(stack_ptrs[n-1] != NULL ) {
			delete stack_ptrs[n-1];
			stack_ptrs.pop_back();
			stack_count.pop_back();

		}
	}
	n_curr_stack = 0;
	num_stacks = 0;
//	stack_count.clear();
//	stack_ptrs.clear();
}


template <typename T>
SetOfStacks<T>::~SetOfStacks() {
	// n is the number of pointers (1 indexed) so we need to subtract
	// 1 to get the pointer we are aiming at.
	clean_up();
//	std::cout<<"Deleting."<<n_stacks()<<std::endl;
//	for( size_t n = n_stacks(); n>0; --n) {
//		// Call destructors on all assigned stacks
//		// and set the counts to zero.
//		std::cout<<n-1<<" of "<<n_stacks()-1<<std::endl;
//		if(stack_ptrs[n-1] != NULL ) {
//			delete stack_ptrs[n-1];
//			stack_ptrs.pop_back();
//			stack_count.pop_back();
//
//		}
//	}
//	n_curr_stack = 0;
//	num_stacks = 0;
//	stack_count.clear();
//	stack_ptrs.clear();
}

template <typename T>
T SetOfStacks<T>::peekAt(size_t n) {
	if( isEmptyAt(n) ) {
		throw std::out_of_range("Nothing to see here.");
	}
	MyStack<T>* current_stack = stack_ptrs[n];
	return current_stack->peek();
}

template <typename T>
T SetOfStacks<T>::peek() {
	if( isEmpty() ) {
		throw std::out_of_range("Nothing to see here.");
	}
	return peekAt(n_curr_stack);
}

// Need to decide how to handle this. I will have that intermediate stacks
// are not destroyed but instead left with NULL pointers so that the numbering
// is preserved. This will be different for the primary stack.
template <typename T>
T SetOfStacks<T>::popAt(size_t n) {
	if( isEmptyAt(n) ) {
		throw std::out_of_range("Nothing to see here.");
	}
	MyStack<T>* current_stack = stack_ptrs[n];
	--stack_count[n]; // Note how many elements are in the stack at n.
	return current_stack->pop();
}

template <typename T>
T SetOfStacks<T>::pop() {
	if( isEmpty() ) {
		throw std::out_of_range("Nothing to see here.");
	}
	T output = popAt(n_curr_stack);
	// If poping leaves current stack empty then we adjust.
	if( stack_count[n_curr_stack] == 0 ) {
		// Delete the stack if we no longer need it.
		delete stack_ptrs[n_curr_stack];
		stack_ptrs.pop_back();
		stack_count.pop_back();
		if( n_curr_stack > 0 ) {
			n_curr_stack = n_curr_stack - 1;
		}
		--num_stacks;
	}
	return output;
}


template <typename T>
void SetOfStacks<T>::pushAt(T input, size_t n) {
	if( !(isStackAt(n)) ) {
		throw std::out_of_range(std::to_string(n) 
				+ "th stack does not exist, there are only "
				+ std::to_string(n_curr_stack) + " stacks.");
	}
	if( isFullAt(n) ) {
		// If it is full we refuse to put it oStack 7 of 10: 16 15
		// n mid-stack
		throw std::out_of_range("Stack is full, no room for additions. "
				+ std::to_string(stack_max) 
				+ " elements is max.");
	}
	MyStack<T>* current_stack = stack_ptrs[n];
	current_stack->push(input);
	++stack_count[n]; // Note how many elements are in the stack at n.
	return;

}


template <typename T>
void SetOfStacks<T>::push(T input) {
	// Deal with the stack not existing or being full.
//	std::cout<<"curr: "<<n_curr_stack<<" total: "<<n_stacks()<<std::endl;

	if( !(isStackAt(0)) ) {
		// If there is no stack we make one
		MyStack<T>* new_stack = new MyStack<T>();
		stack_count.push_back(0);
		stack_ptrs.push_back(new_stack);
		num_stacks = 1;
	} else if( isFullAt(n_curr_stack)) {
		MyStack<T>* new_stack = new MyStack<T>();
		++n_curr_stack;
		++num_stacks;
		stack_count.push_back(0);
		stack_ptrs.push_back(new_stack);	
	}
	// Then push onto the current stack
	pushAt(input, n_curr_stack);
	return;
}


template <typename T>
bool SetOfStacks<T>::isEmpty() {
	// If there is no initial stack
	if( !(isStackAt(0)) ) {
		return true;	
		// Or if the initial stack is empty then the set is empty.
	} else if( (n_curr_stack == 0) && (stack_ptrs[0]->isEmpty()) ) {
		return true;
	}
	return false;
}

template <typename T>
bool SetOfStacks<T>::isEmptyAt(size_t n) {
	if( !(isStackAt(n)) ) {
		throw std::out_of_range(std::to_string(n)
			       	+ " index stack does not exist."
				+ " There are only up to "
				+ std::to_string(n_curr_stack));
	} else if( stack_ptrs[n]->isEmpty() ) {
		return true;
	}
	return false;
}

template <typename T>
bool SetOfStacks<T>::isStackAt(size_t n) {
//	std::cout<<"is stack: "<<n<<std::endl;
	if( n >= n_stacks() ) {
		return false;
	} else if( stack_ptrs[n] == NULL ) {
		return false;
	}
	return true;
}

template <typename T>
bool SetOfStacks<T>::isFullAt(size_t n) {
//	std::cout<<"is full: "<<n<<std::endl;
	if( !(isStackAt(n)) ) {
		throw std::out_of_range(std::to_string(n)
			       	+ " index stack does not exist."
				+ " There are only up to "
				+ std::to_string(n_curr_stack));
	} else if( stack_count[n] ==  stack_max) {
		return true;
	}
	return false;
}

template <typename T>
size_t SetOfStacks<T>::n_stacks() {
	return num_stacks;
}

template <typename T>
void SetOfStacks<T>::print() {
	if( !(isStackAt(0)) ) {
		std::cout<<"No stacks yet."<<std::endl;
		return;
	}
	for( size_t n = 0; n<n_stacks(); ++n) {
		std::cout<<"Stack "<<n+1<<" of "<<n_stacks()<<": ";
		if( isEmptyAt(n) ) {
			std::cout<<"is empty";	
		} else {
			stack_ptrs[n]->print();
		}
		std::cout<<std::endl;
	}	
	return;
}

