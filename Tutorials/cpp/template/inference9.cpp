#include <iostream>
#include <array>
// Do not overuse auto as types add to readability of the code.
// This is hiding templates where we put auto into the arguments
auto accumulate( const auto & col, auto init)
{
	// decltype would preserve the const and & nature of variables
	auto res = init;
	for (auto elem : col)
	{res += elem; }
	return res;
}

void scale( auto & col, auto factor) 
{
	for ( auto & elem : col)
	{elem *= factor ; }
}

int main() 
{
	std::array col = {1, 2, 3, 4, 5};
	std::cout << accumulate(col, 0) << std::endl;
	scale(col, 2);
	auto first = col[0];
	std::cout << first << std::endl;
}
