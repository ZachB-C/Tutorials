#include <iostream>
#include <optional>
//#include <string>
#include <type_traits> // For is_void check

std::optional<int> divide(int n, int d) {
	if (d==0) {
		// Return a "nothing" value
		return {};
	}

	return n/d;
}
/*
 * This does not work I think because it one cannot use optionals this way.
void printNotVoid(std::optional<int> value, const char* name) {
	if (std::is_void<void>::value) {
		std::cout << name << ": " << value << std::endl;
	} else {
		std::cout << name << ": Invalid" << std::endl;
	}
}
*/
// Optional objects can be converted to boolean values so we can trigger
// an if on them. True for full False for empty
void printNotVoid(std::optional<int> variable, const char* name) {
	if (variable) {
		std::cout << name << ": " << variable.value() << std::endl;
	} else {
		std::cout << name << ": Invalid" << std::endl;
	}
}

int main(void) {
	std::optional<int> r1 = divide(9, 3);
	std::optional<int> r2 = divide(9, 0);

	printNotVoid(r1, "Result 1");
	printNotVoid(r2, "Result 2");

	return 0;
}


