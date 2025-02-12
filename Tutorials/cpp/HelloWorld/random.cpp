#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	// Can use zero instead of nullptr
	// long elapsedSeconds = time(nullptr); // Seconds since Jan 1 1970
	// srand(elapsedSeconds);
	srand(time(nullprt));
	// Modulus to limit range.
	// rand is limited randomness 
	// suggest to use C++11 random library instead
	int number {rand() % 10};
	cout << elapsedSeconds << endl;
	cout << number << endl;
	return 0;
}
