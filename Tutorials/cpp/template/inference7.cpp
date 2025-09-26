#include <iostream>
#include <vector>

int accumulate( const std::vector<int> & col, const int & init)
{
	// decltype would preserve the const and & nature of variables
	auto res = init;
	for (auto elem : col)
	{res += elem; }
	return res;
}

void scale( std::vector<int> & col, int factor) 
{
	for ( auto & elem : col)
	{elem *= factor ; }
}

int main() 
{
	std::vector col = {1, 2, 3, 4, 5};
	std::cout << accumulate(col, 0) << std::endl;
	scale(col, 2);
	auto first = col[0];
	std::cout << first << std::endl;
}
