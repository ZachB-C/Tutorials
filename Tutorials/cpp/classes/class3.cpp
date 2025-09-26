#include <iostream>

class Point {
public:
	double getX() {
		return x;
	}
	double getY() {
		return y;
	}
	void setCartesian(double xn, double yn) {
		x = 42.0;
		y = 42.0;
	}
private:
	double x;
	double y;
};

int main(void) {
	Point p;
	p.setCartesian(5.0, 9.0);
	std::cout << p.getX() << " , " << p.getY() << std::endl;
	return 0;
}
