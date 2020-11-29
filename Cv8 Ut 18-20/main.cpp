#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
	Matrix<int> matrix{4, 2};
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
	matrix.createMatrixFromArray(array);
//	cout << matrix.getRows() << endl;
//	cout << matrix.getColumns() << endl;
//	matrix.printMatrix();
	Matrix<int> matrix2{matrix};
	try {
		matrix2.setMatrixValue(0, -1, 10);
	} catch (invalid_argument ex) {
		cerr << move(ex).what() << endl;
	}
	matrix2.printMatrix();

	cout << matrix2.getValue(0, 0) << endl;
	return 0;
}
