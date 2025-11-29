// Define the stack and queue classes properly
#include <iostream>
#include "stackqueue.h"


// Do MyQueue Later should be quite simple.
//
//
//
//
//
//
// test
int main() {
	MyStack<int> stack;
	stack.print();
	std::cout<<", isEmpty(): "<<stack.isEmpty()<<std::endl;
	stack.push( 0);
	stack.print();
	std::cout<<", length = "<<stack.length()
		<<", isEmpty(): "<<stack.isEmpty()<<std::endl;
	stack.pushVector({1,2,3,4,5,6,7,8,9});
	stack.print();
	std::cout<<", length = "<<stack.length()<<std::endl;
	std::cout<<"Popped: "<<stack.pop()<<std::endl;
	stack.print();
	std::cout<<", length = "<<stack.length()<<std::endl;
	std::cout<<"Peek: "<<stack.peek()<<std::endl;
	stack.print();
	std::cout<<", length = "<<stack.length()<<std::endl;
	stack.~MyStack();
	stack.print();
	std::cout<<", length = "<<stack.length()<<std::endl;
	
	MyStack<double>* stack_ptr = new MyStack<double>();
	std::cout<<"n: "<<stack_ptr->length()<<std::endl;
	delete stack_ptr;

	return 0;

}
