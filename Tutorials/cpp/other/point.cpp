#include <iostream>

struct Point {
	int x;
	int y;
};

int main(void) {
	Point p = {5,7}; // Point p; p = {5, 7};

	p.y = 9;

	std::cout << "The point is: (" << p.x << ", " << p.y << ")" 
		<< std::endl;

	int a = 5; // int a; a = 5;
	
	int b;
	std::cout << b << std::endl;

	return 0;
}


