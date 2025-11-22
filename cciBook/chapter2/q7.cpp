// Determine if two linked lists are intersecting, i.e. if they share any 
// nodes.Then return the first shared node.
// That could be problematic for the final cleanup I will have to test 
// that, what happens to the other reference to a deleted node, probably that
// causes problems, I may need to clean up manually or implement a better
// type of linked list. The idea would be to cycle through each element of 
// each list and see if any are the same. N^2 worse case. Not sure how it could
// be done faster. Could do it recursively: do these two intersect, if so 
// return intersection point if not return NULL; Then if not NULL check current
// for intersection and if not return the previous value. We need two paths
// if we reach the end of one then we should wait there and keep incrementing 
// the other. Check if next is NULL for either and if it is for both return NULL// if it is then return. We could add an extra output that just breaks as soon 
// as it no longer matches, that would speed it up but not in terms of order.
#include <iostream>
#include "linkedlist.h"

// Header functions
NodeSingle* intersectionPoint( 
		 LinkedListSingle const& list1, LinkedListSingle const& list2);
NodeSingle* intersectionPointRecursive( 
		NodeSingle* node1, NodeSingle* node2, 
		size_t length1, size_t length2);

int main() {
	LinkedListSingle list1;
	LinkedListSingle list2;
	NodeSingle* node1_ptr;
	NodeSingle* node2_ptr;
	NodeSingle* node_match_ptr;

	list1.insertVectorAtHead({0,1,2,3,4,5,6,7,8,9,10});
	list2.insertVectorAtHead({11,12,13,14,15,16,17});
	// Now link the lists together
	node1_ptr = list1.accessNthNode(5);
	node2_ptr = list2.accessNthNode(6);
	std::cout<<"Intersection: "<<node1_ptr->data
		<<", Final 2 node : "<<node2_ptr->data<<std::endl;
       	node2_ptr->next = node1_ptr;
	node_match_ptr = intersectionPoint(list1, list2);
	std::cout<<"Intersection Found: "<<node_match_ptr->data<<std::endl;
	// Here there is a bit of a problem with the fact the two share an
	// address so we need to first untangle them
	node2_ptr->next = NULL;
	// That should do it.
	node_match_ptr = intersectionPoint(list1, list2);
	if( node_match_ptr == NULL ) {
		std::cout<<"Success"<<std::endl;
	} else {
		std::cout<<"Failure"<<std::endl;
	}

	list1.~LinkedListSingle();
	list2.~LinkedListSingle();
	list1.insertVectorAtHead({});
	list2.insertVectorAtHead({});	
	node_match_ptr = intersectionPoint(list1, list2);
	if( node_match_ptr == NULL ) {
		std::cout<<"Success 1"<<std::endl;
	} else {
		std::cout<<"Failure 1"<<std::endl;
	}

	list1.insertVectorAtHead({1});
	list2.insertVectorAtHead({});	
	node_match_ptr = intersectionPoint(list1, list2);
	if( node_match_ptr == NULL ) {
		std::cout<<"Success 2"<<std::endl;
	} else {
		std::cout<<"Failure 2"<<std::endl;
	}

		
	list1.insertVectorAtHead({});
	list2.insertVectorAtHead({1});	
	node_match_ptr = intersectionPoint(list1, list2);
	if( node_match_ptr == NULL ) {
		std::cout<<"Success 3"<<std::endl;
	} else {
		std::cout<<"Failure 3"<<std::endl;
	}

	list1.insertVectorAtHead({3,6,7,8});
	list2.insertVectorAtHead({99,98,97,96,95});	
	node1_ptr = list1.accessNthNode(4);
	node2_ptr = list2.accessNthNode(1);
	std::cout<<"Intersection: "<<node2_ptr->data
		<<", Final 1 node : "<<node1_ptr->data<<std::endl;
 	node1_ptr->next = node2_ptr;
	node_match_ptr = intersectionPoint(list1, list2);
	std::cout<<"Intersection Found: "<<node_match_ptr->data<<std::endl;
	// Here there is a bit of a problem with the fact the two share an
	// address so we need to first untangle them
	node1_ptr->next = NULL;
	// That should do it.
	return 0;


}

// Design a recursion so we compare the current pointers, 
// if they are the same we return them if not we look forward 
// and compare the next two. 
// If one gets to the end we stop iterating it and just do the other. 
// Then we move back up the stack. No that would work for an iterator
// but not for this if we get to the end of one then the only thing it
// can match is the end of the other so the next step should be to compare
// to the last element of the other.
// This version will not work for lists of different lengths 
// if we knew the lengths we could do it.
NodeSingle* intersectionPointRecursive(
		NodeSingle* node1, 
		NodeSingle* node2,
		size_t length1, size_t length2
		) {
	// If they match then we are finished here
	if(node1 == node2) {
		return node1;
	}
	NodeSingle* node_point = node2;
	if( length1 < length2 ) {
		for( size_t l = length2; l > length1; --l ) {
			node_point = node_point->next;
		}
		return intersectionPointRecursive(
				node1, node_point, length1, length1);
	} else if( length2 < length1 ) {
		node_point = node1;
		for( size_t l = length1; l > length2; --l ) {
			node_point = node_point->next;
		}
		return intersectionPointRecursive(
				node_point, node2, length2, length2);
		// If they are the same length already just return the 
		// next element in the chain for each one.
	} else {	
		return intersectionPointRecursive(
				node1->next, node2->next, 
				length1-1, length2 -1
				);
	}
}

	
NodeSingle* intersectionPoint(
		LinkedListSingle const& list1, LinkedListSingle const& list2) {
	NodeSingle* node1 = list1.head;
	NodeSingle* node2 = list2.head;
	int length1 = 0;
	int length2 = 0;
	while( node1 != NULL ) {
		node1 = node1->next;
		++length1;
	}
	while( node2 != NULL ) {
		node2 = node2->next;
		++length2;
	}
	return intersectionPointRecursive(
			list1.head, list2.head, length1, length2
			);

}

