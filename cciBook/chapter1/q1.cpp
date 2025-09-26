// Note: could introduce something that allows one to 
// ignore spaces. Just check if a space and if so reject
// it. Current implementation ignores spaces, this could
// be made optional and other characters could also be 
// ignored, if there are many it would be better to put
// them in a list. If we don't want to use hash tables we could sort the list and look for consecutive pairs.
// Header files
#include <iostream>
#include <unordered_map>


// Helper functions
// Should default to zero if we wish to default to
// another value need to define struct e.g.
struct CountInt{
	int count = 0;
};
// But for this problem could just use int as should 
// default to the correct value
bool is_unique(std::string test_string) {
	std::unordered_map<char, CountInt> ch_counts;

	for (char ch : test_string) {
		// Increment the count and then check if 
		// it is greater than 1 if so exist
		if ((++(ch_counts[ch].count) > 1)
			&& (ch != ' ')) {
			std::cout<<ch<<": "
				<<ch_counts[ch].count
				<<"\n";
			return false;
		} else {
			std::cout<<ch;
		}
	}
	std::cout<<'\n';
	return true;

}

// This is very inefficient should find a better scaling
// sorter.
std::string string_sorter(std::string input_string) {
	std::string sorted_string = "";
	std::cout << sorted_string << "\n";
	bool found = false;
	// Initialise sorted character as 'a' in case 
	// we deal with an empty list.
	for (char ch : input_string) {
		found = false;
		for ( char s_ch : sorted_string ) {
			if ( ch < s_ch ) 
			{
				sorted_string = (
					ch + sorted_string
					);
				found = true;
				break;
			}
		}
		if ( found == false) {
			sorted_string = sorted_string + ch;
		}
	}
	


	return sorted_string;
}

bool is_unique_str(std::string test_string) {
	std::string sorted_string = string_sorter(
			test_string);
	std::cout << "Sorted: " << sorted_string << "\n";
	bool first = true;
	for( char ch : sorted_string ) {
		if( first ) {
			char prev_ch = ch;
			continue;
		} elif( prev_ch == ch && ch != ' ') {
			return false;
		}		
	}
	return true;
}

// main() function to implement
int main() {
	std::string test_string = "Hello World 1";
	std::cout << test_string << '\n';
	bool success = is_unique(test_string);
	bool success_2 = is_unique_str(test_string);
	std::cout << success_2 << std::endl;
	if (success == true) {
		std::cout<<"Unique\n";
	}
	else {
		std::cout<<"Not Unique\n";
	}
	
	test_string = "Hey World 1";
	std::cout << test_string << '\n';
	success = is_unique(test_string);
	if (success == true) {
		std::cout<<"Unique\n";
	}
	else {
		std::cout<<"Not Unique\n";
	}
	return 0;
}
