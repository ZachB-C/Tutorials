// Here I want to test if it is possible to multiply template parametets.
#include <iostream>
#include <array>

// Header functions
// Returns an array that is N interleaved arrays starting from start and
// incrementing in steps of incr.
// It works perfectly, not sure how I could return a pointer to this array
// I guess I would need to wrap it in a class so I could call it as otherwise
// the main code would need to do the multiplication, which would be a mess.
template <typename T, size_t N, size_t L>
void printArray(T start, T incr);

int main() {
	printArray<int, 7, 3>(1, 1);
	return 0;
}

template <typename T, size_t N, size_t L>
void printArray( T start, T incr) {
	std::array<T, N*L> array_print;
	for(size_t n = 0; n<N; ++n) {
		for(size_t i = 0; i<L; ++i) {
			array_print[N*i+n] = start + i*incr;
		}
	}
	std::cout<<"{";
	for(T elem : array_print) {	
		std::cout<<elem<<"\t";
	}
	std::cout<<"}"<<std::endl;
	return;
}

