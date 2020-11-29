#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
	Matrix<int> matrix{4, 2};
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
	matrix.setMatrixFromArray(array);
//	cout << matrix.getRows() << endl;
//	cout << matrix.getColumns() << endl;
//	matrix.printMatrix();
	Matrix<int> matrix2{matrix};
	matrix2.printMatrix();
	return 0;
}
