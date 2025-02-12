#include <iostream>

using namespace std;

int main() {
	// Statically typed: type cannot change (Java, c#)
	// Dynamically typed: Python, JavaScript, Ruby
	// B = Billion
	// Type		Bytes		Range
	// int		4		-2B to 2B
	// short	2		-32,768 to 32,767
	// long		4		-2B to 2B
	// long long	8
	//
	// float	4		-3.4E38 to 3.4E38
	// double	8		-1.7E308 to 1.7E308
	// long double	8		-3.4E932 to 1.7E4832
	// bool		1		true/false
	// char		1		single character
	
	// Need F for float values upper or lower case
	// L for long or compiler will use int by default.
	// Can use auto instead of actual name. Auto keyword
	double price = 99.99;
	float interestRate = 3.67f;
	long fileSize = 90000L;
	char letter = 'a';
	bool isValid = false;
	
	// brace initialisation
	// {} initialises at zero, 
	// {1.2} initialises at a number and gives an error
	// if type does not matter
	int number {};
	cout << number;

	// System		Digits		Example
	// Decimal (Base 10) 	0-9		255
	// Binary (Base 2)	0,1		1111111
	// Hexadecimal		0-9,A-F		FF
	//
	// Colors
	// Unsigned integers are dangerous
	unsigned int number_positive = -255;
	number = 0b11111111;
	cout << number << endl;
	
	number = -0xFF;
	cout << number << endl;	

	// Narrowing
	//
	number = 1'000'000;
	// Won't compile if we use brace initialiser.
	//short another{number};
	//cout << another << endl;

	short newNumber = 100;
	int another {newNumber};
	cout << another << endl;

	return 0;
}
