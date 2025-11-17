// Replace spaces with '%20' assume original string has space for replacements and that you are given the length of the // true string i.e. ignoring the extra characters at the end that are only included to allow the replacement.
// We use a reference & after variable name to ensure that we carry this out in place. If we wish to produce a new 
// variable then we can get rid of this.
#include <iostream>

//Helper functions
std::string urlify(std::string& string_in, size_t string_length); 
// Replaces spaces with '%20'
size_t countSpaces(std::string string_in);	
// Counts how many spaces there are
std::string addSpaces(std::string string_in);					
// Adds extra spaces to a string to allow in place modification by urlify


int main() {
	std::string true_string = "Mr John Smith";
	size_t true_length = true_string.length();
	std::string long_string = addSpaces(true_string);
	std::cout<<true_string<<' '<<countSpaces(true_string)<<" Spaces: "<<long_string<<"End"<<std::endl;
	std::cout<<true_string<<" becomes "<<urlify(long_string, true_length)<<std::endl;
	std::cout<<long_string<<std::endl;

	true_string = " No time for this ";
	true_length = true_string.length();
	long_string = addSpaces(true_string);
	std::cout<<true_string<<' '<<countSpaces(true_string)<<" Spaces: "<<long_string<<"End"<<std::endl;
	std::cout<<true_string<<" becomes "<<urlify(long_string, true_length)<<std::endl;
	std::cout<<long_string<<std::endl;
	return 0;
}

std::string urlify(std::string& string_in, size_t string_length) {
	size_t i_orig = string_length;
	// i_url notes the index we have made the adjusts up to i_orig is
	// the index of the original.
	size_t i_url = string_in.length();
	char ch = ' ';
	while( i_orig>0 ) {
		ch = string_in[i_orig-1];
		if( ch == ' ') {
			string_in[i_url-3] = '%';
			string_in[i_url-2] = '2';
			string_in[i_url-1] = '0';
			i_url -= 3;
		} else {
			string_in[i_url-1] = ch;
			--i_url;
		}
		--i_orig;
	}

	

	return string_in;
}


std::string addSpaces(std::string string_in) {
	// We need two times the number of spaces extra
	// characters because we are interting something
	// three characters long and we keep the original 
	// space.
	size_t spaces_needed = 2*countSpaces(string_in);
	std::string long_string = "";
	for (size_t i=0; i<spaces_needed; i++) {
		long_string = long_string + ' ';
	}
	long_string = string_in + long_string;

	return long_string;
}



size_t countSpaces(std::string string_in) {
	size_t n_spaces = 0;
	for(char ch : string_in) {
		if( ch == ' ') {
			++n_spaces;
		}
	}

	return n_spaces;
}
