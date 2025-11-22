// We must find the k from last element. So I guess we count the elements on 
// the first pass and then go to it on the second as the naive way or we could 
// have a pointer k behind but it would be the same. I'll assume it is zero
// indexed from last.

#include <iostream>
#include <stdexcept>
#include <string>

// Header functions
int kthFromLast( const LinkedListSingle& list, size_t k);
int kthFromLastRecursive( const LinkedListSingle& list, size_t k);
NodeSingle* kthFromLastNode( const LinkedListSingle& list, size_t k);

int main() {
	LinkedListSingle list;
	int output = 0;
	int output_r = 0;

	list.insertVectorAtHead({10,9,8,7,6,5,4,3,2,1,0});	
	std::cout<<"Original: "<<std::endl;
	list.print();
	std::cout<<std::endl;
	
	for( size_t k = 0; k < 20; ++k) {
		std::cout<<k<<"th from last: ";
		try{
		    output = kthFromLast(list, k);
		    output_r = kthFromLastRecursive(list, k);
		    std::cout<<output<<" r: "<<output_r;
		}
		catch( const std::length_error& ) {
			std::cout<<"Does not exist.";
		}
		std::cout<<std::endl;
		
	}

	return 0;
}

// Should check that it exists.
int kthFromLast( const LinkedListSingle& list, size_t k) {
	NodeSingle* current = list.head;
	size_t length_list = 0;
	// First detemine the length of the list
	while( current != NULL ) {
		++length_list;
		current = current->next;
	}
	if( length_list <= k ) {
		throw std::length_error(
			std::to_string(k) + "th exists not, length = "
			       		 + std::to_string(length_list));
	}
	// Instead of this we could move k through first with one pointer and
	// then start another one moving at the same speed then when the 
	// first reaches the end the second will be k from the end. Not sure if
	// there is any advantage except not storing length?
	// Now find the correct entry
	current = list.head;
	for( size_t i=1; i<length_list - k; ++i) {
		current = current->next;

	}
	return current->data;
}

// Not really sure what to do here, they suggest something recursive.
// maybe we are meant to return address not data, so a pointer to the data?
// I could do that I guess
int kthFromLastRecursive(const LinkedListSingle& list, size_t k) {
	NodeSingle* node = kthFromLastNode(list, k);
	return node->data;	
}

// This seems silly because I think it will be N(N-K)/2 = O(N^2) so this is
// much longer than the one above that does two passes? Why would we do this?
// Not sure why we need to return two things, maybe if we measure length but
// then we should do the iterative one.
NodeSingle* kthFromLastNode(const LinkedListSingle& list, size_t k) {
	NodeSingle* target;
	if(k == 0) { 
		target = NULL;
	} else {
		target = kthFromLastNode(list, k-1);
		if( target == list.head ) {
			throw std::length_error(
					std::to_string(k) + "th from last"
					+ " is out of range"
					);
		}
	}
	NodeSingle* current = list.head;
	while( current->next != target ) {
		current = current->next;
	}
	return current;
}	

