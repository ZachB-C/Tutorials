// A quick version we have pointer to start and one to end. load at the back 
// so the earliest ones arrived earliest.
//
#include <iostream>
#include "linkedlist.h"

class Animal {
	char species; // 'c' for cat 'd' for dog
	int id; // A number
	
	public:
		Animal(char sp, int id_number): species(sp), id(id_number)  {};
		void print() {
			if( isCat() ) {
				std::cout<<"Cat";
			} else if( isDog() ) {
				std::cout<<"Dog";
			} else if( isNotAnAnimal() ) {
				std::cout<<"No animal present.";
				return;
			} else {
				std::cout<<"Unrecognised species";
				return;
			}
			std::cout<<" named "<<id;
		};
		bool isCat() { return (species == 'c');};
		bool isDog() { return (species == 'd');};
		bool isNotAnAnimal() { return (species == 'x');};
};


class Sanctuary {
	LinkedListSingle<Animal> contents;
	NodeSingle<Animal>* last;
	size_t n_cats;
	size_t n_dogs;

	public:
		Sanctuary(): n_cats(0), n_dogs(0) {};
		void enqueue(Animal input);
		Animal dequeueAny();
		Animal dequeueCat();
		Animal dequeueDog();
		bool isEmpty();
		void print();
	private:
		void increaseCounts(Animal input);
		void decreaseCounts(Animal output);
};


int main() {
	std::cout<<"Start: ";
	Sanctuary shelter;
	// First load it up with animals.
	size_t c = 0;
	size_t d = 0;
	for( ; c<3; ++c) {
		std::cout<<c<<std::endl;
		shelter.enqueue( Animal('c', c) );
	}
	shelter.print();
	for( ; d<4; ++d) {
		std::cout<<d<<std::endl;
		shelter.enqueue( Animal('d', d));
	}
	shelter.print();
	for( ; c<7; ++c) {
		std::cout<<c<<std::endl;
		shelter.enqueue( Animal('c', c) );
	}
	shelter.print();
	for( ; d<10; ++d) {
		std::cout<<d<<std::endl;
		shelter.enqueue( Animal('d', d));
	}
	shelter.print();

	std::cout<<" Dequeue Any: "<<std::endl;
	for( int i = 0; i<8; ++i) {
		(shelter.dequeueAny()).print();
		std::cout<<"\t";
	}
	std::cout<<std::endl;
	shelter.print();

	std::cout<<" Dequeue Dog : "<<std::endl;
	for( int i = 0; i<3; ++i) {
		(shelter.dequeueDog()).print();
		std::cout<<"\t";
	}
	std::cout<<std::endl;
	shelter.print();

	std::cout<<" Dequeue Cat : "<<std::endl;
	for( int i = 0; i<10; ++i) {
		(shelter.dequeueCat()).print();
		std::cout<<"\t";
	}
	std::cout<<std::endl;
	shelter.print();

}



void Sanctuary::enqueue(Animal input) {
//	std::cout<<"Commence 1:"<<std::endl;
//	std::cout<<"Commence 2:"<<std::endl;
	NodeSingle<Animal>* new_animal = new NodeSingle<Animal>(input);
//	std::cout<<"Commence 3:"<<std::endl;
	if( isEmpty() ) {
//		std::cout<<"Commence"<<std::endl;
		// Set up first and last points.
		contents.head = new_animal;
		last = new_animal;
	} else {
		// Attach the new animal and then move the pointer
		last->next = new_animal;
		last = new_animal; 
	}

	increaseCounts(input);
	return;
}
		
// Might need to define a copy constructor.
Animal Sanctuary::dequeueAny() {
	Animal output = Animal('x', 0);
	if( (n_cats > 0) || (n_dogs > 0) ) {
		NodeSingle<Animal>* current = contents.head;
		output = current->data;
		contents.head = current->next;
		delete current; // Could use inbuild linked list commands 
				// probably.
		decreaseCounts(output);
	} else {
		std::cout<<"Sorry there are no animals available."<<std::endl;
	}

	return output;
}
// Could make dequeue species and then give different options,
// even use references to functions?
Animal Sanctuary::dequeueCat() {
	Animal output = Animal('x', 0);
	if( n_cats > 0 ) {
		NodeSingle<Animal>* current = contents.head;
		if( current->data.isCat() ) {
			contents.head = current->next;
			output = current->data;
			delete current;
		} else {
			// While we don't have a cat keep looking.
			while( !(current->next->data.isCat()) ) {
				current = current->next;
			}
			NodeSingle<Animal>* next = current->next;
			output = next->data;
			current->next = next->next;
			delete next;
		}
		decreaseCounts(output);
	} else {
		std::cout<<"Sorry there are no cats available."<<std::endl;
	}

	return output;
}


Animal Sanctuary::dequeueDog() {
	Animal output = Animal('x', 0);
	if( n_dogs > 0 ) {
		NodeSingle<Animal>* current = contents.head;
		if( current->data.isDog() ) {
			contents.head = current->next;
			output = current->data;
			delete current;
		} else {
			// While we don't have a cat keep looking.
			while( !(current->next->data.isDog()) ) {
				current = current->next;
			}
			NodeSingle<Animal>* next = current->next;
			output = next->data;
			current->next = next->next;
			delete next;
		}
		decreaseCounts(output);
	} else {
		std::cout<<"Sorry there are no dogs available."<<std::endl;
	}

	return output;
}

bool Sanctuary::isEmpty() {
	if( n_cats == 0 && n_dogs == 0 ) {
		return true;

	}
	return false;

}

void Sanctuary::print() {
	NodeSingle<Animal>* current = contents.head;
	std::cout<<"Animals in sanctuary:";
	while( current != NULL ) {
		std::cout<<"\t";
		current->data.print();
		if( current->next != NULL ) {
			std::cout<<",";
		} else {
			std::cout<<"."<<std::endl;
		}
		current = current->next;
	}
	return;
}


void Sanctuary::increaseCounts(Animal input) {
	if( input.isCat() ) { 
		++n_cats;
	} else if( input.isDog() ) {
		++n_dogs;
	} else {
		std::cout<<"Sorry we cannot accept this kind of animal.";
	}
	return;
}

void Sanctuary::decreaseCounts(Animal output) {
	if( output.isCat() ) { 
		--n_cats;
	} else if( output.isDog() ) {
		--n_dogs;
	} else {
		std::cout<<"Sorry we cannot provide this kind of animal.";
	}
	return;
}



