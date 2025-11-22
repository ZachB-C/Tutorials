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
class NodeSingle {
	public:
		int data;
		NodeSingle* next;
		// Constructor
		NodeSingle(int input_data=0);

};
class NodeDouble {};

class LinkedListSingle {

	public:
		NodeSingle* head;
		// Default constructor
		LinkedListSingle();
		// Destructor
		~LinkedListSingle();
		// Function to insert node at beginning of linked list
		void insertAtHead(int Data);
		void insertVectorAtHead(std::vector<int> data_in);
		void deleteNode(int d);
		void deleteNthNode(size_t n);
		NodeSingle* accessNthNode(size_t n);
//		void deleteAllNodes();
		// Function to print linked list
		void print();
};
class LinkedListDouble {};
#endif
