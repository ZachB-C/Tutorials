// Permutation of a palindrome, we need to check if the input is a palandrome that has been permuted.
// So if it is a palindrome then every letter (but one if there are an odd number of characters) must occur an even
// number of times. The example given ignores spaces so we don't need to consider them.
// Easiest method is probably to count letters and hash it and then just verify. We could perhaps be slightly cleverer
// and just count the number of odd letters in another variable, if this is greater than 0 
// (or one for odd numbers of characters) then we cannot have a palindrome.
// Problem with uppercase letters need to convert to lowercase, extra issue could arise if there are symbols.
#include <iostream>
#include <vector>
#include <unordered_map>

// Helper functions
bool isPalindrome( std::string string_in );
int makePalindromes( std::unordered_map<char, int> character_counts, char odd_char);
bool isPalindromeBit( std::string string_in);

int main() {
	std::string test_string = "Tact coa";
	bool palindrome = isPalindrome( test_string);
	std::cout<<test_string<<std::endl;
	std::cout<<palindrome<<std::endl;
	std::cout<<isPalindromeBit( test_string) <<std::endl;
	
	test_string = "Tac coa";
	palindrome = isPalindrome( test_string);
	std::cout<<test_string<<std::endl;
	std::cout<<palindrome<<std::endl;
	std::cout<<isPalindromeBit( test_string) <<std::endl;
	
	test_string = "Trainer cheesburger";
	palindrome = isPalindrome( test_string);
	std::cout<<test_string<<std::endl;
	std::cout<<palindrome<<std::endl;
	std::cout<<isPalindromeBit( test_string) <<std::endl;
	
	test_string = "Was it a cat I saw";
	palindrome = isPalindrome( test_string);
	std::cout<<test_string<<std::endl;
	std::cout<<palindrome<<std::endl;
	std::cout<<isPalindromeBit( test_string) <<std::endl;
	
	test_string = "Was it a at I saw";
	palindrome = isPalindrome( test_string);
	std::cout<<test_string<<std::endl;
	std::cout<<palindrome<<std::endl;
	std::cout<<isPalindromeBit( test_string) <<std::endl;

	
	return 0;
}

bool isPalindrome(std::string string_in) {
	std::unordered_map<char, int> letter_counts;
	
	for( char ch: string_in ) {
		if( ch != ' ') {
			ch = tolower(ch);
			++letter_counts[ch];
		}
	}

	size_t n_odd = 0;
	char odd_char = ' ';
	for( auto [key, value] : letter_counts) {
		//std::cout<<key<<std::endl;
		if (value % 2 != 0) {
			++n_odd; 
			odd_char = key;
			//std::cout<<odd_char<<key<<" "<<n_odd<<" Value: "<<value<<std::endl;
		}
	}
	if (n_odd > 1) {
		return false;
	} else {
		makePalindromes( letter_counts, odd_char );
		return true;
	}
}


int makePalindromes( std::unordered_map<char, int> letter_counts, char odd_char) {
	int n_repetitions = 0;
	int i = 0;
	// These will be very simple 1 and 2 will just be inverses of each other.
	std::string pali_addition1 = "";
	std::string pali_addition2 = "";
	// Do a very simple palindrome where we put all the same letters
	// next to each other.
	for (auto [key, value] : letter_counts ) {
		if( key != odd_char ) {
			n_repetitions = value/2;
			for( i = 0; i< n_repetitions; ++i) {
				pali_addition1 = pali_addition1 + key;
				pali_addition2 = key + pali_addition2;
			}		
		}

	}
	std::string palindrome1 = pali_addition1 + odd_char + pali_addition2;
	std::string palindrome2 = pali_addition2 + odd_char + pali_addition1;
	std::cout<<"True (permutations: \""<<palindrome1<<"\", \""<<palindrome2<<"\", etc.)"<<std::endl;

	return 0;
}	

// Assumes there are only upper and lowercase letters and no weird symbols, 
// spaces are ignored. Could this be an array.
bool isPalindromeBit( std::string string_in) {
	std::vector<bool> alphabet(26);
	
	for( char ch : string_in ) {
		if( ch == ' ') { continue;}
		//std::cout<<ch<<std::endl;
		// Must get rid of signs
		ch = std::tolower(ch);
		//std::cout<<ch<<std::endl;
		//std::cout<<ch - 'a'<<std::endl;
		//std::cout<<alphabet[ch-'a']<<std::endl;
		alphabet[ch - 'a'] = !alphabet[ch - 'a'];
		//std::cout<<alphabet[ch-'a']<<std::endl;

		//std::cout<<"STOP"<<std::endl;
	}
	// If we have an odd number of more than one letter then 
	// we cannot make a palindrome.
	int n_odd = 0;
	for( bool parity : alphabet) {
		if(parity == 1) {
			if(n_odd == 1) {
				return false;
			} else {
				++n_odd;
			}
		}
	}

	return true;
}

