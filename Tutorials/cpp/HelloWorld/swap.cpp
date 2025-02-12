#include <iostream>

using namespace std;

int main() {
	int a = 1;
	int b = 2;
	int temp = 0;

	temp = b;
	b = a;
	a = temp;
		
	cout << b;
	cout << '\n';
	cout << a;
	cout << '\n';

	return 0;
}
