// Header files
#include <iostream>

// main() function to implement
int main() {
	std::string test_string = "Hello World";
	//std::cout<<test_string<<'\n';
	size_t string_length = test_string.length();
	std::cout << string_length << ' ' <<string_length/2 << '\n';
	std::cout<<"Hi "<<'\n';
	int ch_int_1 = (int) 'a';
	int ch_int_2 = (int) 'b';
	std::cout<<ch_int_1<<" "<<ch_int_2<<" "<<ch_int_2-ch_int_1<<std::endl;
	return 0;
}
