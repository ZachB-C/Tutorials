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
void stackSorter(MyStack<T>& stack) {


int main() {
	MyStack<int> stack;
	stack.pushVector(

}


templare <typename T>
void stackSorter(MyStack<T>& stack) {
	MyStack<T> temp_stack;




	return;
}


