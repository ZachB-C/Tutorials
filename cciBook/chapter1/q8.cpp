// If at least a single element in a row or column is zero set the entire row 
// or column to zero.
// I guess we can make an array for each row and each column noting the indices
// that hold zeros. Then we do a search through once to find the zeros, note
// them in the array and then go through a second time to set values to zero.
// I am assuming that we are working with integer elements if it is float
// then we would need to have some specified precision.
// Might be better to define a type.
#include <iostream>
#include <vector>
#include <stdexcept>
#include <array>

// For simplicity I will define it as a vector<vector<int>> though it would
// probably be better to us a template and maybe an array.
// Define Class
class Matrix
{
	private:
		std::vector<std::vector<int>> data_;

	public:
		// Constructor
		Matrix(std::vector<std::vector<int>> matrix) {
			data_ = matrix;
		}
		// Data member
		int& operator() (size_t row, size_t col) { 
			if( row >= rows() || col >= cols() ) {
				throw std::out_of_range(
					"Matrix subscript out of bounds.");
			}
			return data_[row][col];					
		};
		int operator() (size_t row, size_t col) const {
			if( row >= rows() || col >= cols() ) {
				throw std::out_of_range(
					"Matrix subscript out of bounds.");
			}
			return data_[row][col];
		}
		// Change data
		int input_data(std::vector<std::vector<int>> matrix) {
			data_ = matrix;
			return 0;
		}
		// Meta parameters
		size_t rows() const {return data_.size(); }
		size_t cols() const { return data_[0].size(); }
		size_t size() const { return rows()*cols(); }
		// Functions
		int print() {
			std::cout << "{" << std::endl;
			for( size_t i = 0; i < rows(); ++i) {
				std::cout<<"\t{";
				for( size_t j = 0; j < cols(); ++j) {
					std::cout<<"\t"<<operator() (i,j);
				}
				std::cout<<"}"<<std::endl;
			}
			std::cout<<"}"<<std::endl;

			return 0;
		}

};

// Helper functions (do in place)
int setToZero(Matrix& matrix_in);
int setToZeroSparse(Matrix& matrix_in);
int setToZeroLocal(Matrix& matrix_in);


//inline
//int Matrix::print() {
//	std::cout << "{" << std::endl;
//	for( int i = 0; i < rows(); ++i) {
//		std::cout<<"\t{";
//		for( int j = 0; j < cols(); ++j) {
//			std::cout<<"\t"<<this[i][j];
//		}
//		std::cout<<"}"<<std::endl;
//	}
//	std::cout<<"}"::std::endl;
//}

int main() {

	std::cout<<"No: 1"<<std::endl;

	Matrix matrix_test ({
		{1,0},
		{2,3}
	});
	Matrix matrix_test_sparse = matrix_test;
	Matrix matrix_test_local = matrix_test;

	std::cout<<"Original Matrix:"<<std::endl;
	matrix_test.print();
	
	setToZero(matrix_test);
	std::cout<<"Zeroed Matrix:"<<std::endl;
	matrix_test.print();	

	setToZeroSparse(matrix_test_sparse);
	std::cout<<"Zeroed Matrix Sparse:"<<std::endl;
	matrix_test_sparse.print();

	setToZeroLocal(matrix_test_local);
	std::cout<<"Zeroed Matrix Local:"<<std::endl;
	matrix_test_local.print();


	std::cout<<"No: 2"<<std::endl;
	matrix_test.input_data ({
		{1,0,3,4,5,6,7,8,9,10},
		{11,12,13,14,15,16,17,18,19,20},
		{21,22,23,24,25,26,27,28,29,30},
	});
	matrix_test_sparse = matrix_test;
	matrix_test_local = matrix_test;

	std::cout<<"Original Matrix:"<<std::endl;
	matrix_test.print();
	
	setToZero(matrix_test);
	std::cout<<"Zeroed Matrix:"<<std::endl;
	matrix_test.print();	
	
	std::cout<<"Original Matrix Sparse:"<<std::endl;
	matrix_test_sparse.print();
	
	setToZeroSparse(matrix_test_sparse);
	std::cout<<"Zeroed Matrix Sparse:"<<std::endl;
	matrix_test_sparse.print();

	std::cout<<"Original Matrix Local:"<<std::endl;
	matrix_test_local.print();
	
	setToZeroLocal(matrix_test_local);
	std::cout<<"Zeroed Matrix Local:"<<std::endl;
	matrix_test_local.print();


	std::cout<<"No: 3"<<std::endl;
	matrix_test.input_data ({
		{1,0,3,4,5,6,7,0,9,10},
		{11,12,13,14,15,16,17,18,19,20},
		{21,22,23,0,25,26,27,28,29,30},
	});
	matrix_test_sparse = matrix_test;
	matrix_test_local = matrix_test; 

	std::cout<<"Original Matrix:"<<std::endl;
	matrix_test.print();
	
	setToZero(matrix_test);
	std::cout<<"Zeroed Matrix:"<<std::endl;
	matrix_test.print();	
	
	std::cout<<"Original Matrix Sparse:"<<std::endl;
	matrix_test_sparse.print();
	
	setToZeroSparse(matrix_test_sparse);
	std::cout<<"Zeroed Matrix Sparse:"<<std::endl;
	matrix_test_sparse.print();

	std::cout<<"Original Matrix Local:"<<std::endl;
	matrix_test_local.print();
	
	setToZeroLocal(matrix_test_local);
	std::cout<<"Zeroed Matrix Local:"<<std::endl;
	matrix_test_local.print();



	return 0;
}

// I'll do a simple version but I guess if we used the 
// fact we have vectors we could probably do something
// a bit faster.
// Might be quicker just to make list of zeros if there are not
// many and the matrix is large.
int setToZero(Matrix &matrix_in) {
	size_t n_rows = matrix_in.rows();
	size_t n_cols = matrix_in.cols();
	// A 0 indicates the row should be zero, 1 indicates we should
	// leave it as it is.
	std::vector<bool> row_zero_locations(n_rows, 1);
	std::vector<bool> col_zero_locations(n_cols, 1);

	for( size_t i = 0; i < n_rows; ++i ) {
		for( size_t j = 0; j < n_cols; ++j ) {
			if( matrix_in(i,j) == 0 ) {
				row_zero_locations[i] = 0;
				col_zero_locations[j] = 0;
			}
		}
	}
	for( size_t i = 0; i < n_rows; ++i ) {
		for( size_t j = 0; j < n_cols; ++j ) {
			if( !row_zero_locations[i] 
					|| !col_zero_locations[j]) {
				matrix_in(i,j) = 0;
			}

		}
	}
			

	return 0;

}

// I'll do a simple version but I guess if we used the 
// fact we have vectors we could probably do something
// a bit faster.
// Might be quicker just to make list of zeros if there are not
// many and the matrix is large.
int setToZeroSparse(Matrix &matrix_in) {
	// Could reserve some space maybe if we will need long vectors;
	std::vector<size_t> zero_rows;
	std::vector<size_t> zero_cols;

	for( size_t i = 0; i < matrix_in.rows(); ++i ) {
		for( size_t j = 0; j < matrix_in.cols(); ++j ) {
			if( matrix_in(i,j) == 0 ) {
				zero_rows.push_back(i);
				zero_cols.push_back(j);
			}
		}
	}
	for( size_t i : zero_rows ) {
		for( size_t j = 0; j < matrix_in.cols(); ++j ) {
				matrix_in(i,j) = 0;
		}
	}
			
	for( size_t j : zero_cols ) {
		for( size_t i = 0; i < matrix_in.rows(); ++i ) {
				matrix_in(i,j) = 0;
		}
	}
	
	return 0;

}


// Here we store the location of the rows and columns within the 
// matrix itself, to do so we use two unsigned ints, one to specify
// the row of the matrix with the indices of the columns that must be
// set to zero and one to specify the index of the row of the matrix with
// the indices of the rows that must be set to zero. We should have two
// more variables to count how many rows and columns we need to deal with.
// Complication is that when we are setting rows and columns to zero we need
// to make sure we don't set the storage rows to zero (or any of their elements
// before we have read them). So set rows to zero first (except the one storing
// column data) and then set columns to zero but don't alter anything in the 
// column storage row. Then finish by setting the storage rows to zero.
// There must be a more efficient way to do this, maybe use 
// columns for storage instead? It is not square so we must store column data
// in columns and row data in rows. Maybe best idea is to make a chain where
// we store the next location in the previous place. But that will take two
// bits of information for each one. This is a real mess, it seems like 
// a horrible way to do things.
// So we will store column info in a row and row info in a column we just have
// to make sure we don't overwrite one with the other. We can skip it and cope
// with the edge case where everything is zero if we do not record one value of 
// each.
// Best not to store location data because matrix could be a double or 
// whatever so it may not be compatible but we should be able to store zero
// or not zero.
int setToZeroLocal(Matrix& matrix_in) {
	size_t n_rows = matrix_in.rows();
	size_t n_cols = matrix_in.cols();
	bool zero_found = false;
	// Store col_info in rows and row info in cols.
	// i_row_info is the current index in the column 
	// where the latest row info is stored.
	// j_col_info is the index in the row where the latest column info
	// is stored.
	// Better way we will search the whole row, it will take more time
	// as we must search the whole row and column but it will be way 
	// less confusing and the order will be the same, it can just be one
	// and zeros.
	size_t col_index_loc = 0;
	size_t row_index_loc = 0;
	// Could reserve some space maybe if we will need long vectors;
	
	for( size_t i = 0; i < n_rows; ++i ) {
		for( size_t j = 0; j < n_cols; ++j ) {
			if( matrix_in(i,j) == 0 ) {
				// If this is our first zero
				// we need to set up where we will store
				// data
				if( !zero_found ) {
					col_index_loc = i;
					row_index_loc = j;
					matrix_in(i, j) = 0;
					zero_found = true;
				} else {
					// We set the corresponding row
					// and column of our reference
					// columns and rows to zero. 
					matrix_in(col_index_loc, j) = 0;
					matrix_in(i, row_index_loc) = 0;
				}
			}
		}
	}
	std::cout<<"Part way through"<<std::endl;
	matrix_in.print();			
	
	// Now we need to set all the rows and columns to zero 
	// that are zero in our references
	for( size_t i = 0; i < n_rows; ++i ) {
		// Need to make sure we don't over-write the column information
		// we can do that last.
		if( i != col_index_loc 
				&& matrix_in(i, row_index_loc) == 0 ) {
			// Set the whole row to zero.
			for( size_t j = 0; j < n_cols; ++j ) {
					matrix_in(i,j) = 0;
			}
		}
	}
	for( size_t j = 0; j < n_cols; ++j ) {
		// Over-writing doesn't matter in this case as we have 
		// already used the row information
		if( matrix_in(col_index_loc, j) == 0) {
			for( size_t i = 0; i < n_rows; ++i ) {
				matrix_in(i,j) = 0;
			}
		}
	}
	
	// Lastly we need to deal with the row references
	for( size_t j = 0; j < n_cols; ++j ) {
			matrix_in(col_index_loc, j) = 0;
	}

	return 0;

}
