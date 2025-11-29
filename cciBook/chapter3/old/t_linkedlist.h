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

// Define classes
//template <typename T = int> // This gives default type.
template <typename T>
class NodeSingle {
	public:
		T data;
		NodeSingle<T>* next;
		// Constructor
		NodeSingle(T input_data=0);

};
class NodeDouble {};

template <typename T>
class LinkedListSingle {

	public:
		NodeSingle<T>* head;
		// Default constructor
		LinkedListSingle();
		// Destructor
		~LinkedListSingle();
		// Function to insert node at beginning of linked list
		void insertAtHead(T Data);
		void insertVectorAtHead(std::vector<T> data_in);
		void deleteNode(T d);
		void deleteNthNode(size_t n);
		NodeSingle<T>* accessNthNode(size_t n);
//		void deleteAllNodes();
		// Function to print linked list
		void print();
};
class LinkedListDouble {};
#endif
