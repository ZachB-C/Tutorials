// Here we build all our linked list funcitons and then we can have the 
// questions files make use of them, so we can have some functions that we 
// will need multiple times as well as the class definitions
#include <iostream>
#include "linkedlist.h"


// Class definitions
LinkedListSingle::LinkedListSingle(): head(NULL) {}
// Destructor
LinkedListSingle::~LinkedListSingle() {
	NodeSingle* current = head;
	NodeSingle* next = head;
	while( current != NULL ) {
		next = current->next;
		delete current;
		current = next;
	}
	head = NULL;
}
// Function to insert a node at beginning
// of linked list
void LinkedListSingle::insertAtHead(int data) {
	// Create a new node
	NodeSingle* newNode = new NodeSingle(data);
	// Assign to head of the list if empty
	if( head == NULL ) {
		head = newNode;
		return;
	}
	// Insert the newly created linked list at the head
	newNode->next = this->head;
	this->head = newNode;
}

void LinkedListSingle::insertVectorAtHead(std::vector<int> data_in) {
	for( size_t i = data_in.size(); i-- > 0; ) {
		insertAtHead(data_in[i]);
	}
}

void LinkedListSingle::deleteNode(int d) {
	NodeSingle* current = head;
	NodeSingle* next = head;

	// If the data is at head move head.
	if( current->data == d ) {
		head = current->next;
		delete current;
		return;
	}

	while( current->next != NULL ) {
		if( current->next->data == d ) {
			next = current->next;
			current->next = current->next->next;
			delete next;
			return;
		}
		current = current->next;
	}
	return;
}

// Zero indexed.
void LinkedListSingle::deleteNthNode(size_t n) {
	NodeSingle* current = head;
	NodeSingle* next = head;
	if( n == 0 ) {
		head = head->next;
		delete current;
		return;
	}
	// Careful of this we end up one before
	// the one we want to delete.	
	for( size_t i=1; i<n; ++i) {
		current = current->next;
	}	
	next = current->next;
	current->next = current->next->next;
	delete next;
	return;
}

// Zero indexed.
NodeSingle* LinkedListSingle::accessNthNode(size_t n) {
	NodeSingle* current = head;
	for( size_t i=0; i<n; ++i) {
		current = current->next;
	}	
	return current;
}	


// Function to print the linked list
void LinkedListSingle::print() {
	NodeSingle *temp = head;
	// Check for empty list
	if( head == NULL ) {
		std::cout<<"List empty" << std::endl;
		return;
	}
	// Traverse the list
	while( temp != NULL ) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
}

// Node constructor
NodeSingle::NodeSingle(int input_data): data(input_data), next(NULL) {}


// get rid of this after testing
//int main() {
//	// Creating the linked list object
//	LinkedListSingle list;
//
//	// Inserting Nodes
//	list.insertAtHead(4);	
//	list.insertAtHead(3);
//	list.insertAtHead(2);
//	list.insertAtHead(1);
//
//	std::cout<< "Elements of the list are: ";
//	// Print the list
//	list.print();
//	std::cout<<std::endl;
//
//
//	list.insertVectorAtHead({1,2,3,4,5,6,7,8,9,10});
//	std::cout<< "Elements of the list are: ";
//	// Print the list
//	list.print();
//	std::cout<<std::endl;
//
//	list.deleteNode(2);
//	std::cout<< "Elements of the list are: ";
//	// Print the list
//	list.print();
//	std::cout<<std::endl;
//
//	list.deleteNthNode(7);
//	std::cout<< "Elements of the list are: ";
//	// Print the list
//	list.print();
//	std::cout<<std::endl;
//
//	NodeSingle* node = list.accessNthNode(7);
//	std::cout<<"7th: "<<node->data<<std::endl;
//
//	return 0;
//}
