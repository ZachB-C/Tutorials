#include <iostream>
#include <cmath>

template<typename T>
T constexpr PI = std::acos(-T(1)) ;

template<typename T>
const T EPSILON = 0;

template<>
const float EPSILON<float> = 1e-6;

template<>
const double EPSILON<double> = 1e-13;


int main() {
	// 3. 14159 26536 89793 23846
	std::cout << (PI<int>-3) << "\n";
	std::cout << PI<float> << "\n";
	std::cout << PI<double> << "\n";
	std::cout << (PI<long double>-3.14159) << "\n";

	std::cout << EPSILON<int> << std::endl;
	std::cout << EPSILON<float> << std::endl;
	std::cout << EPSILON<double> << std::endl;
}
