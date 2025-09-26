#include <iostream>
#include <array>

int main() {
	std::array<double, 4> four_vector {2., 3., 4., -10.};
	std::cout << "This 4-vector has time component " << four_vector[3] << std::endl;
	
	four_vector[3] = 7.5;
	std::cout << "This 4-vector now has time component " << four_vector.at(3) << std::endl;
	
	std::cout << "Size of 4-vector " << four_vector.size() << std::endl;
	

	return 0;
}
