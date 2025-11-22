// Here we have to put all numbers less than a given partition to the left of
// those greater or equal to a given partition the orderings within a 
// partition do not matter (including the partition value itself, it can 
// be anywhere). I think it can be done with a single complete pass and one
// partial pass. Just find first element of right partition and stick a 
// pointer to it, then keep going until we find an element that should be 
// in the left partition (or reach the end) and swap them. 
// Then with the first pointer step 
// through until we find another element from the right partition and with the
// second pointer keep going until we find another element from the left 
// partition or reach the end. This should have done the required pivot.
// Seems a bit like quick sort.

#include <iostream>
#include "linkedlist.h"

void repartitionList( LinkedListSingle& list, int partition);

// Test having the first and last elements correct or wrong
int main() {
	LinkedListSingle list;
	int partition = 5;
	list.insertVectorAtHead({3,5,8,5,10,2,1});
	std::cout<<"Original: "<<std::endl;
	list.print();
	std::cout<<std::endl;

	partition = 5; 
	repartitionList(list, partition);
	std::cout<<"Repartitioned: "<<partition<<std::endl;
	list.print();
	std::cout<<std::endl;
	
	list.insertVectorAtHead({9,1,6,2,8,3,4,10,100,16});
	std::cout<<"Original: "<<std::endl;
	list.print();
	std::cout<<std::endl;

	partition = 4; 
	repartitionList(list, partition);
	std::cout<<"Repartitioned: "<<partition<<std::endl;
	list.print();
	std::cout<<std::endl;

	return 0;
}

// Could make this more efficient by having the pointer for the low values
// never go backwards but this would involve comparing it to high pointer
// It would reduce the complexity from N^2 to N though, so could be worth doing
// would require a check to compare the two every time we step highNode.
// if( highNode == lowNode ) {lowNode = highNode->next;} that would reduce 
// from N^2 to N I think as lowNode will at most go through once and so will
// high node. No actually, lowNode will have highData in it so it will
// stop the high pointer, so as long as we increment lowNode we should be okay
void repartitionList(LinkedListSingle& list, int partition) {
	// High node is linked to nodes that should be in 
	// right partition 
	NodeSingle* highNode = list.head;
	// Low node is linked to nodes that should be in the
	// left partition, 
	// If there are no elements then just return
	if( highNode == NULL ) {
		return;
	}
	NodeSingle* lowNode = list.head; 
	int low_data;
	int high_data;
	
	// Stop if either of the pointers reaches the end of the 
	// list
	while( (highNode->next != NULL) && (lowNode != NULL) ) {
		// If highNode contents is above (or equal to)  partion
		// then we look for anything later on that is less than 
		// partition that we can swap with it.
		if( highNode->data >= partition ) {
			high_data = highNode->data;
			// If lowNode is not already defined set it to position
			// after highNode, otherwise it should already be in the
			// correct place
			if( lowNode == list.head ) {	lowNode = highNode->next;}
			while( lowNode != NULL ) {
				// If we find something from the 
				// lower position later on then we
				// swap the two
				if( lowNode->data < partition ) {
					low_data = lowNode->data;
					highNode->data = low_data;
					lowNode->data = high_data;
					// This ensures we start searching from 					// the next cell next time.
					lowNode = lowNode->next;
					break;
				} else {
					lowNode = lowNode->next;
				}
			}

		}
		// Now shift high node along and make sure it doesn't overtake
		// the lowNode
		highNode = highNode->next;
	}

	return;

}
