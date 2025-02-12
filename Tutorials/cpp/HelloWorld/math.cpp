#include <iostream>

int main() {
	int x = 10;
	// Set y then increment x; x=11, y=10
	int y = x++;
	// Increment x then set y; x=12, y=12
	y = ++x 
	int z = x % y;
	++x;
	std:: cout << x;
	std:: cout << '\n';

	std:: cout << z;
	std:: cout << '\n';
	return 0;
}
