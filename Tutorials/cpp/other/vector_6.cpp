#include <iostream>
#include <vector>

int main() {
	std::vector<double> n_vector {-1.0, -2.0, -3.0, -5.0};

	std::cout << "Vector initial size is " << n_vector.size() << std::endl;
	n_vector.clear();
	std::cout << "After a clear() the vector size is " << n_vector.size() << std::endl;

	return 0;
}
/* vector<double> v; v.reserve(1000000); will reserve a million elements in memory so save time during 
* execution if we add elements to v. push_back must copy all data if there is not space as vectors must
* be contiguous. 
*/
