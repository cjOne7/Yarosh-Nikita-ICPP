#ifndef CV8_UT_18_20_MATRIX_H
#define CV8_UT_18_20_MATRIX_H

#include <stdexcept>
#include <iostream>

using namespace std;

template<typename T>
class Matrix {
private:
	int rows, columns;
	T **matrix;

	T **createMatrix(int rows, int columns);

	void deleteMatrix(T **matrix, int rows);

public:
	Matrix(int rows, int columns);

	Matrix(const Matrix<T> &m);

	virtual ~Matrix();

	void setMatrix(int row, int column, T value);

	void setMatrixFromArray(T *array);

	T **getMatrix() const;

	int getRows();

	int getColumns();

	void printMatrix();

};

template<typename T>
Matrix<T>::Matrix(int rows, int columns) {
	if (rows < 0 || columns < 0) {
		throw invalid_argument("Rows or columns can't be < 0");
	}
	this->rows = rows;
	this->columns = columns;
	matrix = createMatrix(rows, columns);
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T> &m) {
	if (m.rows <= 0 || m.columns <= 0) {
		throw invalid_argument("Empty matrix.");
	}
	rows = m.rows;
	columns = m.columns;
	T **newMatrix = createMatrix(rows, columns);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			newMatrix[i][j] = m.getMatrix()[i][j];
		}
	}
	matrix = newMatrix;
}

template<typename T>
void Matrix<T>::setMatrix(int row, int column, T value) {
	if (rows < 0 || columns < 0) {
		throw invalid_argument("Row or column can't be < 0");
	}
	matrix[row][column] = value;
}

template<typename T>
void Matrix<T>::setMatrixFromArray(T *array) {
	if (array == nullptr) {
		throw invalid_argument("Array is nullptr.");
	}
	T **newMatrix = createMatrix(rows, columns);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			newMatrix[i][j] = array[i * columns + j];
		}
	}
	matrix = newMatrix;
//	deleteMatrix(newMatrix, rows);
}

template<typename T>
T **Matrix<T>::createMatrix(int rows, int columns) {
	T **newMatrix = new T *[rows];
	for (int i = 0; i < rows; i++) {
		newMatrix[i] = new T[columns];
	}
	return newMatrix;
}

template<typename T>
T **Matrix<T>::getMatrix() const { return matrix; }

template<typename T>
int Matrix<T>::getRows() { return rows; }

template<typename T>
int Matrix<T>::getColumns() { return columns; }

template<typename T>
Matrix<T>::~Matrix() { deleteMatrix(matrix, rows); }

template<typename T>
void Matrix<T>::deleteMatrix(T **matrix, int rows) {
	for (int i = 0; i < rows; i++) {
		delete matrix[i];
	}
	delete[] matrix;
}

template<typename T>
void Matrix<T>::printMatrix() {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}


#endif //CV8_UT_18_20_MATRIX_H
