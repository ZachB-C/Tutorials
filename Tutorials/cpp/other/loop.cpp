#include <iostream>
/*
 * Continue: jumps to next iteration of loop.
 * Break: terminates loop and runs code after loop.
 * Return: breaks out of current function and returns value if not return void.
 */

float max(float a, float b, float c) {
	if (a<b) {
		if (b>c) return b;
		else return c;
	} else if (b>c) return b;
	else return a;
}
int main() {
	// For loops
	for (int i = 0, j = 1; i < 4; ++i) {
		printf("print");
		j += i;
	}

	for (int i = 0, j = 0; i < 10; i++, j = i*i) {
		std::cout << i << "^2 is " << j << "\n";
	}
	// Range Based for loops
	int v[4] = {1, 2, 3, 4};
	int sum = 0;
	for (int a : v) { sum += a; } // For a in v
	
	int n = 21;
	// while loop
	printf("First Attempt");
	while (n != 1) 
		if (0 == n%2) n /= 2;
		else n = 3*n + 1;
		std::cout << n << std::endl;
	n = 21;
	printf("Second Attempt");
	while (n != 1) {
		if (0 == n%2) n /= 2;
		else n = 3*n + 1;
		std::cout << n << std::endl;
	}
	//do while
	do {
		if (0 == n%2) n /= 2;
		else n = 3*n + 1;
	} while (n != 1);
	// Will fail for n<= 0; or, if collatz conjecture is false, for some positive n
	while (1) {// naively, the loop will never finish (unless a break or return is reached).	 
		 if (n==1) break;
		 if (0 == n%2) {
			 std::cout << n << "\n";
			 n /= 2;
			 continue;
		 } 
		 n = 3*n + 1; // Will not execute unless n is odd.
	}
	
	int a = 10;
	for (;;) {
		std::cout << a << std::endl;
		a--;
		if (a == 0) break;
	}	
	
	for (int aa = 10; aa != 0; --aa) std::cout << aa <<std::endl;
	
	printf("Float problem\n");
	std::cout << max(0, 1, 2) << std::endl;
	std::cout << max(0, 2, 1) << std::endl;
	std::cout << max(1, 2, 0) << std::endl;

	printf("Missing combinations.");
	std::cout << max(2, 1, 0) << std::endl;
	std::cout << max(2, 0, 1) << std::endl;
	std::cout << max(1, 0, 2) << std::endl;
	printf("Extra combinations.");
	std::cout << max(0, 1, 0) << std::endl;
	std::cout << max(0, 0, 1) << std::endl;
	std::cout << max(1, 0, 0) << std::endl;


	return 0;
}


