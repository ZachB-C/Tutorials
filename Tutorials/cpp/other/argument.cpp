#include <iostream>
#include <vector>
#include <tuple>

// With return type
int square(int a) {
	return a*a;
}
// Multiple parameters
int multi(int a, int b) {
	return a*b;
}
// No parameter
void hello() {
	std::cout << "Hello World" << std::endl;
}
// No return
void log(char* msg) {
	std::cout << msg << std::endl;
}

// Exchange arguments

// By value
void display( std::vector<int> col)
{
	std::cout << "[ " ;
	for( unsigned i = 0 ; i < col.size() ; ++i)
	{ std::cout << col[i] << " " ; }
	std::cout << "]" << std::endl ;
}


int main_1()
{
	std::vector col = {1,2,3,4,5};
	display(col) ;
}

// By reference
void scale( std::vector<int> & col, int factor) {
	for ( unsigned i = 0 ; i < col.size() ; ++i )
	{col[i] *= factor ; }

}

// By constant reference
void display( const std::vector<int> & col )
{
	std::cout << "[ ";
	for( unsigned i = 0 ; i < col.size() ; ++i )
		{std::cout << col[i] << " " ; }
	std::cout << "]" << std::endl;
}

// Return results
// By value
std::vector<int> scale(std::vector<int> col, int factor) {
	for (unsigned i = 0; i < col.size() ; ++i )
	{ col[i] *= factor ; }
	return col;
}

// Composite result
std::tuple<double, double, double> analyse( const std::vector<double> & data )
{
	double min {999.}, max {0}, sum {0} ;
	for( unsigned i = 0 ; i < data.size(); ++i)
	{ 
		sum += data[i];
		if (data[i]<min) min = data[i];
		if (data[i]>max) max = data[i];
	}
	return {min, max, sum/data.size()};
}

int main()
{
	std::vector<double> data = {1., 2., 3., 4., 5., 6.};
	double min, max, mean;
	std::tie(min,max,mean) = analyse(data);

	std::cout << "min : " << min << std::endl ;
	std::cout << "max : " << max << std::endl;
	std::cout << "mean: " << mean << std::endl;

}

