// Here we build all our linked list funcitons and then we can have the 
// questions files make use of them, so we can have some functions that we 
// will need multiple times as well as the class definitions
#include <iostream>
#include "linkedlist.h"


// get rid of this after testing
int main() {
	// Creating the linked list object
	LinkedList<int> list;

	// Inserting Nodes
	list.insertAtHead(4);	
	list.insertAtHead(3);
	list.insertAtHead(2);
	list.insertAtTail(1);

	std::cout<< "Elements of the list are: ";
	// Print the list
	list.print();
	std::cout<<std::endl;


	list.insertVectorAtHead({1,2,3,4,5,6,7,8,9,10});
	std::cout<< "Elements of the list are: ";
	// Print the list
	list.print();
	std::cout<<std::endl;

	list.removeNode(2);
	std::cout<< "Elements of the list are: ";
	// Print the list
	list.print();
	std::cout<<std::endl;

	list.removeNode(7);
	std::cout<< "Elements of the list are: ";
	// Print 
	list.print();
	std::cout<<std::endl;

	Node<int>* node = list.accessNode(7);
	std::cout<<"7th: "<<node->getData()<<std::endl;

	LinkedList<double> double_list;
	double_list.insertVectorAtHead({1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9});
	double_list.print();
	std::cout<<"pop Head: "<<double_list.popHead()<<std::endl;
	std::cout<<"pop Tail: "<<double_list.popTail()<<std::endl;
	Node<double>* node_double = double_list.nodeWith( 4.4);
	std::cout<<"Find 4.4: "<<node_double->getData()<<std::endl;
	std::cout<<"Node exists? "<<double_list.hasNode(node_double)<<std::endl;
	double_list.removeFromPointer(node_double);
	double_list.print();
	double_list.removeAllNodes();
	double_list.print();
	std::cout<<std::endl;


	return 0;
}
