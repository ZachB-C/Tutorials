// Here we build all our linked list funcitons and then we can have the 
// questions files make use of them, so we can have some functions that we 
// will need multiple times as well as the class definitions
#include <iostream>
#include "linkedlist.h"


// get rid of this after testing
int main() {
	// Creating the linked list object
	LinkedListSingle<int> list;

	// Inserting Nodes
	list.insertAtHead(4);	
	list.insertAtHead(3);
	list.insertAtHead(2);
	list.insertAtHead(1);

	std::cout<< "Elements of the list are: ";
	// Print the list
	list.print();
	std::cout<<std::endl;


	list.insertVectorAtHead({1,2,3,4,5,6,7,8,9,10});
	std::cout<< "Elements of the list are: ";
	// Print the list
	list.print();
	std::cout<<std::endl;

	list.deleteNode(2);
	std::cout<< "Elements of the list are: ";
	// Print the list
	list.print();
	std::cout<<std::endl;

	list.deleteNthNode(7);
	std::cout<< "Elements of the list are: ";
	// Print the list
	list.print();
	std::cout<<std::endl;

	NodeSingle<int>* node = list.accessNthNode(7);
	std::cout<<"7th: "<<node->data<<std::endl;

	LinkedListSingle<double> double_list;
	double_list.insertVectorAtHead({1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9});
	double_list.print();
	std::cout<<std::endl;


	return 0;
}
