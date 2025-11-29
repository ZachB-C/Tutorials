// Here the task is to initialise three stacks that make use of the same array
// I guess the way to do it is to track the latest entry and do 3i, 3j+1, and
// 3k+2, track the values of i,j,k for the latest values, as it is a stack
// it will have a maximum size, can be templated. So check we don't
// exceed max size and have numbered methods pop1(), pop2(), pop3() for example.
#include <iostream>
#include <exception>
#include <string>
#include <array>
#include <vector>

// Header functions: these functions are indexed so they can be called 
// for any list, n is the list number 1,2 or 3.


// Header classes
template <typename T, size_t N, size_t L>
class ArrayStack {
	std::array<T, L*N> data; // Initialise an arrays that can hold 
				// N stacks of size L
	std::array<size_t, N> stack_lengths; 
	// Initialise all to zero
	size_t max_size;
	size_t max_stacks;

	public: 
		ArrayStack();
	//	~ArrayStack();// I don't think I need this as it has 
	//			// nothing to do.
		// Removes and returns item from nth stack
		T popIndexed(size_t n); 
		// Returns (but does not remove) item from nth stack
		T peekIndexed(size_t n); 
		void pushIndexed(T input, size_t n); // Adds input to stack n.
		bool isEmptyIndexed(size_t n); // Returns true if and only if 
				 // stack n is empty.
		bool isFullIndexed(size_t n); // Returns true if and only if 
						 // stack n is full.
		bool isSpaceIndexed(size_t data_size, size_t n); // Returns 
			// True if there is space for data_size pieces of 
			// data in the stack			 
		void pushVectorIndexed( std::vector<T> input_vector, size_t n);
		void printIndexed(size_t n); // Prints stack n; 
		void print();		     // Prints all stacks.
		// Returns current length of stack n 			 
		size_t lengthIndexed(size_t n);
		// Returns the number of stacks available
		size_t nStacksTotal();	
		size_t nStacksInUse(); // returns number of non empty stacks.
		// Runs isEmpty for every index and returns the results as 
		// a vector.
		std::array<bool, N> isEmptyAll();

	private: 
		bool doesStackExist(size_t n); // Checks nth index is in range
		// Returns the ith index of stack n within the main data
		// array.
		size_t getStackIndex(size_t n, size_t i); 
		// This gets the current (top) index for stack n.
		size_t getPopIndex(size_t n);
		size_t getPushIndex(size_t n);
};		
// I think stacks could be 1 indexed, but I guess to be careful they should be
// zero indexed
template <typename T, size_t N, size_t L>
bool ArrayStack<T,N,L>::doesStackExist(size_t n) 
{	// Check if stack index exists
	return (n < nStacksTotal());
}
// This is nice because I could change the way I store them
// I will interleave them now as it will be easy to see what is 
// happening but it might make more sense to make them contiguous.
template <typename T, size_t N, size_t L>
size_t ArrayStack<T,N,L>::getStackIndex(size_t n, size_t i) 
{	// We store all the stacks (N) 0th data then all the stacks 1st data
	// then all the stacks 2nd data etc.
	// Was using N instead of max_stacks here maybe that is a problem
	// because we would then need to specify it in stack index? Not sure?
	// Maybe there is the need for another separate template declaration
	// for methods, not sure!!!!
//	std::cout<<" i,n,N,L: "<<i<<", "<<n<<", "<<max_stacks<<", "
//		<<max_size<<std::endl;
//	std::cout<<"Index: "<<(i*max_stacks + n)<<std::endl; 
	return i*max_stacks + n;

}

template <typename T, size_t N, size_t L>
size_t ArrayStack<T,N,L>::getPopIndex(size_t n) 
{	
	// Top
	// Check that it is not empty
	if( !(doesStackExist(n)) ) {
		throw std::out_of_range( std::to_string(n) 
				+ "th node is not defined." ); 
	}
	size_t length_stack = stack_lengths[n]; 
	if ( isEmptyIndexed(n) ) {
		throw std::out_of_range("No items in " 
				+ std::to_string(n) + "th stack.");
	}
	return getStackIndex(n, length_stack-1);
}

template <typename T, size_t N, size_t L>
size_t ArrayStack<T,N,L>::getPushIndex(size_t n) 
{	
	// Top
	// Check that it is not empty
	if( !(doesStackExist(n)) ) {
		throw std::out_of_range( std::to_string(n) 
				+ "th node is not defined." ); 
	}
	size_t length_stack = stack_lengths[n]; 
//	std::cout<<length_stack<<" = Length"<<std::endl;
	// Check we won't go out of range
	if ( isFullIndexed(n) ) {
		throw std::out_of_range("Stack is already full, it can hold " 
				+ std::to_string(max_size) + " items.");
	}
//	std::cout<<getStackIndex(n, length_stack)<<std::endl;
	return getStackIndex(n, length_stack);
}
// Constructor
template <typename T, size_t N, size_t L>
ArrayStack<T,N,L>::ArrayStack() {
	// data; don't need to initialise this it will happen automatically
	// only if I need to change it.
	stack_lengths = {0}; // Is the same as {} they
			     // are all 0 initialised.
	max_size = L;
	max_stacks = N;
}

// Destructor, I don't think this is necessary as there are only 
// standard objects here so default destructor should handel it.
//template <typename T, size_t N, size_t L>
//ArrayStack<T, N, L>::~ArrayStack() {
//	// I think this calls the destructor
//	// I think maybe my destructors might not be quite right, do I delete 
//	//
//	delete data;
//	delete stack_lengths;
//	
//
//}

// Removes and returns item from nth stack
template <typename T, size_t N, size_t L>
T ArrayStack<T, N, L>::peekIndexed(size_t n) {
	// Locate data
	size_t index = getPopIndex(n);
	// Extract data
	return data[index];
}	
	

// Removes and returns item from nth stack
template <typename T, size_t N, size_t L>
T ArrayStack<T, N, L>::popIndexed(size_t n) {
	// Extract data
	T element = peekIndexed(n);
	// Pop data
	// It is not necessary to set this equal to zero but it is neater but if
	// we want it to be valid for any data type we would need a method to 
	// remove that data type so I guess we will just leave it and 
	// overwrite it, it means it is in principle reachable but ...
	// Reduce the appropriate counter
	--stack_lengths[n];
	return element;
}	
	
// Removes and returns item from nth stack
template <typename T, size_t N, size_t L>
void ArrayStack<T, N, L>::pushIndexed(T input, size_t n) {
	// Locate data
	size_t index = getPushIndex(n);
	// Place data
	data[index] = input;
	// Increment counter so data can be found
	++stack_lengths[n];
	return;
}


template <typename T, size_t N, size_t L>
bool ArrayStack<T, N, L>::isEmptyIndexed(size_t n) {
	if( !(doesStackExist(n)) ) {
		// If the stack does not exist throw an error
		throw std::out_of_range("Stack " + std::to_string(n) 
				+ " does not exist. There are only "
				+ std::to_string(max_stacks) + " stacks.");
	}
	if( stack_lengths[n] == 0 ) {
		return true;
	}
	return false;
}

template <typename T, size_t N, size_t L>
bool ArrayStack<T, N, L>::isFullIndexed(size_t n) {
	// Should we check if it is greater than and 
	// give an error?
	if( stack_lengths[n] == max_size ) {
		return true;
	}
	return false;
}
// !!! This seems to cause a problem, do i need to call things as
// isSpacedIndexed<T, N, L>? Surely not? But maybe?
// Maybe I should just make a separate function for this or include it
// inside? I have put L instead of max_size to see if that works.
template <typename T, size_t N, size_t L>
bool ArrayStack<T, N, L>::isSpaceIndexed(size_t data_size, size_t n) {
	if( stack_lengths[n]+data_size <= max_size ) {
		return true;
	}
	return false;
}

template <typename T, size_t N, size_t L>
void ArrayStack<T, N, L>::pushVectorIndexed(
	       	std::vector<T> input_vector, 
		size_t n
		) 
{
	size_t input_size = input_vector.size();
	// If there is not space return an error
	if( !(isSpaceIndexed(input_size, n)) ) {
		throw std::out_of_range("Too much data (" 
				+ std::to_string(input_size) 
				+ " pieces), only room for " 
				+ std::to_string(max_size - stack_lengths[n]) 
				+ " more pieces." );
	}	
	// If there is space load all the data.
	for( size_t i = 0; i<input_size; ++i) {
		pushIndexed(input_vector[i], n);
	}

	return;
}


// Prints nth stack
template <typename T, size_t N, size_t L>
void ArrayStack<T, N, L>::printIndexed(size_t n) {
//	std::cout<<"Start"<<std::endl;
	if( isEmptyIndexed(n) ) {
		std::cout<<"Stack is empty.";
		return;
	}	
//	std::cout<<" Step 1"<<std::endl;
	std::cout<<"{";
	size_t index = 0;
	for( size_t i = 0; i < stack_lengths[n]; ++i) {
//		std::cout<<"i = "<<i<<" n = "<<n;
		index = getStackIndex(n, i);
//		std::cout<<"Index: "<<index<<std::endl;
		std::cout<<data[index]<<"\t";
	}
	std::cout<<"}";
	return;

}

// Prints all stacks
template <typename T, size_t N, size_t L>
void ArrayStack<T, N, L>::print() {
	for( size_t n = 0; n < max_stacks; ++n) {
		std::cout<<n<<"th node: ";
		printIndexed(n);
		std::cout<<std::endl;
	}
	return;
}



template <typename T, size_t N, size_t L>
// Returns current length of stack n 			 
size_t ArrayStack<T, N, L>::lengthIndexed(size_t n) {
	if( !(doesStackExist(n))) {
		throw std::out_of_range(std::to_string(n) 
				+ "th stack does not exist. There are only "
				+ std::to_string(max_stacks) + " stacks.");
	}
	return stack_lengths[n];
}

// !!! Is a comment under template okay?
template <typename T, size_t N, size_t L>
// Returns the number of stacks available
size_t ArrayStack<T, N, L>::nStacksTotal() {
	return max_stacks;
}
	

template <typename T, size_t N, size_t L>
size_t ArrayStack<T, N, L>::nStacksInUse() {
	std::array<bool, N> emptyStacks = isEmptyAll();
	size_t n_not_empty = 0;
	for( bool empty : emptyStacks) {
		if( !empty ) {
			++n_not_empty;
		}
	}
	return n_not_empty;

}

template <typename T, size_t N, size_t L>
std::array<bool, N> ArrayStack<T, N, L>::isEmptyAll() {
	std::array<bool, N> empty_array;
	for( size_t n = 0; n < max_stacks; ++n ) {
		empty_array[n] = isEmptyIndexed(n);
	}
	return empty_array;
}


int main() {
	ArrayStack<int, 5, 10> stack;
	stack.print();
	
	std::cout<<"Push Test"<<std::endl;
	stack.pushIndexed(21, 2);
//	std::cout<<"Test P"<<std::endl;
	stack.printIndexed(2);
//	std::cout<<"Test R"<<std::endl;
	std::cout<<std::endl;
//	std::cout<<"Test S"<<std::endl;
	stack.print();
//	std::cout<<"Test T"<<std::endl;

	std::cout<<"Push Vector Test"<<std::endl;
	stack.pushVectorIndexed( {0,1,2,3,4,5,6,7,8,9}, 0);
	std::cout<<"Test"<<std::endl;
	stack.printIndexed(0);
	std::cout<<std::endl;
	stack.print();

	stack.pushVectorIndexed({0,1,2,3,4},4);
	stack.print();
	std::cout<<std::endl;

	std::cout<<"Peek and Pop Test"<<std::endl;
	std::cout<<stack.peekIndexed(0)<<std::endl;
	std::cout<<stack.popIndexed(0)<<std::endl;
	std::cout<<stack.peekIndexed(0)<<std::endl;
	std::cout<<stack.popIndexed(0)<<std::endl;
	stack.printIndexed(0);
	std::cout<<std::endl;
	stack.print();
	std::cout<<std::endl;

	std::cout<<"Empty test"<<std::endl;
	std::array<bool, 5> empty_vector = stack.isEmptyAll();
	for( size_t n = 0; n<3; ++n ) {
		std::cout<<n<<"th node is empty: "
			<<stack.isEmptyIndexed(n)
			<<", "<<empty_vector[n]
			<<std::endl;
	}
	

	return 0;
}


