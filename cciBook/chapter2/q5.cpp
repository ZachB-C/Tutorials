// Numbers with one digit per node head of list is units and next is tens, etc.
// Task is to design an adder for these linked lists, that returns a number 
// in the same format within the linked list. Then design one where the numbers
// are stored in the opposite direciton.
#include <iostream>
#include "linkedlist.h"

void addLists(
		const LinkedListSingle& list1, 
		const LinkedListSingle& list2,
		LinkedListSingle& list_sum
		);
void addListsReversed(
			const LinkedListSingle& list1,
			const LinkedListSingle& list2,
			LinkedListSingle& list_sum
		);
void reverseList( const LinkedListSingle& list, 
			LinkedListSingle& list_reversed);

int main() {
	LinkedListSingle list1;
	LinkedListSingle list2;
	LinkedListSingle list_sum;
	LinkedListSingle list_sum_r;

	list1.insertVectorAtHead({8,2,3});
	list2.insertVectorAtHead({4,2,9});
	addLists(list1, list2, list_sum);
	addListsReversed(list1, list2, list_sum_r);

	std::cout<<" \t";
	list1.print();
	std::cout<<std::endl<<"+\t";
	list2.print();
	std::cout<<std::endl<<"=\t";
	list_sum.print();
	std::cout<<std::endl<<"=\t";
	list_sum_r.print();
	std::cout<<std::endl;

	list1.insertVectorAtHead({1,2,3});
	list2.insertVectorAtHead({2,7});
	list_sum.~LinkedListSingle();
	list_sum_r.~LinkedListSingle();
	addLists(list1, list2, list_sum);
	addListsReversed(list1, list2, list_sum_r);

	std::cout<<" \t";
	list1.print();
	std::cout<<std::endl<<"+\t";
	list2.print();
	std::cout<<std::endl<<"=\t";
	list_sum.print();
	std::cout<<std::endl<<"=\t";
	list_sum_r.print();
	std::cout<<std::endl;


	
	list1.insertVectorAtHead({123});
	list2.insertVectorAtHead({2,7});
	list_sum.~LinkedListSingle();
	list_sum_r.~LinkedListSingle();
	addLists(list1, list2, list_sum);
	addListsReversed(list1, list2, list_sum_r);

	std::cout<<" \t";
	list1.print();
	std::cout<<std::endl<<"+\t";
	list2.print();
	std::cout<<std::endl<<"=\t";
	list_sum.print();
	std::cout<<std::endl<<"=\t";
	list_sum_r.print();
	std::cout<<std::endl;
 
 	list1.insertVectorAtHead({123});
	list2.~LinkedListSingle();
	list_sum.~LinkedListSingle();
	list_sum_r.~LinkedListSingle();
	addLists(list1, list2, list_sum);
	addListsReversed(list1, list2, list_sum_r);

	std::cout<<" \t";
	list1.print();
	std::cout<<std::endl<<"+\t";
	list2.print();
	std::cout<<std::endl<<"=\t";
	list_sum.print();
	std::cout<<std::endl<<"=\t";
	list_sum_r.print();
	std::cout<<std::endl;
 
	list1.~LinkedListSingle();
 	list1.insertVectorAtHead({9,7,8});
	list2.~LinkedListSingle();
 	list2.insertVectorAtHead({6,8,5});
	list_sum.~LinkedListSingle();
	list_sum_r.~LinkedListSingle();
	addLists(list1, list2, list_sum);
	addListsReversed(list1, list2, list_sum_r);

	std::cout<<" \t";
	list1.print();
	std::cout<<std::endl<<"+\t";
	list2.print();
	std::cout<<std::endl<<"=\t";
	list_sum.print();
	std::cout<<std::endl<<"=\t";
	list_sum_r.print();
	std::cout<<std::endl;
 

	return 0;
}


// Here this should be simple we just add and carry and if we add a new node
// everytime we need to carry or if one of the lists has more digits.
// Need to check when they are different lengths as well
void addLists( 
		const LinkedListSingle& list1, 
		const LinkedListSingle& list2,
		LinkedListSingle& list_sum
		) {
	NodeSingle* node1 = list1.head;
	NodeSingle* node2 = list2.head;
	// Check list_sum is empty
	if( list_sum.head == NULL ) {
		list_sum.head = new NodeSingle(0);
	} else {
		std::cout<<"Output list not empty."<<std::endl;
		return;
	}
	NodeSingle* node_sum = list_sum.head;
	int carry = 0;
	int partial_sum = 0;
	// Note we behave differential for first element of loop
	bool first = true;
	// Keep going until we get to the end of both of them
	// and have dealt with any remaining carries.
	while( node1 != NULL || node2 != NULL || carry != 0 ) {
		// It would be more elegant to move put in the correct
		// data rather than zero initialise and then change
		// but I think this is clearer.
		if( first ) { 
			first = false; 
		} else {
			node_sum->next = new NodeSingle(0);
			node_sum = node_sum->next;
		}

		// Account for carry, zero initialised
		partial_sum = carry;
		if( node1 != NULL ) {
			// Add current value and move to next node
			partial_sum += node1->data;
			node1 = node1->next;
		}
		if( node2 != NULL ) {
			// Add current value and move to next node
			partial_sum += node2->data;
			node2 = node2->next;
		}
		// We take the modulus as the value and carry the rest
		node_sum->data = partial_sum % 10;
		// Integer division should round to zero I think.
		carry = partial_sum / 10;
		// I don't like this extra check but I think it is unavoidable
		// unless I do something similar at the beginning

	}

	std::cout<<"End"<<std::endl;
	return;
}
		

// Couple of options we could call standard sum list and dress it by reversal
// operators before and afterwards. Or we could try to handle the carries 
// as we go along; We could cheat and use the fact we are allowed to include
// non unit numbers and then just sort them out after an additional pass?
// For two numbers the biggest the carry can be is 2 I think, actually I think
// 2 is only possible if we started with a carry in fact we have 9+9 = 18 means // a carry of 1 then 1+9+9 = 19 still carry of 1, so if they are properly 
// formatted it is a carry of 1, which is simple to deal with, we either add
// 1 or don't we can check ahead for a carry. Just look if the next will add to 
// more than 10, but might mean checking the whole thing? We could make an 
// additional temporary linked list to store the carries in and then 
// use that as reference.
// Maybe have a sub-routine check for carry. For this one I'll assume that we
// have only digits maybe? Then I could use a bit vector, but I don't know how
// long to make it. Naive way would be N^2 as we have to pass to the end and 
// then do that again. If they are properly formatted it can be done in
// two passes, first just add up but leave as too large ints and second pass
// do the carries, although that won't work because we may need to carry again
// so it could still be N^2
// Okay we will do order N, and increase size in space but still same order
// we just make new copies of the lists that are reversed add them and reverse
// the result. We can just call the previous function. We could do something
// fancy to add as we reverse but I don't think it is worth the effort.
void addListsReversed( 
		const LinkedListSingle& list1, const LinkedListSingle& list2,
		LinkedListSingle& list_sum
		) 
{
	// Reversed lists
	LinkedListSingle list1_r;
	LinkedListSingle list2_r;
	LinkedListSingle list_sum_r;
	
	reverseList(list1, list1_r );
	reverseList(list2, list2_r);

	addLists(list1_r, list2_r, list_sum_r);
	reverseList(list_sum_r, list_sum);

	return;
}


void reverseList(const LinkedListSingle& list, LinkedListSingle& list_r) {
	NodeSingle* node = list.head;
	if( list_r.head != NULL ) {
		std::cout<<"List to copy to is not empty"<<std::endl;
		return;
	}
	if( node == NULL ) {
		// That was easy
		return;
	}
	
	NodeSingle* node_r = NULL;

	// Copy across the data in reverse order.
	while( node != NULL ) {
		// Make a new node at head and append the previous node to it.
		list_r.head = new NodeSingle();
		list_r.head->next = node_r;
		// Updata our node pointer
		node_r = list_r.head;
		// Copy data to our reversed node
		node_r->data = node->data; 
		node = node->next;
	}

	return;
}
