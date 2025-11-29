// A quick version we have pointer to start and one to end. load at the back 
// so the earliest ones arrived earliest.
// This version keeps separate list for dogs and cats;
#include <iostream>
#include "linkedlist.h"

class Animal {
	char species; // 'c' for cat 'd' for dog
	int id; // A number
	int date; // Records date of arrival

	public:
		Animal(char sp, int id_number): 
			species(sp), 
			id(id_number),
			date(-1)
		{};
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
		bool arrivedBefore( Animal other) {
		       	return (this->date < other.date);
		};
		void setDate(int new_date) {date = new_date; return;};

};


class Sanctuary {
	NodeSingle<Animal>* last_cat;
	NodeSingle<Animal>* last_dog;
	LinkedListSingle<Animal> cats;
	LinkedListSingle<Animal> dogs;
	int date_count;

	public:
		Sanctuary() : last_cat(NULL), last_dog(NULL), date_count(0) {};
		void enqueue(Animal input);
		Animal dequeueAny();
		Animal dequeueCat();
		Animal dequeueDog();
		bool noCats();
		bool noDogs();
		void print();
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
	input.setDate( date_count++ ); // This will increment even if they
				       // try to give us a faulty animal.
	NodeSingle<Animal>* new_animal = new NodeSingle<Animal>(input);
	if( noCats() && input.isCat() ) {
		cats.head = new_animal;
		last_cat = new_animal;
	} else if( noDogs() && input.isDog() ) {
		dogs.head = new_animal;
		last_dog = new_animal;
	} else if( input.isCat() ) {
		last_cat->next = new_animal;
	       	last_cat = new_animal;	
	} else if( input.isDog() ) {
		last_dog->next = new_animal;
		last_dog = new_animal;
	} else {
		std::cout<<" Sorry we do not accept that type of animal."
			<<std::endl;
		delete new_animal;
	}
	return;
}
		
// Might need to define a copy constructor.
Animal Sanctuary::dequeueAny() {
	Animal output = Animal('x', 0);
	if( noDogs() && noCats() ) {
		std::cout<<"Sorry there are no animals available."<<std::endl;
		return output;
	} 
	if( noCats() ) {
		output =  dequeueDog();
	} else if( noDogs() ) {
		output = dequeueCat();
	} else if( ((dogs.head)->data).arrivedBefore( (cats.head)->data ) ) {
		output = dequeueDog();
	} else {
		output = dequeueCat();
	}

	return output;
}
// Could make dequeue species and then give different options,
// even use references to functions?
Animal Sanctuary::dequeueCat() {
	Animal output = Animal('x', 0);
	if( noCats() ) {
		std::cout<<"Sorry there are no cats available."<<std::endl;
		return output;
	} 

	NodeSingle<Animal>* current = cats.head;
	output = current->data;
	cats.head = current->next;
	delete current;

	return output;
}


Animal Sanctuary::dequeueDog() {
	Animal output = Animal('x', 0);
	if( noDogs() ) {
		std::cout<<"Sorry there are no dogs available."<<std::endl;
		return output;
	} 

	NodeSingle<Animal>* current = dogs.head;
	output = current->data;
	dogs.head = current->next;
	delete current;

	return output;
}

bool Sanctuary::noCats() {
	if( cats.head == NULL ) {
		return true;

	}
	return false;

}

bool Sanctuary::noDogs() {
	if( dogs.head == NULL ) {
		return true;

	}
	return false;

}

void Sanctuary::print() {
	std::cout<<"Animals in sanctuary:";
	for( NodeSingle<Animal>* current : {cats.head, dogs.head}) {
		std::cout<<"|";
		while( current != NULL ) {
			std::cout<<"\t";
			current->data.print();
			if( current->next != NULL ) {
				std::cout<<",";
			}
			current = current->next;
		}
	}
	std::cout<<"."<<std::endl;		
	return;
}



