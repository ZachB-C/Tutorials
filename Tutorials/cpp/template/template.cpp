#include <iostream>

template<typename T>
T abs( T val ) {
	const T ZERO = 0;
	if ( val > ZERO ) { return val; }
	else { return (-val) ; }
}

template<typename T, int sz>
class Vector {
	public:
		T data[sz];
};


template<int sz>
using VectorDouble = Vector<double, sz>;

int main() {
	Vector<int,2> v = {2*2*2, -3*3};
	std::cout << abs<int>(v.data[0]) << std::endl;
	std::cout << abs<int>(v.data[1]) << std::endl;

	// Inferred type
	Vector<int, 2> w = {2*2*2, -3*3};
	std::cout << abs(w.data[0]) << std::endl; // T is inferred to be int
	std::cout << abs(w.data[1]) << std::endl; // T is inferred to be int

	// Equivalent
	VectorDouble<10> v1;
	Vector<double, 10> v2;

	// Code bloat: each instantiation is a new class, e.g.
	Vector<int,2> v3;
	Vector<int,3> v4;
	Vector<double,10> v5;
	Vector<double,20> v6;
	Vector<double,30> v7;





	return 0;
}
