// Loop detection, when given a string with a loop, a latter node points
// to an early one return a pointer to the start of the cycle. I.e. the earliest
// node one encounters that is part of the loop. We could do it with a 
// hash table just follow the loop until we find the same pointer again.
// 
#include <iostream>
#include <unordered_map>
#include "linkedlist.h"

// Header functions
NodeSingle* loopFinder( LinkedListSingle const & list);
void loopFixer( LinkedListSingle& list);

int main() {
	LinkedListSingle list;
	NodeSingle* end_pointer;
	NodeSingle* loop_start;

	list.insertVectorAtHead({0,1,2,3,4,5,6,7,8,9});
	loop_start = list.accessNthNode(0);
	end_pointer = list.head;
	while( end_pointer->next != NULL ) {
		end_pointer = end_pointer->next;
	}
	// Make loop
	end_pointer->next = loop_start;
	std::cout<<"Loop start: "<<loop_start->data<< std::endl;
	if( loopFinder(list) == NULL ) {
		std::cout<<"No loop."<<std::endl;
	} else {
		std::cout<<"Loop start found: "
			<<loopFinder(list)->data<<std::endl;
		// Fix the loop
		loopFixer(list);
		if( end_pointer->next == NULL ) {
			std::cout<<"Success"<<std::endl;
		} else {
			std::cout<<"Failure"<<std::endl;
		}
	}
	// Shouldn't be a memory error if the loop is fixed.

	return 0;
}

// The idea is to use a hash table and keep going until we find a repeat
NodeSingle* loopFinder( LinkedListSingle const& list) {
	NodeSingle* node = list.head;
	// Bool might be more efficient but then I would have to do some 
	// checks
	std::unordered_map<NodeSingle*, int> pointer_counter;
//	std::cout<<"Step 1"<<std::endl;
	while( node != NULL ) {
		// We add one to each, if we find more than 
		// one of a node than we return a reference to that node.
//		std::cout<<"Step 2: "<<node->data<<std::endl;
		if( ++pointer_counter[node] > 1 ) {
			break;
		}
		node = node->next;
	}
	// If there are no loops we return NULL
	return node;
}
// Similar to Node finder but we search one ahead for the repeat and then 
// we know where we can cut the loop without any problems.
void loopFixer( LinkedListSingle& list) {
	NodeSingle* node = list.head;
	// Bool might be more efficient but then I would have to do some 
	// checks
	std::unordered_map<NodeSingle*, int> pointer_counter;
	// We need to add in the first element to the string in case that
	// is the start of the loop, because we skip it.
	++pointer_counter[node];
	while( node != NULL ) {
		// We add one to each, if we find more than 
		// one of a node than we return a reference to that node.
//		std::cout<<node<<std::endl;
//		std::cout<<"Node : "<<node->data<<std::endl;
//		std::cout<<node->next<<std::endl;
//		std::cout<<"Next : "<<node->next->data<<std::endl;
		if( ++pointer_counter[node->next] > 1 ) {
//			std::cout<<node<<std::endl;
//			std::cout<<node->next<<std::endl;
			node->next = NULL;
			break;
		}
		node = node->next;
	}
	// If there are no loops we return NULL
	return;
}


//NodeSingle* findLoopRunners(LinkedList& const list) {
//	NodeSingle* slow = list.head;
//	NodeSingle* fast = list.head;
//

//

//}

