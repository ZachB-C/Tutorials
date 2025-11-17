// Checks if two strings are permutations of each other.
#include <iostream>
#include <unordered_map>
// Alternative method would be to sort both strings so
// that they are in the same order, then cycle through 
// and compare O(NLog(N)) as cycle through is O(N)
// This version is O(N) to build hash table and to cycle through it


// Helper functions
bool isPermutation( std::string string1, std::string string2 );


int main() {
	std::string input_1 = "combination";
	std::string input_2 = "biationcomn";
	
	if( isPermutation(input_1, input_2) ) {
		std::cout<<input_1<<" is a permutation of "<<input_2<<"\n";
	} else {
		std::cout<<input_1<<" is not a permutation of "<<input_2<<"\n";
	}


	input_1 = "combination";
	input_2 = "biatoncomnl";
	
	if( isPermutation(input_1, input_2) ) {
		std::cout<<input_1<<" is a permutation of "<<input_2<<"\n";
	} else {
		std::cout<<input_1<<" is not a permutation of "<<input_2<<"\n";
	}

	input_1 = "combination";
	input_2 = "biatoncomn";
	
	if( isPermutation(input_1, input_2) ) {
		std::cout<<input_1<<" is a permutation of "<<input_2<<"\n";
	} else {
		std::cout<<input_1<<" is not a permutation of "<<input_2<<"\n";
	}


	return 0;
}


bool isPermutation(std::string string1, std::string string2) {
	size_t length1 = string1.length();
	size_t length2 = string2.length();
	// Create two structures to store all the characters
	// which can be compared.
	std::unordered_map<char, int > ch_counts1;
	std::unordered_map<char, int > ch_counts2;
	
	// First check they are the same length, if not they are 
	// not permutations.
	if (length1 != length2 ) { return false;}
	// Now if they are the same length hash them and count the 
	// number of characters.
	for (char ch1: string1)  {++(ch_counts1[ch1]);}
	for (char ch2: string2) {++(ch_counts2[ch2]);}

	// Because we have already checked they have the same length
	// can just loop over the keys of one of the hash functions
	for (auto& [key, value] : ch_counts1 ) {
		if( value != ch_counts2[key] ) {
			return false;
		}
	}
	// If it passes all the tests then it is a permutation.
	return true;

}
