#include <iostream>

using namespace std;

int main() {
	double tempFar;
	double tempCent;

	cout << "Enter a temperature in Fahrenheit: ";
	cin >> tempFar;

	tempCent = (tempFar - 32) * 5/9;
	cout << tempFar << "\u2109 = " 
	     << tempCent << "\u2103" << endl;

	return 0;
}
