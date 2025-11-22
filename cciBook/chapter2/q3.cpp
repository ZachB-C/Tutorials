// We need to delete a node from a linked list that is not the first or the
// last we will be given access to that node only. It is a singly linked list
// I guess the only way to do it is to copy all latter nodes up to their
// previous node and then delete the final node, assuming the ordering matters.
#include <iostream>
#include "linkedlist.h"

// Header functions
void deleteMiddleNode( NodeSingle* middle_node);

int main() {
	LinkedListSingle list;
	NodeSingle* node;
	list.insertVectorAtHead({0,1,2,3,4,5,6,7,8,9,10});

	std::cout<<"Original: "<<std::endl;
	list.print();
	std::cout<<std::endl;
	node = list.accessNthNode(7);
	std::cout<<"Delete "<<node->data<<"th node: "<<std::endl;
	deleteMiddleNode(node);
	list.print();
	std::cout<<std::endl;
	return 0;
}

// I was making it to complicated by going to the end of the list
// I can just copy the next nodes contents into the middle node and 
// delete the next node.
void deleteMiddleNode(NodeSingle* middle_node) {
	// Middle node so cannot be the final node but check just to be sure
	if( middle_node->next == NULL ) {
		delete middle_node;
	}
	NodeSingle* next = middle_node->next;
	// Copy across from the next node
	middle_node->data = next->data;
	// Remove next from the link
	middle_node->next = next->next;
	// Delete next
	delete next;
}

