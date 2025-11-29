// Stack sorter: need to sort a stack so smallest values at the top. Can use
// a temporary stack to do so. Stack has pop, peek, push, and isEmpty.
// So I guess we allow our selves one temporary variable we take off the first 
// element and compare it to the next if the next is larger we put it in the 
// stack if the next is smaller we put our current value in the stack
// So we pop one off the stack if it is smaller than what is on our temp stack
// we put the temp stack back until it is bigger then add it to the temp stack.
// Then we do the same for each element on the original stack, each time we
// find a bigger item we remove it and load things back on the main stack, when
// we finish we load everything back on the main stack.

#include <iostream>
#include "stackqueue.h"

// Header functions
template <typename T>
void stackSorter(MyStack<T>& stack);


int main() {
	MyStack<int> stack;
	stack.pushVector({9,1,2,3,7,6,8,4,3,9,0});
	std::cout<<"Initial stack: ";
	stack.print();

	std::cout<<std::endl<<"Sorted stack: ";
	stackSorter<int>(stack);
	stack.print();
	std::cout<<std::endl;

	return 0;
}


template <typename T>
void stackSorter(MyStack<T>& stack) {
	MyStack<T> temp_stack;
	T data;
	// Keep going until we have emptied 
	// the main stack then we load everything back again.
	while( !(stack.isEmpty()) ) {
		data = stack.pop();
		// We start offloading our temp_stack until we find a 
		// place that the data can slot it or we reach the end of
		// the temp stack
		while( !(temp_stack.isEmpty()) ) {
			// If data is less it means it should go lower on 
			// temp_stack and higher on stack.
			if( data < temp_stack.peek() ) {
				stack.push(( temp_stack.pop() ));
			} else {
				// Stop when data is no longer smaller
				break;
			}
		}
		// Now we work through again, this means we have to put
		// everything we just took off back on.
		temp_stack.push(data);
	}
	// Now we need to put everything back in the original stack as it is 
	// now empty. We could save one go by looking ahead and if the main 
	// stack is empty when we take our data out then as soon as we find a 
	// place for our data we can quit and put the rest of temp onto the main
	// stack
	while( !(temp_stack.isEmpty()) ) {
		stack.push(( temp_stack.pop() ));
	}


	return;
}


