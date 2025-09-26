#include <iostream>

int a = 3;

int main() {
	switch (a) {
		case 1: printf("a == 1");
		case 3: printf("a == 3");
		case 4: printf("a == 4");
		default: printf("a is not 1, 3, or 4");
	}
	return 0;	
}
