#include <iostream>
#include <chrono>

int double_it(int i) {
	return i * 2;
}

struct Behemoth {
	int vals[1000000];
};

int double_first(Behemoth i) {
	return i.vals[0] * 2;
}

// Basic referemces
int main_1(void) {
	// Create a ne integer with value 5.
	int a = 5;

	// Create a reference b that points to a.
	int & b = a;

	a = 7;

	// This prints 5!
	std::cout << b << std::endl;
	// A reference is transparent (acts like the value)
	// Non-Null
	// Non-reseatable (always points to the same place and cannot change what it refers to)	
	b = 9;

	std::cout << a << std::endl;
	return 0;
}
// Unlike pointers you cannot have a null reference.
//
//
//
void f(void) {
	// This integer lives at Add_1
	int a = 5;

	// This integer lives at Add_2
	int b = 7;

	// This integer reference lives at Add_3 points to Add_1
	int & c = a;

	// This integer reference lives at Add_4 points to Add_1
	int & d = a;

	// After this c still lives at Add_3 and still points to Add_1
	// But the value at Add_1 is now 8
	c = 8;
};

int double_pbv(Behemoth i) {
	return i.vals[0] * 2;
}

int double_pbr(Behemoth & i ) {
	return i.vals[0] * 2;
}

int main_2(void) {
	Behemoth b;

	int r = double_pbr(b);

	std::cout << r << std::endl;

	return 0;
}




int main_time(void) {
	Behemoth b;
	b.vals[0] = 10;

	auto t1 = std::chrono::high_resolution_clock::now();
	int r1 = double_pbv(b);
	auto t2 = std::chrono::high_resolution_clock::now();
	int r2 = double_pbr(b);
	auto t3 = std::chrono::high_resolution_clock::now();

	auto nano_pbv = std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count();
	auto nano_pbr = std::chrono::duration_cast<std::chrono::nanoseconds>(t3-t2).count();

	std::cout << "Pass by val found : " << r1 << " and took " << nano_pbv << "ns." << std::endl;
	std::cout << "Pass by ref found : " << r2 << " and took " << nano_pbr << "ns." << std::endl;

	return 0;
}


int main(void) { 
	int a = 5;
	// b is read only
	const int & b = a;
	// Fails at compile time	
	b = 2;
	return 0;
}



