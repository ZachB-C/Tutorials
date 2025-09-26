#include <iostream>
#include <array>



int main() 
{
	std::array col = {1, 2, 3, 4, 5};

	auto first = col[0];
	auto sz = col.size();
	int sum = 0;
	for (auto elem : col )
	{ sum += elem; }

	std::cout << "First: " << first << std::endl;
	std::cout << "Mean: " << sum/sz << std::endl;
}
