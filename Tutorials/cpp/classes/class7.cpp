#include <iostream>
#include <cmath>


class Point {
public:
	Point() : x(1.0), y(0.0) {
	}
	Point(double phi, double r) : x(std::cos(phi)), y(std::sin(phi)) {
	}	
	double getX() {
		return x;
	}
	double getY() {
		return y;
	}
	bool setCartesian(double xn, double yn) {
		if( std::abs(1.0 - std::hypot(yn, xn)) < 0.0001) {
			x = xn;
			y = yn;
			return true;
		} else {
			return false;
		}
	}
private:
	double x;
	double y;
};

int main(void) {
	Point p(1.445, 6);
	std::cout << "Point is (" << p.getX() << ", " << p.getY() << ")" << std::endl;

	bool r1 = p.setCartesian(0.866025404, 0.5);
	std::cout << "Attempt 1 " << (r1 ? "succeeded" : "failed") << std::endl;

	bool r2 = p.setCartesian(6.0, 0.0);
	std::cout << "Attempt 2 " << (r2 ? "succeeded" : "failed") << std::endl;


	std::cout << "Point is (" << p.getX() << ", " << p.getY() << ")" << std::endl;
	return 0;
}
