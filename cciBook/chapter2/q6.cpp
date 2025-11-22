// We must check if a linked list is a palindrome. So we could find the pair
// of each letter, but that is pretty heavy going and would be N^2 so instead
// we will use O(N) memory and load the first half onto a different 
// array, we can do the by moving double speed through it with one pointer and
// offloading at single speed and then once we have done this offloading N time
// we then work through from the beginning of the offloaded list and current 
// position of the slow pointer. 
#include <iostream>
#include "linkedlist.h"

// Header functions
bool isPallindrome(LinkedListSingle const& list);
// Not sure how to use constants here, I want to say that start_node
// cannot be changed and the thing it points at can't be changed
// end_node can be changed but the things it points to can't be changed.
bool isPallindromeRecursive( 
		NodeSingle * start_node, 
		size_t list_length, NodeSingle ** end_node_ptr);
// We will use integer pallindromes as I haven't got a template for using 
// different inputs, that will maybe go
int main() {
	LinkedListSingle list;
	NodeSingle* end_node;
	NodeSingle** end_node_ptr;
	
	list.insertVectorAtHead({1,2,3,4,5,4,3,2,1});
	end_node = list.head;
	end_node_ptr = &end_node;
	std::cout<<"List: "<<std::endl;
	list.print();
	std::cout<<" is a pallindrome? "<<isPallindrome(list)<<std::endl;
	std::cout<<" is a pallindrome? "
		<<isPallindromeRecursive(list.head, 9, end_node_ptr)<<std::endl;
	if(*end_node_ptr != NULL) {
		std::cout<<" End data: "<<(*end_node_ptr)->data<<std::endl;
	}

	list.~LinkedListSingle();
	list.insertVectorAtHead({1});
	end_node = list.head;
	end_node_ptr = &end_node;
	std::cout<<"List: "<<std::endl;
	list.print();
	std::cout<<" is a pallindrome? "<<isPallindrome(list)<<std::endl;
	std::cout<<" is a pallindrome? "
		<<isPallindromeRecursive(list.head, 1, end_node_ptr)<<std::endl;
	if(*end_node_ptr != NULL) {
		std::cout<<" End data: "<<(*end_node_ptr)->data<<std::endl;
	}

	list.~LinkedListSingle();
	list.insertVectorAtHead({1,2,3,4,3,7,1});
	end_node = list.head;
	end_node_ptr = &end_node;
	std::cout<<"List: "<<std::endl;
	list.print();
	std::cout<<" is a pallindrome? "<<isPallindrome(list)<<std::endl;
	std::cout<<" is a pallindrome? "
		<<isPallindromeRecursive(list.head, 7, end_node_ptr)<<std::endl;
	if(*end_node_ptr != NULL) {
		std::cout<<" End data: "<<(*end_node_ptr)->data<<std::endl;
	}



	list.~LinkedListSingle();
	list.insertVectorAtHead({1,2,3,4,3,2,1});
	end_node = list.head;
	end_node_ptr = &end_node;
	std::cout<<"List: "<<std::endl;
	list.print();
	std::cout<<" is a pallindrome? "<<isPallindrome(list)<<std::endl;
	std::cout<<" is a pallindrome? "
		<<isPallindromeRecursive(list.head, 7, end_node_ptr)<<std::endl;
	if(*end_node_ptr != NULL) {
		std::cout<<" End data: "<<(*end_node_ptr)->data<<std::endl;
	}


	list.~LinkedListSingle();
	list.insertVectorAtHead({1,2,3,4,3,2,9});
	end_node = list.head;
	end_node_ptr = &end_node;
	std::cout<<"List: "<<std::endl;
	list.print();
	std::cout<<" is a pallindrome? "<<isPallindrome(list)<<std::endl;
	std::cout<<" is a pallindrome? "
		<<isPallindromeRecursive(list.head, 7, end_node_ptr)<<std::endl;
	if(*end_node_ptr != NULL) {
		std::cout<<" End data: "<<(*end_node_ptr)->data<<std::endl;
	}

	list.~LinkedListSingle();
	list.insertVectorAtHead({9,2,3,4,3,2,1});
	end_node = list.head;
	end_node_ptr = &end_node;
	std::cout<<"List: "<<std::endl;
	list.print();
	std::cout<<" is a pallindrome? "<<isPallindrome(list)<<std::endl;
	std::cout<<" is a pallindrome? "
		<<isPallindromeRecursive(list.head, 7, end_node_ptr)<<std::endl;
	if(*end_node_ptr != NULL) {
		std::cout<<" End data: "<<(*end_node_ptr)->data<<std::endl;
	}

	list.~LinkedListSingle();
	list.insertVectorAtHead({1,8,3,4,3,2,1});
	end_node = list.head;
	end_node_ptr = &end_node;
	std::cout<<"List: "<<std::endl;
	list.print();
	std::cout<<" is a pallindrome? "<<isPallindrome(list)<<std::endl;
	std::cout<<" is a pallindrome? "
		<<isPallindromeRecursive(list.head, 7, end_node_ptr)<<std::endl;
	if(*end_node_ptr != NULL) {
		std::cout<<" End data: "<<(*end_node_ptr)->data<<std::endl;
	}



	list.~LinkedListSingle();
	list.insertVectorAtHead({1,2,3,4,7,2,1});
	end_node = list.head;
	end_node_ptr = &end_node;
	std::cout<<"List: "<<std::endl;
	list.print();
	std::cout<<" is a pallindrome? "<<isPallindrome(list)<<std::endl;
	std::cout<<" is a pallindrome? "
		<<isPallindromeRecursive(list.head, 7, end_node_ptr)<<std::endl;
	if(*end_node_ptr != NULL) {
		std::cout<<" End data: "<<(*end_node_ptr)->data<<std::endl;
	}


	return 0;

}

bool isPallindrome(const LinkedListSingle& list) {
	NodeSingle* fast_node = list.head;
	// An empty list is assumed symmetrical
	// deal with this and a list with one element just in case
	// but we can check if the main code handles it
	if(fast_node == NULL ) {
		return true;
	}// else if(fast_node->next == NULL ) {
	//	return true;
	//}
	NodeSingle* slow_node = fast_node;
	LinkedListSingle half_list;
	NodeSingle* half_node = NULL;
	// First offload half of the pallindrome
	while( fast_node != NULL ) {
		// Add a mew node to the half_list
		half_list.head = new NodeSingle(0);
		half_list.head->next = half_node;
		half_node = half_list.head;
		// Copy the current position of the slow node
		// We could move this bit so we don't put on the
		// middle value but it won't make much difference
		half_node->data = slow_node->data;
		slow_node = slow_node->next;
		// Progress the fast node, it goes twice the speed.
		// If the next node is NULL we are at the end of the
		// list. This means we have an odd number of nodes.
		if( fast_node->next == NULL ) {
			// With an odd number of nodes our half node 
			// should start the comparison on the second node
			half_node = half_node->next;
			// i.e. we should skip the middle node
			// Now leave the loop as we cannot increment fast twice
			break;
		}
		fast_node = fast_node->next->next;
	}
	// Now compare the offloaded half to the remaining half
	while( slow_node != NULL ) {
		if( slow_node->data != half_node->data ) {
			return false;
		}
		slow_node = slow_node->next;
		half_node = half_node->next;
	}
	return true;
	// Obviously this would be trivial if we had a doubly linked list.
	// Maybe they want us to use doubly linked list for these, but they 
	// don't specify. In that case we can get rid of half node and just 
	// send one to the end of the list and keep one at the beginning and 
	// simply compare them to each other.


}

// Here the idea is that the function checks a section of length list_length
// to see if it is a palindrome, if it is it returns the end of the list
// if not it returns NULL, would be nice to return bool but then I 
// would have to run to the end of the string myself, which is a hassle.
// Node is start node and nextNode is the node after the end of the 
// region checked. Start node marks the start of the pallindrome check
// and at the end endNode will make the end of the pallindrome.
// If it is a pallindrome at otherwise it will be the last section that was a 
// pallindrome, from the middle
// end_node marks the first node that is not part of the pallindrome.
bool isPallindromeRecursive(
		NodeSingle* start_node, // Can't change the what 
						     // the pointer points to
						     // or the value of what
						     // it points to.
		size_t list_length, 
		NodeSingle ** end_node_ptr
	       	// Not sure if this will work endNode
		     // is a pointer to a Node, so the idea
		     // is I want to change this to point
		     // to somewhere else.
		) {
	
	// Empty strings will be considered to be pallindromes.
	if(start_node == NULL ) { return true; }
	// All zero or 1 length strings are palindromes.
//	std::cout<<"Step 2"<<std::endl;
	if( list_length == 0 ) {
		*end_node_ptr = start_node;
		return true;
	} else if( list_length == 1) {
//		std::cout<<"Step 2B"<<start_node->data<<std::endl;
		
		*end_node_ptr = start_node->next;
		return true;
	}
//	std::cout<<"Step 3A"<<std::endl;
//	std::cout<<"Step 3"<<" Data "<<(*end_node_ptr)->data<<std::endl;
	if( isPallindromeRecursive( 
				start_node->next, list_length - 2, 
				end_node_ptr
				) )
	{
//		std::cout<<"Step 4"<<(*end_node_ptr)->data<<std::endl;
		// Separate ifs as we need the first to change
		// end_node before we access it
		if(  start_node->data == (*end_node_ptr)->data ) {
		// If the start node and the end node are the same
		// it is a pallindrome (or at least this part of it is.
		// So we increment end_node to the next position that may
		// not be a pallindrome.

//			std::cout<<"Step 5"<<std::endl;
			*end_node_ptr = (*end_node_ptr)->next;
			return true;
		}

	}
//	std::cout<<"Step 6"<<std::endl;
	// If the sub-section is not a pallindrome or 
	return false;

}




