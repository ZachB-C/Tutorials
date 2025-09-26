#include <iostream>


template<typename Val>
struct MyContainer 
{
	int size() { return 0; };
};

template<typename Val>
struct MyExtendedContainer : public MyContainer<Val>
{
	int extended_size()
		{return this->size() + 1; } // Does not compile
							// without specifying MyContainer<Val>:: or this-> or using MyContainer<Val>::size to specify where size comes from MyContainer<Val>::size should be avoided because it inhibits possibly virtual methods
};


template<typename Container>
void inspect( Container & container) 
{
	// Must specify that iterator is a typename or it will multiply
	// iterator by x (or try to). But x does not exist
	//Container::iterator *x; // This will fail to compile
	typename Container::iterator *x;
}


int main() {
}
