#include<iostream>

template<typename T, int sz>
class Vector {
	public:
		T data[sz];
};

template<int sz>
using VectorDouble = Vector<double, sz>;

template<typename T>
using Vector3 = Vector<T, 3>;

template<typename T, int sz>
void display(const Vector<T, sz> & v) {
	std::cout << '(' << v.data[0];
	for(int i=1; i<sz; ++i) {
		std::cout << ", " << v.data[i];
	}
	std::cout << ")" << std::endl;
}

template<typename T>
T abs(T val) {
	const T ZERO = 0;
	if( val > ZERO) { return val;}
	else {return (-val); }
}

template<typename T>
bool equal(T v1, T v2) {
	return (v1==v2);
}

template<>
bool equal(double v1, double v2) {
	const double EPSILON = 1e-13;
	return (abs(v1-v2)<EPSILON);
}

int main() {
	Vector3<int> v1 = {6*7, 3*14, 2*21};
	VectorDouble<2> v2 = {3.14, 1.62};
	display(v1);
	display(v2);

	double val = 1.0, tenth = val/10, sum = 0.0;
	for( int i=0; i<10; ++i) {
		sum += tenth;
	}
	if (equal(val,sum)) {
		std::cout << "1. == 1./10 + 1./10 + ...";
	}
	else {
		std::cout << "1. != 1./10 + 1./10 + ...";
	}

	return 0;
}


