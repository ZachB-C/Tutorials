#include <iostream>
//#include <numbers> // std::numbers
#include <cmath>
//#include <cfloat>
//#include <iomanip>
//#include <cstdio>

using namespace std;

int main() {
	const double pi_value = 4*atan(1);
	double radius;
	double area; 

	cout << "Circle radius: ";
	cin >> radius;

	area = pi_value * pow(radius, 2);
	cout << "Circle area: " << area << endl;

	return 0;
}
