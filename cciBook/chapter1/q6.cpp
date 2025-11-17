// Now we need to compress a string of characters by replacing a string of the same character with 
// the character followed by the number of times it occurs, if the compressed string is not shorter 
// than the original then return the original string. We can assume only upper and lower case
// characters are permitted. Not sure why this last bit makes things easier. As I was going to 
// just walk through the string. Maybe there is a search function that could save time, but I
// think it must be at least order N? Check speed of length function is it order N scaling or not.
// I think the alphabet thing is to avoid confusion in the notation, if there were some numbers 
// there it might be difficult.
// Remember the number may not be a single character if we have more than 9 repetitions, 
// should handle this
#include <iostream>
#include <string>

// Helper functions
std::string stringCompressor(std::string string_in);
std::string stringCompressorEfficient(std::string string_in);

int main() {
	std::string test_string = "";
	std::string correct_answer = "";
	std::string compressor_output = "";

	test_string = "aabcccccaaa";
	correct_answer = "a2b1c5a3";
	compressor_output = stringCompressor(test_string);
	std::cout<<"Target:\t"<<test_string<<" -> "<<correct_answer<<std::endl;
	std::cout<<"Result:\t"<<test_string<<" -> "<<compressor_output<<std::endl;
	if(correct_answer == compressor_output) {
		std::cout<<"Success"<<std::endl;
	} else {
		std::cout<<"Failure"<<std::endl;
	}

	test_string = "aabbccddeeffgg";
	correct_answer = "aabbccddeeffgg";
	compressor_output = stringCompressorEfficient(test_string);
	std::cout<<"Target:\t"<<test_string<<" -> "<<correct_answer<<std::endl;
	std::cout<<"Result:\t"<<test_string<<" -> "<<compressor_output<<std::endl;
	if(correct_answer == compressor_output) {
		std::cout<<"Success"<<std::endl;
	} else {
		std::cout<<"Failure"<<std::endl;
	}


	test_string = "aaaaxxbbbbc";
	correct_answer = "a4x2b4c1";
	compressor_output = stringCompressorEfficient(test_string);
	std::cout<<"Target:\t"<<test_string<<" -> "<<correct_answer<<std::endl;
	std::cout<<"Result:\t"<<test_string<<" -> "<<compressor_output<<std::endl;
	if(correct_answer == compressor_output) {
		std::cout<<"Success"<<std::endl;
	} else {
		std::cout<<"Failure"<<std::endl;
	}

	test_string = "abcde";
	correct_answer = "abcde";
	compressor_output = stringCompressorEfficient(test_string);
	std::cout<<"Target:\t"<<test_string<<" -> "<<correct_answer<<std::endl;
	std::cout<<"Result:\t"<<test_string<<" -> "<<compressor_output<<std::endl;
	if(correct_answer == compressor_output) {
		std::cout<<"Success"<<std::endl;
	} else {
		std::cout<<"Failure"<<std::endl;
	}
	
	test_string = "ffffrrreeeddddoooooooooooooooommmmmmmmmmmmmmmm";
	correct_answer = "f4r3e3d4o16m16";
	compressor_output = stringCompressorEfficient(test_string);
	std::cout<<"Target:\t"<<test_string<<" -> "<<correct_answer<<std::endl;
	std::cout<<"Result:\t"<<test_string<<" -> "<<compressor_output<<std::endl;
	if(correct_answer == compressor_output) {
		std::cout<<"Success"<<std::endl;
	} else {
		std::cout<<"Failure"<<std::endl;
	}
	
	return 0;
}


std::string stringCompressor(std::string string_in) {
	// Initialise characters
	std::string string_comp = "";
	char prev_ch = string_in[0];
	int n_repeats = 0;

	for( char ch : string_in ) {
		if( ch != prev_ch ) {
			// If we change character then add the previous one to our output 
			// string along with how many repeats it had.
			string_comp = string_comp + prev_ch + std::to_string(n_repeats);
			prev_ch = ch;
			n_repeats = 1;
		} else {
			// If we find the same character again just increase the number of 
			// repeats.
			++n_repeats;
		}
	}
	// Make sure to deal with the final characters/
	string_comp = string_comp + prev_ch + std::to_string(n_repeats);

	// Check if compression actually compresses.
	if(string_comp.length() < string_in.length() ) {
		return string_comp;
	} else {
		return string_in;
	}

}

// It is inefficient to keep concatenating strings so I should try to do it in place
// but I cannot lose the original string so I will need to make a copy.
std::string stringCompressorEfficient(std::string string_in) {
	// Initialise characters
	size_t length_string = string_in.length();
	std::string string_comp = "";
	// Avoid having to reallocate space to our new string.
	string_comp.reserve(length_string);

	std::string new_string = "";
	char prev_ch = string_in[0];
	int n_repeats = 0;
	size_t length_comp = 0;
	for( char ch : string_in ) {
		if( ch != prev_ch ) {
			// If we change character then add the previous one to our output 
			// string along with how many repeats it had.
			// at the end. Difficult because could be more than one digit. So we
			// have to ascertain its length and then insert it as a substring.
			// We add on the length 
			new_string = prev_ch + std::to_string(n_repeats);
			// Reset the repetition data
			prev_ch = ch;
			n_repeats = 1;
			length_comp += new_string.length();
			// We check length_comp + 2 as that is the minimum that will be needed
			// to account for the final character string. So if this is too long
			// we return the original string.
			if(length_comp+2 < length_string) { 
				string_comp += new_string;
			} else { return string_in; }
		} else {
			// If we find the same character again just increase the number of 
			// repeats.
			++n_repeats;
		}
	}
	// Make sure to deal with the final characters/
	new_string = prev_ch + std::to_string(n_repeats);
	if(length_comp < length_string) { 
		string_comp += new_string;
	} else {return string_in;}

	// If we have really compressed it then we return the compressed string.
	return string_comp;
}

