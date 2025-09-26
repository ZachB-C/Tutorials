#include <iostream>
#include <cmath>

class Point {
public:
	double getX() {
		return r * std::cos(phi);
	}
	double getY() {
		return r * std::sin(phi);
	}
	void setCartesian(double xn, double yn) {
		phi = std::atan2(yn, xn);
		r = std::hypot(yn, xn);
	}
private:
	double phi;
	double r;
};

int main(void) {
	Point p;
	p.setCartesian(5.0, 9.0);
	std::cout << p.getX() << " , " << p.getY() << std::endl;
	return 0;
}
