#include <iostream>
#include <numbers> // std::numbers
#include <cmath>
#include <cfloat>
#include <iomanip>
#include <cstdio>

//using namespace std;

int main() {
	const double pi_value = std::numbers::pi;
	double radius;
	double area; 

	std::cout << "Circle radius: " << std::endl;
	std::cin >> radius;

	area = pi_value * std::cmath::pow(radius, 2);
	std::cout << "Circle area: " << area << std::endl;

	return 0;
}
