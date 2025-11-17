// Here the task is to identify pairs of words that differ by a single edit or less: 
// deletion, insertion, or replacement of a single letter. So first we should
// count the letters that allows us to narrow it down. If they are the same
// it is a replacement or multiple changes, if it is one differnt could be deletion
// or insertion. For the latter two just make hash tables with counts of each letter
// and check the longer string contains all the elements of the shorter string so
//  that each letter has a count greater than or equal to that of the shorter one.
//  For the words being of the same length all letter counts must be the same if 
//  no changes have been if a single replacement has been made then one letter must
//  have one larger count and one one smaller count. This is not sufficient though
//  as this will not be sufficient to identify permutations so we must also consider
//  the order. This is necessary but not sufficient. Instead we should compare length 
//  first, if the length is different we go through one letter at a time and compare
//  calculating the offset: if at some point they don't match then try the next letter
//  for the longer case. Make a function deletion check? For replacement do the same 
//  but count the number of differences always continuing. We could ignore spaces but 
//  I don't think we will for now.
#include <iostream>

// Helper functions
bool isSingleEditOrLessOnePass(std::string string1, std::string string2);
bool isSingleEditOrLessOnePass(std::string string1, std::string string2);
bool isDeletion(std::string stringLong, std::string stringShort);

int main() {
	std::string test_string1 = "pale";
	std::string test_string2 = "ple";
	bool correct_answer = true;
	std::cout<<test_string1<<", "<<test_string2<<" -> "<<correct_answer<<std::endl;
	if( isSingleEditOrLessOnePass(test_string1, test_string2)==correct_answer ) {
		std::cout<<"It works."<<std::endl;
	} else { std::cout<< "It doesn't work."<<std::endl;}

	test_string1 = "pales";
	test_string2 = "pale";
	correct_answer = true;
	std::cout<<test_string1<<", "<<test_string2<<" -> "<<correct_answer<<std::endl;
	if( isSingleEditOrLessOnePass(test_string1, test_string2)==correct_answer ) {
		std::cout<<"It works."<<std::endl;
	} else { std::cout<< "It doesn't work."<<std::endl;}

	test_string1 = "pale";
	test_string2 = "bale";
	correct_answer = true;
	std::cout<<test_string1<<", "<<test_string2<<" -> "<<correct_answer<<std::endl;
	if( isSingleEditOrLessOnePass(test_string1, test_string2)==correct_answer ) {
		std::cout<<"It works."<<std::endl;
	} else { std::cout<< "It doesn't work."<<std::endl;}


	test_string1 = "pale";
	test_string2 = "bake";
	correct_answer = false;
	std::cout<<test_string1<<", "<<test_string2<<" -> "<<correct_answer<<std::endl;
	if( isSingleEditOrLessOnePass(test_string1, test_string2)==correct_answer ) {
		std::cout<<"It works."<<std::endl;
	} else { std::cout<< "It doesn't work."<<std::endl;}

}



bool isSingleEditOrLess( std::string string1, std::string string2) {
	size_t length1 = string1.length();
	size_t length2 = string2.length();

	if( length1 == length2 ) {
		// This checks if the strings have one or no replacements
		// but are otherwise unchanged.
		int n_diff = 0;
		for( size_t i=0; i< length1; ++i) {
			// This could be modified to ignore case
			// using a tolower statement. It could also be 
			// refacted and allowed to check for any number
			// of replacements.
			if( string1[i] != string2[i]) {
				// Make sure we only increment n_diff
				// if the two strings don't match.
				if (++n_diff > 1 ) {
					// If there is more than one 
					// difference then return false
					// as this cannot be achieved with a
					// single replacement
					return false;
				}
			}
		}
		// If we have not found more than 1 difference then at most
		// one edit has occurred.
		return true;
	} else if (length1 == length2 + 1) {
		// The first one should be the longest
		// Checks for deletion
		return isDeletion(string1, string2);
	} else if (length1 == length2 - 1) {
		// Checks for insertion, which is the
		// same as a deletion but starting from
		// the longer string, string
		return isDeletion(string2, string1); 
	} else {
		return false;
	}	
}

// Assume the first string is always the longest, could add in a check
// to make sure that is the case
bool isDeletion(std::string string_long, std::string string_short) {
	// We cycle over each of the shorter strings characters and 
	// try to find a match in the longer string, if we must search more
	// than one character ahead then or search one character ahead more
	// than once then we return false, it is not a deletion.
	int n_deletions = 0;
	for( size_t i=0, j=0; i < string_short.length(); ++i, ++j) {
		if( string_short[i] != string_long[j] ) {
			// Increment j to check next character along.
			// This ensures that j will be correct for the future
			// iterations of the loop. Once n_deletions goes beyond one
			// we quit.
			if( (string_short[i] != string_long[++j]) || (++n_deletions>1)) {
				return false;
			}
		}

	}
	// If we reach the end of the string without more than one deletion then 
	// the strings are related by a single deletion.
	return true;	
}


bool isSingleEditOrLessOnePass( std::string string1, std::string string2 ) {
	size_t length1 = string1.length();
	size_t length2 = string2.length();
	size_t offset2 = 0;
	int n_changes = 0;

	if ( (length1 > length2 +1) || length1 < length2 -1) {
		// One edit can result in a difference in length of at most one
		// must check this separately
		return false;
	} else {
		for( size_t i = 0; i < length1; ++i) {
			if( string1[i] != string2[i+offset2] ) {
				// Note that there is an edit detected, if this
				// occurs more than once we quit
				if(++n_changes>1) {
					return false;
				} else if( string1[i+1] == string2[i+offset2] ) {
					// This indicates we have made one deletion.
					// So we need to offset the index of the 
					// second string by -1.
					--offset2;
					// We can also offset i by 1 since we have
					// already tested the next one in sequence
					++i;
				} else if( string1[i] == string2[i+offset2+1] ) {
					// This indicates we have made an insertion
					// so we need to offset the index of the second
					// string by 1
					++offset2;
				} 

			}
		}
	}
	// If we have not already quit and returned false then we should return true.
	return true;
}
