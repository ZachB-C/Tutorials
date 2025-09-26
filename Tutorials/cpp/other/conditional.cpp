#include <iostream>


enum Lang {FRENCH, GERMAN, ENGLISH, OTHER};

int main() {
	int a = 0;
	int b = 1;
	
	if (a<b) {
		a = b;
	}
	else if (a>b) {
		b = a;
	}
	else { 
		a = b + 1;
	}

	switch (a) {
		case 0: a+=1; break;
		case 2: a/=2; break;
		case 1: a-=1; break;
		default : a-=1; break;
	}
	switch (language) {//language is one of the elements of the Lang enum
		case FRENCH:
			printf("Bonjour");
			break;
		case GERMAN:
			printf("Guten tag");
			break;
		case ENGLISH:
			prinf("Good morning");
			break;
		default:
			printf("I do not speak your language.");
			break;
	}

	switch (c) {
		case 'a':
			f();
			[[fallthrough]]; // Warning supressed when this 
					 // line is added
					 // Otherwise lack of break will result
					 // in warning.
		case 'c':
			h();
		}

	Value val = GetValue();
	if (val==1) {
		a = val;
	} 
	else {
		a = 0;
	}

	if (Value valTwo = GetValue(); val==1) {
		a = val;
	}
	else {
		a = 0;
	}




	return 0;
}


int collatz(int a) {
	if (a<=0) {
		std::cout << "Not supported" << std::endl;
		return 0;
	} else if (a == 1) {
		return 1;
	} else if (a%2 == 0) {
		return collatz(a/2);
	} else {
		return collatz(3*a+1);
	}
}

int collatz_one_line(int a) {
	return a==1 ? 1 : collatz(a%2 ? 3*a+1 : a/2)
}





