// Okay now I will try a simple one, the idea is that the array will dynamically// move data in order to ensure the most efficient use of the space. 
// For simplicity I will use an array of size 12 without templating. I will 
// store data continguously within the three stacks and initialise stacks a 
// third of the way through and two thirds through, then rearrange things
// if one grows too big. I will fix it to ints to avoid templates.
// It was more of a hassle than I hoped.
#include <iostream>
#include <exception>
#include <array>

#define ARRAY_SIZE 10

class ArrayStack {
	std::array<int, ARRAY_SIZE> data;
	// Start index and stop index are the 
	// start and end of the data so first piece of data
	// at start and last at stop.
	size_t start_indices[3];
	size_t stop_indices[3];
	size_t sizes[3];
	size_t free_space[3];
	size_t free_space_total;
	void shift_data(size_t n);
	void shift_up_k(size_t n, size_t k);
	void free_space_allocator();

	public:
		ArrayStack();
		// No destructor;
		int peek(size_t n);
		int pop(size_t n);
		void push(size_t n, int input);
		bool isEmpty(size_t n);
		void print();
};

// Determine free space between neighbouring stacks
// Allows wrapping.
size_t calculate_free_space(size_t stop_a, size_t start_b) {
	if(start_b > stop_a) {
		return start_b - stop_a;
	} else if( stop_a >= start_b ) {
		return (start_b - stop_a + ARRAY_SIZE) % ARRAY_SIZE;
	} else {
		throw std::out_of_range("Something is wrong. Stop_a: " 
				+ std::to_string(stop_a) + ", Start_b: "
				+ std::to_string(start_b));
	}
}

void ArrayStack::free_space_allocator() {
	for( size_t n = 0; n < 3; ++n ) {
		free_space[n] = calculate_free_space(
					stop_indices[n], 
					start_indices[(n+1) % 3]
					);
	}
	return;
}

ArrayStack::ArrayStack() {
	start_indices[0] = 0;
	start_indices[1] = ARRAY_SIZE/3;
	start_indices[2] = 2*ARRAY_SIZE/3;
	for( size_t i = 0; i<3; i++ ) {
		// Stop is the first empty space
		// Start is where the first element will appear
		stop_indices[i] = start_indices[i];
		sizes[i] = 0;
	}
	free_space_allocator();
	free_space_total = ARRAY_SIZE;
}

int ArrayStack::peek(size_t n) {
	if( isEmpty(n) ) {
		throw std::out_of_range("No data");
	}
	// Stop indices are 1 after the end so we must subtract 1.
	return data[(stop_indices[n]+ARRAY_SIZE-1) % ARRAY_SIZE];
}
// Could do these with pointers rather than indices but not clear that would
// be easier.
int ArrayStack::pop(size_t n) {
	int output = peek(n);
	--stop_indices[n]; // Note that we have removed something.
	--sizes[n];
	// Overkill we could easily do free space update by hand.
	free_space_allocator();
	++free_space_total;
	return output;
}

void ArrayStack::push(size_t n, int input) {
	// This is the hard one as we might need to rearrange things
	if( free_space_total == 0 ) {
		std::cout<<"Stack is full."<<std::endl;
		// When we have not put anything in yet there is space 
		// for one item.
	} else if( free_space[n] == 0) {
		// If not enough space we shift things around to make space
		shift_data(n);
	}
	// Then we put the data in and increment stop_indices[n]
//	std::cout<<"n: "<<n<<" Input: "<<input<<std::endl;
//	std::cout<<"Stop_index: "<<stop_indices[n]<<std::endl;
	data[stop_indices[n]] = input;
	// Then increment stop_index ready for next input
	stop_indices[n] = (stop_indices[n] + 1) % ARRAY_SIZE;
//	std::cout<<"Stop_index: "<<stop_indices[n]<<std::endl;
	// Update meta parameters.
	--free_space_total;
	free_space_allocator();
	++sizes[n];
}

// Shift data will move the data around in order to distribute the empty 
// space equally between the three stacks. Prioritising giving space 
// to stack n. Could optimise to make the fewest movements but I won't bother
// with that.
void ArrayStack::shift_data(size_t n) {
	size_t divided_space = free_space_total/3;
	// Do the nth stack last as that is the one we want to give space to.
	// Total free space may not divide equally in three so we 
	// need to account for that case and have a potentially larger
	// partition for node n, this means if there is one space left we will
	// always give it to n
	//  Always start with the m that comes before n, which is also the one
	//  two steps after if we mod by 3, this avoids negative numbers
	// This is a bit fiddly
	size_t m = (n+1) % 3;
	for( size_t i=0; i<3; ++i ) {
		// Do not shift our special data that way we will definitely
		// Free up some space for it.
		m = (m + 1) % 3;
		if( (m != n) && free_space[m] > divided_space ) {
			// If too much space then move that data up a bit
//			std::cout<<" k: "
//				<<free_space[m] - divided_space<<std::endl;
			shift_up_k(m, free_space[m] - divided_space);
		}
	}
	// This means mode n will have at least divided_space free 
	// space after we have made the changes.
	// We would only be doing this if our node had no free space so 
	// we don't need to move it, the others will do all the work.
	return;	
}

// Shifts the nth data stack up by k in the array
void ArrayStack::shift_up_k(size_t n, size_t k) {
	// The addition of ARRAY_SIZE ensures stop is after start
	for( size_t i = 0; i<sizes[n]; ++i) 
	{
//		std::cout<<"i: "<<i<<" n: "<<n<<" k: "<<k
//			<<" New index: "<<(start_indices[n]+i+k) % ARRAY_SIZE
//			<<" Old index: "<<(start_indices[n]+i) % ARRAY_SIZE
//			<<" Stop: "<<stop_indices[n]
//			<<" Start: "<<start_indices[n]
//			<<" Free: "<<free_space[n]
//			<<std::endl;
		data[(start_indices[n]+i+k) % ARRAY_SIZE] 
			= data[(start_indices[n]+i) % ARRAY_SIZE];
		// Erase data? but it is not really necessary
	}
	// Adjust the start indices and stop indices
	start_indices[n] = (start_indices[n] + k) % ARRAY_SIZE;
	stop_indices[n] = (stop_indices[n] + k) % ARRAY_SIZE;
	// Recalculate free space.
	free_space_allocator();

	return;
}

void ArrayStack::print() {
	std::cout<<"Free space: "<<free_space_total<<std::endl;

	std::cout<<"Start:\t";
	for(size_t n = 0; n<3; ++n) {
		std::cout<<start_indices[n]<<"\t";
	}
	std::cout<<std::endl<<"Size:\t";
	for(size_t n = 0; n<3; ++n) {
		std::cout<<sizes[n]<<"\t";
	}	
	std::cout<<std::endl<<"Stop:\t";
	for(size_t n = 0; n<3; ++n) {
		std::cout<<stop_indices[n]<<"\t";
	}
	std::cout<<std::endl;

	for( size_t n = 0; n<3; ++n) {
		std::cout<<std::endl<<"Data "<<n<<": ";

		for(size_t i = 0; i<sizes[n]; ++i) {
//			std::cout<<"index: "<<(start_indices[n]+i) % ARRAY_SIZE
//				<<std::endl<<" data: ";
			std::cout<<data[(start_indices[n] + i) % ARRAY_SIZE]
				<<"\t";
//			std::cout<<std::endl;
		}
	}
	std::cout<<std::endl;
	return;
}

bool ArrayStack::isEmpty(size_t n) {
	if( sizes[n] == 0 ) {
		return true;
	}
	return false;
}

int main() {
	ArrayStack stack;
	stack.print();
		
	stack.push(1, 0);
	stack.print();
	stack.push(0, 10);
	stack.push(2, 20);
	stack.print();

	
	stack.push(1, 1);
	stack.push(1, 2);
	stack.push(1, 3);
	stack.push(1, 4);
	stack.push(1, 5);
	stack.push(1, 6);
	stack.print();
	stack.push(1, 7);
	stack.print();

	std::cout<<stack.peek(1)<<std::endl;
	stack.print();
	std::cout<<stack.pop(1)<<std::endl;
	stack.print();
	
	return 0;
}

