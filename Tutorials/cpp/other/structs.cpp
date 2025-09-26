#include <iostream>



struct Point {
	int x;
	int y;
};

int main(void) {
	Point p = {5, 7};

	p.y = 9;

	// Default constructor
	Point a;

	// Default constructor with two assignments
	Point b;
	b.x = 5;
	b.y = 7;

	// Default constructor with one assignment
	Point c;	
	c.y = 7;

	// Initialisation with empty initializer list
	Point d {};

	// Initialisation with non-empty initiailizer list:
	Point e {5, 7};

	// Initialisation with named initializer list:
	Point f {.x=5, .y=7};

	// Initialisation with partial named initializer list:
	Point g {.y=7};

	// Assignment with initializer list:
	Point h;
	h = {.x=5, .y=7};

	std::cout << "a: (" << a.x << ", " << a.y << "); "
		<< "b: (" << b.x << ", " << b.y << "); "
		<< "c: (" << c.x << ", " << c.y << "); "
		<< "d: (" << d.x << ", " << d.y << "); "
		<< "e: (" << e.x << ", " << e.y << "); "
		<< "f: (" << f.x << ", " << f.y << "); "
		<< "g: (" << g.x << ", " << g.y << "); "
		<< "h: (" << h.x << ", " << h.y << "); "
	 << std::endl;
}
