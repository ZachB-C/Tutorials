// Note: could introduce something that allows one to 
// ignore spaces. Just check if a space and if so reject
// it. Current implementation ignores spaces, this could
// be made optional and other characters could also be 
// ignored, if there are many it would be better to put
// them in a list. If we don't want to use hash tables we could sort the list and look for consecutive pairs.
// Header files
#include <iostream>
#include <unordered_map>
#include <string>

// Helper functions
std::string sortString( std::string input_string);
std::string mergeStrings( std::string input_string1, std::string input_string2);
bool isUnique(std::string input_string); // Checks all characters (except space) in string are unique.
bool isUniqueStr(std::string input_string);  // Checks all characters (except space) in string are unique.
// Does not use hash functions.



// Should default to zero if we wish to default to
// another value needed to define struct e.g.
struct CountInt{
	int count = 0;
};

// main() function to implement
int main() {
	std::string test_string = "Hello World 1";
	std::cout << test_string << '\n';
	std::string sorted_string = sortString(test_string);
	std::cout << "Sorted: " << sorted_string << '\n';
	bool success = isUnique(test_string);
	bool success_2 = isUniqueStr(test_string);

	if (success == true) {
		std::cout<<"Unique\n";
	}
	else {
		std::cout<<"Not Unique\n";
	}
	if (success_2 == true) {
		std::cout<<"UniqueStr\n";
	}
	else {
		std::cout<<"Not UniqueStr\n";
	}

	test_string = "Hey World 1";
	std::cout << test_string << '\n';
	std::cout << "Sorted: " 
		<< sortString(test_string) << '\n';
	success = isUnique(test_string);
	success_2 = isUniqueStr(test_string);
	if (success == true) {
		std::cout<<"Unique\n";
	}
	else {
		std::cout<<"Not Unique\n";
	}
	if (success_2 == true) {
		std::cout<<"UniqueStr\n";
	}
	else {
		std::cout<<"Not UniqueStr\n";
	}
	return 0;
}
// But for this problem could just use int as should 
// default to the correct value
bool isUnique(std::string input_string) {
	std::unordered_map<char, CountInt> ch_counts;

	for (char ch : input_string) {
		// Increment the count and then check if 
		// it is greater than 1 if so it exists
		if ((++(ch_counts[ch].count) > 1)
			&& (ch != ' ')) {
			std::cout<<", "<<ch<<" repeats ("
				<<ch_counts[ch].count
				<<")\n";
			return false;
		} else {
			std::cout<<ch;
		}
	}
	std::cout<<'\n';
	return true;

}



// implement a merge sort or quick sort, I think I will
// do merge sort.
std::string sortString(std::string input_string) {
	size_t string_length = input_string.length();
	if ( string_length <= 1 ) {
		return input_string;
	} else {
		return mergeStrings( 	
				sortString(input_string.substr(0, string_length/2)),
				sortString(input_string.substr(string_length/2 ))
			);
		// Using only the start position goes until the end of the string.			
	}
}


std::string mergeStrings(std::string string1, std::string string2) {
	std::string merged_string = "";
	size_t length1 = string1.length();
	size_t length2 = string2.length();
	size_t i1 = 0;
	size_t i2 = 0;
	// Merge until all of one string is used up.
	while ( i1 < length1 && i2 < length2 ) {
		if( string1[i1] < string2[i2] ) {
			merged_string = merged_string + string1[i1];
			i1++;
		} else {
			merged_string = merged_string + string2[i2];
			i2++;
		}
	}
//	std::cout << "First stage " << i1 << ' ' << i2  << ' ' << length1  << ' ' << length2 << '\n';
	// Append the remaining string to the merged string.
	if( i1 < length1 ) {
		merged_string = merged_string + string1.substr(i1);
	} else if ( i2 < length2 ) {
		merged_string = merged_string + string2.substr(i2);
	}

	return merged_string;
}

bool isUniqueStr(std::string test_string) {
	std::string sorted_string = sortString(
			test_string);
//	std::cout << "Sorted: " << sorted_string << "\n";
	bool first = true;
	char prev_ch = sorted_string[0];
	for( char ch : sorted_string ) {
		if( first ) {
			first = false;
			continue;
		} else if( prev_ch == ch && ch != ' ') {
			return false;
		} else {
			prev_ch = ch;
		}		
	}
	return true;
}

