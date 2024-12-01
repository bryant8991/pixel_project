#include "Matrices.h"

namespace Matrices
{
	Matrix::Matrix(int _rows, int _cols) : rows(_rows), cols(_cols) {}


	///Add each corresponding element.
	///usage:  c = a + b;
	Matrix operator+(const Matrix& a, const Matrix& b) { return a; }

	///Matrix multiply.  See description.
	///usage:  c = a * b;
	Matrix operator*(const Matrix& a, const Matrix& b) { return a; }

	///Matrix comparison.  See description.
	///usage:  a == b
	bool operator==(const Matrix& a, const Matrix& b) { return true; }

	///Matrix comparison.  See description.
	///usage:  a != b
	bool operator!=(const Matrix& a, const Matrix& b) { return true; }

	///Output matrix.
	///Separate columns by ' ' and rows by '\n'
	ostream& operator<<(ostream& os, const Matrix& a) { return os; }
}
