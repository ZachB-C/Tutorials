#include <iostream>
#include <vector>


// For this to work the definition and declaration of the function must
// be in the same file.
auto accumulate( const std::vector<int> & col, const int & init)
{
	// decltype would preserve the const and & nature of variables
	auto res = init;
	for (auto elem : col)
	{res += elem; }
	return res;
}


int main() 
{
	std::vector col = {1, 2, 3, 4, 5};
	std::cout << accumulate(col, 0) << std::endl;
}
