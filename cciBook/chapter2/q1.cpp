// We must remove duplicates from an unsorted list. Extension is to do it
// without a buffer. At first I will do it with a buffer, I need to record
// all duplicates and then remove them, there could be loads though so 
// do I have to go through N^2 times that is a lot, and look for each value
// one at a time? That could be the non-buffer version. But there must be 
// a faster version if we can use a buffer. I will assume in all this that 
// this is a singly linked list else it would make it easier.
#include <iostream>
#include <unordered_map>
#include "linkedlist.h"

void deleteRepeats( LinkedListSingle& list );
void deleteRepeatsHash( LinkedListSingle& list );
// Ideally we should do some more checks.
int main() {
	LinkedListSingle list;
	list.insertVectorAtHead({1,2,3,2,5,6,2,2,2,7,9,5});
	std::cout<<"Original: "<<std::endl;
	list.print();
	std::cout<<std::endl;
	deleteRepeatsHash(list);
	std::cout<<"Repeats deleted: "<<std::endl;
	list.print();
	std::cout<<std::endl;


	list.insertVectorAtHead({1,2,3,2,5,6,7,2,9,5,17});
	std::cout<<"Original: "<<std::endl;
	list.print();
	std::cout<<std::endl;
	deleteRepeatsHash(list);
	std::cout<<"Repeats deleted: "<<std::endl;
	list.print();
	std::cout<<std::endl;


	return 0;
}
// Do a quick N^2 version then see if we can do better.
// The idea is to take each node one at a time and search all the other
// nodes to see if there are any repeats.
void deleteRepeats( LinkedListSingle& list) {
	// Early node is the node we try to match with
	NodeSingle* early_node = list.head;
	// Late node is the one before the one we might want to delete.
	NodeSingle* late_node = early_node;
	NodeSingle* temp_node;
//	std::cout<<"Stage 1"<<std::endl;
	// If the list is empty there will be no repeats so no changes needed
	if( early_node == NULL ) {
		return;
	}
//	std::cout<<"Stage 2"<<std::endl;
	// Whenever there are no more nodes then the early node can stop.
//	int i = 0;
//	int j = 0;
	while( early_node->next != NULL ) {
		// For each node we cycle until the end
//		std::cout<<"Count I: "<<++i<<" e = "<<early_node->data
//			<<std::endl;
//		j = 0;
//		list.print();
//		std::cout<<std::endl;
		while(late_node->next != NULL) {
//			std::cout<<"Count J: "<<++j<<" l = "<<late_node->data
//				<<std::endl;
			// If we find a match delete that piece of data.
			if( early_node->data == late_node->next->data ) {
				temp_node = late_node->next;
				late_node->next = late_node->next->next;
				delete temp_node;
			} else {
				// If we did not delete anything then increment
				// our late node to check the next element,
				// If we did find something we don't
				// increment because our current next node
				// is what we will check.
				late_node = late_node->next;
			}
//			std::cout<<" stop "<<std::endl;
			// Cycle to check the next element
			// I don't like having this check here and in 
			// the while loop it seems too much
			// We should really alter the while loop maybe?
		}	
		// Once we have checked for copies of the first node 
		// we move to the next node.
		early_node = early_node->next;
		late_node = early_node;	
	}	
//	std::cout<<"Stage 3"<<std::endl;
}

// Okay so that one was N^2 but didn't use a buffer, I don't think, maybe I can
// do it in N (one pass) if I use a hash table
void deleteRepeatsHash( LinkedListSingle& list ) {
	NodeSingle *current_node = list.head;
	NodeSingle *next_node;
	std::unordered_map<int, bool> int_present;
	// No repeats if nothing there
	if( current_node == NULL ) {
		return;
	}
	// Add the data in the first node to our hash table
	int_present[current_node->data] = true;
	// Then add the data from all subsequent nodes and if we get a
	// repeat
	while(current_node->next != NULL ) {
//		std::cout<<" Current: "<<current_node->data<<std::endl;
		// If we have already seen this data before then delete it.
		next_node = current_node->next;
//		std::cout<<" Next: "<<next_node->data<<std::endl;
//		for( auto elem : int_present ) {
//			std::cout<<elem.first<<": "<<elem.second<<std::endl;
//		}
		if( int_present.count(next_node->data) > 0 ) {
			// If it is present we delete it
			current_node->next = next_node->next;
			delete next_node;
		} else {
			// Otherwise we note the new integer
			int_present[current_node->next->data] = true;
			// and increment to the next node
			current_node = current_node->next;
		}
	}



}
