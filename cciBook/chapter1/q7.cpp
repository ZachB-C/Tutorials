// The task is to rotate the contents of a matrix 90  degrees in place. 
// So we need a 
// buffer of one element if we do it an element at a time, or we could do it 
// row by row I guess. Need to deal with references I guess

#include <iostream>
#include <stdint.h>
#include <vector>
// uint32_t is 4 bytes, 32 bits unsigned int.

// Helper functions
int rotateMatrixInPlace(std::vector<std::vector<uint32_t>>& matrix_in);
std::vector<std::vector<uint32_t>> rotateMatrix(
		std::vector<std::vector<uint32_t>> matrix_in);
int printMatrix(std::vector<std::vector<uint32_t>> matrix_in);

int main() {
	std::vector<std::vector<uint32_t>> test_vector = {
		{1,2},
	       	{3,4}
	};
	std::cout<<"Input:"<<std::endl;
	printMatrix(test_vector);
	std::vector<std::vector<uint32_t>> rotated_vector_gt = {
		{3, 1},
		{4, 2}
	};
	std::vector<std::vector<uint32_t>> rotated_vector_test 
		= rotateMatrix( test_vector);
	printMatrix(test_vector);
	std::cout<<"Output"<<std::endl;
	printMatrix(rotated_vector_test);
	rotateMatrixInPlace( test_vector );

	std::cout<<"Ground truth:"<<std::endl;
	printMatrix(rotated_vector_gt);
	std::cout<<"Output matrix:"<<std::endl;
	printMatrix(rotated_vector_test);
	std::cout<<"Original matrix:"<<std::endl;
	printMatrix(test_vector);

	std::cout<<"Test 1"<<std::endl;
	test_vector = {
		{1}
	};
	std::cout<<"Input:"<<std::endl;
	printMatrix(test_vector);
	rotated_vector_gt = {
		{1}
	};
	rotated_vector_test = rotateMatrix( test_vector);
	printMatrix(test_vector);
	std::cout<<"Output"<<std::endl;
	printMatrix(rotated_vector_test);
	rotateMatrixInPlace( test_vector );

	std::cout<<"Ground truth:"<<std::endl;
	printMatrix(rotated_vector_gt);
	std::cout<<"Output matrix:"<<std::endl;
	printMatrix(rotated_vector_test);
	std::cout<<"Original matrix:"<<std::endl;
	printMatrix(test_vector);

	std::cout<<"Test 2"<<std::endl;
	test_vector = {
		{1,2},
		{3,4}
	};
	std::cout<<"Input:"<<std::endl;
	printMatrix(test_vector);
	rotated_vector_gt = {
		{3,1},
		{4,2},
	};
	rotated_vector_test = rotateMatrix( test_vector);
	printMatrix(test_vector);
	std::cout<<"Output"<<std::endl;
	printMatrix(rotated_vector_test);
	rotateMatrixInPlace( test_vector );

	std::cout<<"Ground truth:"<<std::endl;
	printMatrix(rotated_vector_gt);
	std::cout<<"Output matrix:"<<std::endl;
	printMatrix(rotated_vector_test);
	std::cout<<"Original matrix:"<<std::endl;
	printMatrix(test_vector);

	std::cout<<"Test 3"<<std::endl;
	test_vector = {
		{1,2,3},
	       	{4,5,6},
		{7,8,9}
	};
	std::cout<<"Input:"<<std::endl;
	printMatrix(test_vector);
	rotated_vector_gt = {
		{7,4,1},
		{8,5,2},
		{9,6,3}
	};
	rotated_vector_test = rotateMatrix( test_vector);
	printMatrix(test_vector);
	std::cout<<"Output"<<std::endl;
	printMatrix(rotated_vector_test);
	rotateMatrixInPlace( test_vector );

	std::cout<<"Ground truth:"<<std::endl;
	printMatrix(rotated_vector_gt);
	std::cout<<"Output matrix:"<<std::endl;
	printMatrix(rotated_vector_test);
	std::cout<<"Original matrix:"<<std::endl;
	printMatrix(test_vector);




	std::cout<<"Test 4"<<std::endl;
	test_vector = {
		{1,2,3,4},
	       	{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};
	std::cout<<"Input:"<<std::endl;
	printMatrix(test_vector);
	rotated_vector_gt = {
		{13,9,5,1},
		{14,10,6,2},
		{15,11,7,3},
		{16,12,8,4}
	};
	rotated_vector_test = rotateMatrix( test_vector);
	printMatrix(test_vector);
	std::cout<<"Output"<<std::endl;
	printMatrix(rotated_vector_test);
	rotateMatrixInPlace( test_vector );

	std::cout<<"Ground truth:"<<std::endl;
	printMatrix(rotated_vector_gt);
	std::cout<<"Output matrix:"<<std::endl;
	printMatrix(rotated_vector_test);
	std::cout<<"Original matrix:"<<std::endl;
	printMatrix(test_vector);



	std::cout<<"Test 5"<<std::endl;
	test_vector = {
		{1,2,3,4,5},
	       	{6,7,8,9,10},
		{11,12,13,14,15},
		{16,17,18,19,20},
		{21,22,23,24,25}
	};
	std::cout<<"Input:"<<std::endl;
	printMatrix(test_vector);
	rotated_vector_gt = {
		{21,16,11,6,1},
		{22,17,12,7,2},
		{23,18,13,8,3},
		{24,19,14,9,4},
		{25,20,15,10,5}
	};
	rotated_vector_test = rotateMatrix( test_vector);
	printMatrix(test_vector);
	std::cout<<"Output"<<std::endl;
	printMatrix(rotated_vector_test);
	rotateMatrixInPlace( test_vector );

	std::cout<<"Ground truth:"<<std::endl;
	printMatrix(rotated_vector_gt);
	std::cout<<"Output matrix:"<<std::endl;
	printMatrix(rotated_vector_test);
	std::cout<<"Original matrix:"<<std::endl;
	printMatrix(test_vector);



	return 0;

}
// There is a problem with the quadrant approach since some elements
// will be counted twice if we have an odd number of elements, and that
// means we will rotate twice.
// We have to work with a reference so that we modify in place
// I have only coded rotating clockwise I could code for anti-clockwise as
// well I guess it would not be too difficult.
int rotateMatrixInPlace(
		std::vector<std::vector<uint32_t>>& matrix_in ) {
	//std::cout<<"Step 1"<<std::endl;
	size_t length_matrix = matrix_in.size();

	//std::cout<<"Step 2"<<std::endl;
	uint32_t moving_element_1 = 0;
	uint32_t moving_element_2 = 0;
	// Loop over rows first as it is more efficient
	// Because we are doing things in place we are best off
	// only mapping a quarter of the matrix and then shifting all
	// the elements that get in the way.
	//std::cout<<"Step 3"<<std::endl;
	// This is a problem because it double counts the cross
	// through the middle of an odd sized matrix. So we should 
	// deal with this cross separately maybe. We need a rectangular
	// section so we don't hit the middle element of an odd one
	for( size_t i = 0; i<length_matrix/2; ++i) {
		for ( size_t j = 0; j<(length_matrix+1)/2; ++j) {
			// Move element in first quadrant to second quadrant
			moving_element_1 = matrix_in[j][length_matrix-i-1];
			matrix_in[j][length_matrix-i-1] = matrix_in[i][j];
			// Move element in second quadrant to third quadrant
			moving_element_2 
			= matrix_in[length_matrix-i-1][length_matrix-j-1];
			matrix_in[length_matrix-i-1][length_matrix-j-1] 
				= moving_element_1;

			// Move element in third quadrant to fourth quadrant
			moving_element_1 = matrix_in[length_matrix -j -1][i];
			matrix_in[length_matrix-j-1][i] = moving_element_2;

			// Move element in fourth quadrant to first quadrant
			// We don't need reserve this time as the first quadrant
			// is already copied.
			matrix_in[i][j] = moving_element_1;
		}
	}
	
	//std::cout<<"Step 4"<<std::endl;
	return 0;

 }
 


// To rotate we must take each element matrix[i][j] -> matrix[j][length-i-1]
// Assumed to be square.
std::vector<std::vector<uint32_t>> rotateMatrix(
		std::vector<std::vector<uint32_t>> matrix_in) {
	size_t length_matrix = matrix_in.size();
	std::vector<std::vector<uint32_t>> rotated_matrix = matrix_in;
	// Loop over rows first as it is more efficient.
	for( size_t i = 0; i<length_matrix; ++i) {
		for( size_t j = 0; j<length_matrix; ++j) {
			rotated_matrix[j][length_matrix - i - 1] 
				= matrix_in[i][j];
		}
	}

	return rotated_matrix;
}


int printMatrix(std::vector<std::vector<uint32_t>> matrix_in) {
	size_t length_matrix = matrix_in.size();
	std::cout<<"{"<<std::endl;
	for( size_t i = 0; i<length_matrix; ++i) {
		std::cout<<"\t{";
		for( size_t j = 0; j<length_matrix; ++j) {
			std::cout<<"\t"<<matrix_in[i][j];
		}
		std::cout<<"}"<<std::endl;
	}
	std::cout<<"}"<<std::endl;

	return 0;
}
