#include <iostream>
#include <bitset>

// Either a bool or unsigned int?
union IntBool {
	bool b;
	uint i;
};

int main(void) {
	IntBool v;
	v.i = 1234567;
	std::cout << "i1 = " << std::bitset<32>(v.i) << " (" << v.i << ")" << std::endl;
	v.b = true;
	std::cout << "i2 = " << std::bitset<32>(v.i) << " ( " << v.i << ")" << std::endl;
	return 0;
}

