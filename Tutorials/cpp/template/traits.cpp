#include <iostream>

template<typename T>
class Traits {};

template<>
class Traits<float> {
	public:
		static constexpr float EPSILON = 1e-6;
};

template<>
class Traits<double> {
	public:
		static constexpr double EPSILON = 1e-13;
};

int main() {
	std::cout << Traits<float>::EPSILON << std::endl;
	std::cout << Traits<double>::EPSILON << std::endl;
}
