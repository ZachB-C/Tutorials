#include <iostream>
#include <bitset>

union IntBool {
	bool b;
	uint i;
};

int divide(int n, int d) {
	return n / d;
}

int divideBad(int n, int d) {
	if (d==0) {
		return -1;
	}
	else {
		return n / d;
	}
}
/*
 * This does not seem to work, not sure why, it doesn't want to convert to the union type I guess?
union IntError {
	int a;
	std::invalid_argument error;
};

IntError divideSafe(int n, int d) {
	if (d==0) {
		return std::invalid_argument("DivByZero");
	}
	else {
		return n / d;
	}
}
*/

int main(void) {
	IntBool v;
	v.i = 1234567;
	std::cout << "i1 = " << std::bitset<32>(v.i) << " (" << v.i << ")" << std::endl;
	std::cout << "b1 = " << std::bitset<32>(v.b) << " (" << v.b << ")" << std::endl;
	v.b = true;
	std::cout << "i2 = " << std::bitset<32>(v.i) << " (" << v.i << ")" << std::endl;
	std::cout << "b2 = " << std::bitset<32>(v.b) << " (" << v.b << ")" << std::endl;
	v.b = false;
	std::cout << "i3 = " << std::bitset<32>(v.i) << " (" << v.i << ")" << std::endl;
	std::cout << "b3 = " << std::bitset<32>(v.b) << " (" << v.b << ")" << std::endl;
	return 0;
}
	
	

