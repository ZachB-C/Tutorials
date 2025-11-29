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
	std::cout<<"Stack: "<<std::endl;
	Stack<int> stack;
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
	stack.print();
	stack.push(21);
	std::cout<<"Push: "<<21<<std::endl;
	std::cout<<", length = "<<stack.length()<<std::endl;
	stack.print();

	std::cout<<", length = "<<stack.length()<<std::endl;
	
	Stack<double>* stack_ptr = new Stack<double>();
	std::cout<<"n: "<<stack_ptr->length()<<std::endl;
	stack_ptr->print();
	delete stack_ptr;

	std::cout<<"Queue: "<<std::endl;
	Queue<int> queue;
	queue.print();
	std::cout<<", isEmpty(): "<<queue.isEmpty()<<std::endl;
	queue.add( 0);
	queue.print();
	std::cout<<", length = "<<queue.length()
		<<", isEmpty(): "<<queue.isEmpty()<<std::endl;
	queue.addVector({1,2,3,4,5,6,7,8,9});
	queue.print();
	std::cout<<", length = "<<queue.length()<<std::endl;
	std::cout<<"Popped: "<<queue.remove()<<std::endl;
	queue.print();
	std::cout<<", length = "<<queue.length()<<std::endl;
	std::cout<<"Peek: "<<queue.peek()<<std::endl;
	std::cout<<", length = "<<queue.length()<<std::endl;
	queue.print();
	queue.add(21);
	std::cout<<"Push: "<<21<<std::endl;
	std::cout<<", length = "<<queue.length()<<std::endl;
	queue.print();

	std::cout<<", length = "<<queue.length()<<std::endl;
	
	Queue<double>* queue_ptr = new Queue<double>();
	std::cout<<"n: "<<queue_ptr->length()<<std::endl;
	queue_ptr->print();
	delete queue_ptr;


	return 0;

}
