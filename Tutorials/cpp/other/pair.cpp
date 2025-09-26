#include <utility> // pair
#include <iostream>
#include <tuple> // tuple

int main(void) {
	std::pair<int, double> v {5, 11.73};
	std::tuple<int, double, bool, float> w {5, 11.73, true, -5.81};
	v.first = 8;
	std::cout << "Integer part: " << v.first << ", double part: " << v.second << std::endl;
	
	std::get<0>(v) = 8;
	std::get<2>(v) = false;
	std::cout << "Integer part: " << std::get<0>(v) << std::endl;
	std::cout << "Double part: " << std::get<1>(v) << std::endl;
	std::cout << "Boolean part: " << std::get<2>(v) << std::endl;
	std::cout << "Float part: " << std::get<3>(v) << std::endl;

	return 0;
}
