#include <iostream>

template<typename T>
T abs( T val ) {
	const T ZERO = 0 ;
	if ( val > ZERO ) { return val;}
	else { return (-val); }
}

template<typename T>
bool equal( T v1, T v2 ) {
	return (v1==v2);
}

template<typename T>
const T EPSILON = 0;

template<>
const float EPSILON<float> = 1e-6;

template<>
const double EPSILON<double> = 1e-13;
/*
template<>
using real<double> = double;

template<>
using real<float> = float;
*/
template<>
bool equal(double v1, double v2) {
	return (abs(v1-v2)<EPSILON<double>);
}

template<>
bool equal(float v1, float v2) {
	return (abs(v1-v2)<EPSILON<float>);
}

int main() {
	double val = 1.0, tenth = val/10, sum = 0.0;
	for ( int i = 0; i<10; ++i) {
		sum += tenth;
	}
	if (equal(val,sum)) {
		std::cout<<"1. == 1./10 + 1./10 + ...";
	}
	else {
		std::cout<<"1. != 1./10 + 1./10 + ...";
	}	
	float val2 = 1.0, tenth2 = val2/10, sum2 = 0.0;
	for ( int i2 = 0; i2<10; ++i2) {
		sum2 += tenth2;
	}
	if (equal(val2,sum2)) {
		std::cout<<"1. == 1./10 + 1./10 + ...";
	}
	else {
		std::cout<<"1. != 1./10 + 1./10 + ...";
	}
}



