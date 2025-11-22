// Assume you have code isSubstring that checks if one string is a substring of
// another. You can call it only once and must detemine if one string is a 
// cyclic permutation of the other. I think we need to concatenate the second 
// string twice (or append) and then check if the first is a substring of 
// this concatenated string, we should first check they are the same length.
#include <iostream>
// Helper functions
bool isSubstring(std::string s1, std::string s2);
bool isRotation(std::string s1, std::string s2);


int main() {
	std::string s1 = "waterbottle";
	std::string s2 = "erbottlewat";
	bool correct_result = true;
	bool answer_given = isRotation(s1, s2);
	std::cout<<s1<<" is rotation of "<<s2<<"? "
		<<answer_given<<", "
		<<correct_result<<" (GT)."<<std::endl;

	s1 = "watebottled";
	s2 = "erbottlewat";
	correct_result = false;
	answer_given = isRotation(s1, s2);
	std::cout<<s1<<" is rotation of "<<s2<<"? "
		<<answer_given<<", "
		<<correct_result<<" (GT)."<<std::endl;

	s1 = "wayoutman";
	s2 = "outmanway";
	correct_result = true;
	answer_given = isRotation(s1, s2);
	std::cout<<s1<<" is rotation of "<<s2<<"? "
		<<answer_given<<", "
		<<correct_result<<" (GT)."<<std::endl;


	return 0;
}
// Could do an in place operation on s2 but might be confusing
bool isRotation(std::string s1, std::string s2) {
	if( s1.length() != s2.length() ) {
		return false;
	}
	std::string s2_doubled = s2 + s2;	
	if( !isSubstring(s1, s2_doubled) ) {
		return false;
	}

	return true;
}


// isSubstring gives index of start of substring if it is 
// a substring and -1 if not. s1 is the one that should be within s2
bool isSubstring(std::string s1, std::string s2) {
	if( s1.length() > s2.length() ) { return -1;}
	char start = s1[0];
	bool match = false;
	// First find the occurences of s1 in s2. For each one check if
	// we get a full substring.
	for( size_t i_2 = 0; i_2 < s2.length() - s1.length() +1; ++i_2 ) {
		// If we find a possible start to the sequence check 
		// until the end
		if( s2[i_2] == start ) {
			match = true;
			for( size_t i_1 = 0; i_1 < s1.length(); ++i_1) {
				// If we stop matching then skip to the next
				// attempt.
				if( s2[i_2+i_1] != s1[i_1] ) {
					match = false;
				       	break;
				}	       
			}
		}
	}
	
	return match;

}




