// This is the helper file for the linked list programs, it defines the linked
// list class so that we can use it. Have two definitions, single and 
// double linked list.
// If we have not included this helper file before then 
// include it now.
// Can we define a default constructor here and non-default in cpp file.
#ifndef LINKEDLIST_H
// Define to prevent multiple inclusions
#define LINKEDLIST_H

#include <vector>
#include <iostream>
#include <exception>
//
///
///
///
///
///
/// Node Single
///
///
///
///
///
//
//

// Define classes
//template <typename T = int> // This gives default type.
template <typename T>
class Node {
	T data;
	public:
		Node<T>* next;
		// Constructor
		Node(T input_data=0);
		const T getData() const;
		T getData();
		void print();

};

template <typename T>
Node<T>::Node(T input_data): data(input_data), next(NULL) {}

template <typename T>
const T Node<T>::getData() const { return data;}

template <typename T>
T Node<T>::getData() { return data;}


template <typename T>
void Node<T>::print() {
	std::cout<<data;
}

///
///
///
///
///
/// NodeDouble
///
///
///
///
///
///
///

class NodeDouble {};

//
///
///
///
///
/// LinkedListSingle
///
///
///
///
///
///
///
//



template <typename T>
class LinkedList {
	Node<T>* tail;	
	Node<T>* head;
	size_t n_elements;

	public:
		// Default constructor
		LinkedList();
		// Destructor
		~LinkedList();
		T peekHead();
		T peekTail();
		T popHead();
		T popTail();
		// Function to insert node at beginning of linked list
		void insertAtHead(T data);
		void insertAtTail(T data);
		void insertVectorAtHead(std::vector<T> data_in);
		void insertVectorAtTail(std::vector<T> data_in);
		void removeFromHead();
		void removeFromTail();
		void removeFromPointer(Node<T>* pointer);
		void removeNode(size_t n);
		Node<T>* accessNode(size_t n);
		void removeAllNodes();
		Node<T>* nodeWith(T target); // A search method looks for
					     // object and returns first 
					     // node with it in. 
					     // Assumes unsorted. Returns NULL
					     // if not found.
		// Function to print linked lista
		bool isEmpty();
		bool hasNode(Node<T>* pointer);
		void print();
		size_t length();
};

template <typename T>
LinkedList<T>::LinkedList() : 
	tail(NULL), 
	head(NULL), 
	n_elements(0) {}

template <typename T>
void LinkedList<T>::removeAllNodes() {
	while( head != NULL ) {
		removeFromHead();
	}
}

template <typename T>
LinkedList<T>::~LinkedList() {
	removeAllNodes();
}

template <typename T>
T LinkedList<T>::peekTail() {
	if( isEmpty()) {
		throw std::out_of_range("The list is empty.");
	}
	return tail->getData();
}


template <typename T>
T LinkedList<T>::peekHead() {
	if( isEmpty()) {
		throw std::out_of_range("The list is empty.");
	}
	return head->getData();
}

template <typename T>
T LinkedList<T>::popHead() {
	T output = peekHead();
	removeFromHead();
	return output;
}

template <typename T>
T LinkedList<T>::popTail() {
	T output = peekTail();
	removeFromTail();
	return output;
}

template <typename T>
void LinkedList<T>::insertAtHead(T data) {
	Node<T>* new_node = new Node<T>(data);
	if( head == NULL ) {
		head = new_node;
		tail = new_node;
	} else {
		new_node->next = head;
		head = new_node;
	}
	++n_elements;
	return;
}


template <typename T>
void LinkedList<T>::insertAtTail(T data) {
	Node<T>* new_node = new Node<T>(data);
	if( tail == NULL ) {
		head = new_node;
		tail = new_node;
	} else {
		tail->next = new_node;
		tail = new_node;
	}
	++n_elements;
	return;
}


template <typename T>
void LinkedList<T>::insertVectorAtHead(std::vector<T> data_in ) {

	for( auto datum = data_in.rbegin(); datum != data_in.rend(); datum++ ) {
		insertAtHead(*datum);
	}
	return;

}

template <typename T>
void LinkedList<T>::insertVectorAtTail(std::vector<T> data_in ) {
	for( auto datum : data_in ) {
		insertAtTail(datum);
	}
	return;
}


template <typename T>
void LinkedList<T>::removeFromHead() {
	if( isEmpty() ) {
		throw std::out_of_range("No data to remove.");
	}
	Node<T>* current = head;
	if( head == tail ) {
		head = NULL;
		tail = NULL;
		delete current;
		--n_elements;
		return;
	}
	head = current->next;
	delete current;
	--n_elements;
	if( head == NULL ) {
		tail = NULL;
	}
	return;
}

template <typename T>
bool LinkedList<T>::hasNode(Node<T>* pointer) {
	if( isEmpty() ) {
		throw std::out_of_range("No Nodes in list.");
	}
	Node<T>* current = head;
	while( current != NULL ) {
		if( current == pointer ) {
			return true;
		}
		current = current->next;
	}
	// If we do not find the pointer
	return false;
}



// Do remove FromPointer like tail but look for pointer and also do search by
// pointer.
template <typename T>
void LinkedList<T>::removeFromPointer(Node<T>* pointer) {
	if( isEmpty() ) {
		throw std::out_of_range("No data to remove.");
	}
	if( pointer == head ) {
		removeFromHead();
		return;
	} else if( pointer == tail ) {
		removeFromTail();
		return;
	}
	Node<T>* current = head;
	while( current->next != NULL ) {
		if( current->next == pointer ) {
			current->next = current->next->next;
			delete pointer;
			--n_elements;
			return;
		}
		current = current->next;
	}
	// If we do not find the pointer
	throw std::logic_error("The target pointer does not exist.");
}

// Remove from tail is not recommended as it 
// requires traversing through the whole list.
template <typename T>
void LinkedList<T>::removeFromTail() {
	if( isEmpty() ) {
		throw std::out_of_range("No data to remove.");
	}
	Node<T>* current = head;
	if( head == tail ) {
		head = NULL;
		tail = NULL;
		delete current;
		--n_elements;
		return;
	}

	while( current->next != tail ) {
		current = current->next;
	}
	current->next = NULL;
	delete tail;
	tail = current;
	--n_elements;
	return;
}


template <typename T>
void LinkedList<T>::removeNode(size_t n) {
	Node<T>* current = head;
	if( n == 0 ) {
		removeFromHead();
		return;
	} 
	for( size_t i = 0; i<n-1; ++i ) {
		current = current->next;
	}
	Node<T>* next = current->next;
	current->next = next->next;
	delete next;
	--n_elements;
	return;
}

template <typename T>
Node<T>* LinkedList<T>::accessNode(size_t n) {
	if( n_elements <= n ) {
		throw std::out_of_range(std::to_string(n) 
				+ "th element does not exist.");
	}
	Node<T>* current = head;
	if( n == 0 ) {
		return head;
	} 
	for( size_t i = 0; i<n; ++i ) {
		current = current->next;
	}
	return current;
}

template <typename T>
Node<T>* LinkedList<T>::nodeWith(T target) {
	Node<T>* current = head;
	while( current != NULL ) {
		if( current->getData() == target) {
			return current;
		} else {
			current = current->next;
		}
	}
	return NULL;
}

template< typename T>
bool LinkedList<T>::isEmpty() {
	if( head == NULL ) {
		if( tail != NULL || n_elements != 0 ) {
			throw std::logic_error("Not sure if list is "
					 "empty or not");
		}
		return true;
	}
	return false;
}


template< typename T>
void LinkedList<T>::print() {
	if( isEmpty() ) {
		std::cout<<"List is empty."<<std::endl;
	}
	Node<T>* current = head;
	std::cout<<" List: ";
	while( current != NULL ) {
		current->print();
		std::cout<<"\t";
		current = current->next;
	}
	std::cout<<std::endl;
	return;
}

template <typename T>
size_t LinkedList<T>::length() {
	return n_elements;
}
///
///
///
///
///
///
///  LinkedListDouble
///
///
///
///
///
///
///
///
///
class LinkedListDouble {};
#endif
