#include <iostream>
#include <cmath>

int main_const(void) {
	int a = 5;
	const int & b = a;

	std::cout << b << std::endl;

	a = 7;

	std::cout << b << std::endl;

	return 0;

}

void sincos(double in, double & sin, double & cos) {
	sin = std::sin(in);
	cos = std::cos(in);
}

int main(void) {
	double sin, cos;
	sincos(0.3 * 3.1415, sin, cos);
	std::cout << sin << " , " << cos << std::endl;
	return 0;
}
