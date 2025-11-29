// Here we build all our linked list funcitons and then we can have the 
// questions files make use of them, so we can have some functions that we 
// will need multiple times as well as the class definitions
#include <iostream>
#include "t_linkedlist.h"


// Class definitions
// Can default to int but won't do it to make sure it works.
template <typename T>
LinkedListSingle<T>::LinkedListSingle(): head(NULL) {}
// Destructor
template <typename T>
LinkedListSingle<T>::~LinkedListSingle() {
	NodeSingle<T>* current = head;
	NodeSingle<T>* next = head;
	while( current != NULL ) {
		next = current->next;
		delete current;
		current = next;
	}
	head = NULL;
}
// Function to insert a node at beginning
// of linked list

template <typename T>
void LinkedListSingle<T>::insertAtHead(T data) {
	// Create a new node
	NodeSingle<T>* newNode = new NodeSingle<T>(data);
	// Assign to head of the list if empty
	if( head == NULL ) {
		head = newNode;
		return;
	}
	// Insert the newly created linked list at the head
	newNode->next = this->head;
	this->head = newNode;
}

template <typename T>
void LinkedListSingle<T>::insertVectorAtHead(std::vector<T> data_in) {
	for( size_t i = data_in.size(); i-- > 0; ) {
		insertAtHead(data_in[i]);
	}
}

template <typename T>
void LinkedListSingle<T>::deleteNode(T d) {
	NodeSingle<T>* current = head;
	NodeSingle<T>* next = head;

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

template <typename T>
void LinkedListSingle<T>::deleteNthNode(size_t n) {
	NodeSingle<T>* current = head;
	NodeSingle<T>* next = head;
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

template <typename T>
NodeSingle<T>* LinkedListSingle<T>::accessNthNode(size_t n) {
	NodeSingle<T>* current = head;
	for( size_t i=0; i<n; ++i) {
		current = current->next;
	}	
	return current;
}	


// Function to print the linked list
// Must make sure the data type is compatible with <<
template <typename T>
void LinkedListSingle<T>::print() {
	NodeSingle<T> *temp = head;
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

template <typename T>
NodeSingle<T>::NodeSingle(T input_data): data(input_data), next(NULL) {}


// get rid of this after testing
//int main() {
//	// Creating the linked list object
//	LinkedListSingle<int> list;
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
//	NodeSingle<int>* node = list.accessNthNode(7);
//	std::cout<<"7th: "<<node->data<<std::endl;
//
//	LinkedListSingle<double> double_list;
//	double_list.insertVectorAtHead({1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9});
//	double_list.print();
//	std::cout<<std::endl;
//
//
//	return 0;
//}
