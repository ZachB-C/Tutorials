#include <iostream>

struct Point {
	int x = 5; // Could specify only one of the two if we would like.
	int y = 10;
};

int printPoint(Point p, char name) {
	std::cout << name << " = ( " << p.x << ", " << p.y << "); " << std::endl;
	return 0;
}	

int manhattan(Point p) {
	return std::abs(p.x) + std::abs(p.y);
}

int main(void) {
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


	printPoint(a, 'a');
	printPoint(b, 'b');
	printPoint(c, 'c');
	printPoint(d, 'd');
	printPoint(e, 'e');
	printPoint(f, 'f');
	printPoint(g, 'g');
	printPoint(h, 'h');
	
	Point p = {-11, 17};
	std::cout << "The manhattan distance is: " << manhattan(p) << std::endl;

	return 0;
}
