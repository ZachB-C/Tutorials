#include <iostream>

class Point {
public:
	double x;
	double y;
};

int main(void) {
	Point p;
	std::cout << p.x << " , " << p.y << std::endl;
	return 0;
}
