#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
//	Matrix<int> matrix{4, 2};
//	int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
//	matrix.createMatrixFromArray(array);
////	cout << matrix.getRows() << endl;
////	cout << matrix.getColumns() << endl;
////	matrix.printMatrix();
//	Matrix<int> matrix2{matrix};
////	try {
////		matrix2.setMatrixValue(0, 0, 10);
////	} catch (invalid_argument ex) {
////		cerr << move(ex).what() << endl;
////	}
//	matrix2.printMatrix();
//
//	cout << matrix2.getValue(0, 0) << endl;
//	matrix2.printMatrix();
//	Matrix<int> m = matrix2.matrixTransposition();
//	m.printMatrix();
//	cout << matrix2.getValue(0, 0) << endl;
//
//	Matrix<int> m1 = matrix2.multiplication(10);
//	m1.printMatrix();
//
//	Matrix<int> m2 = matrix2.sum(matrix);
//	m2.printMatrix();
//
//	if (matrix2.isMatch(matrix)) {
//		cout << "Match" << endl;
//	} else {
//		cout << "No match" << endl;
//	}

	Matrix<int> m{3, 3};
	int jednodpole[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	m.createMatrixFromArray(jednodpole);
	Matrix<int> mt = m.matrixTransposition();
	Matrix<int> mmt = m.multiplication(mt);
	Matrix<double> mmt_d = mmt.changeType<double>();
	Matrix<double> n_d{3, 3};
	double jednodpole_d[] = {4.5, 5, 0, 2, -0.5, 7, 1.5, 9, 6};
	n_d.createMatrixFromArray(jednodpole_d);
	Matrix<double> mmtn_d = mmt_d.multiplication(n_d);
	Matrix<int> r = mmtn_d.changeType<int>();
	Matrix<int> t{3, 3};
	int tpole[] = {85, 225, 236, 292, 819, 866, 499, 1413, 1496};
	t.createMatrixFromArray(tpole);
	cout << "r==t ? " << (r.isMatch(t) ? "true" : "false") << endl;
	return 0;
}
