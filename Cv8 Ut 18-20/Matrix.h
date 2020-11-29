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

public:
	Matrix(int rows, int columns);

	Matrix(const Matrix<T> &m);

	virtual ~Matrix();

	void setMatrixValue(int row, int column, T value);

	void createMatrixFromArray(T *array);

	T **getMatrix() const;

	int getRows();

	int getColumns();

	void printMatrix();

	T &getValue(int row, int column);

	const T &getValue(int row, int column) const;

	bool isMatch(const Matrix<T> &m) const;

	Matrix<T> multiplication(const Matrix<T> &m) const;
	Matrix<T> multiplication(T scalar) const;

	Matrix<T> sum(const Matrix<T> &m) const;
	Matrix<T> sum(T scalar) const;

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
void Matrix<T>::setMatrixValue(int row, int column, T value) {
	if (row < 0 || column < 0 || row >= rows || column >= columns) {
		throw invalid_argument("Invalid arguments for setting.");
	}
	matrix[row][column] = value;
}

template<typename T>
void Matrix<T>::createMatrixFromArray(T *array) {
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
Matrix<T>::~Matrix() {
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

template<typename T>
T &Matrix<T>::getValue(int row, int column) {
	if (row < 0 || column < 0 || row >= rows || column >= columns) {
		throw invalid_argument("Invalid arguments for setting.");
	}
	return matrix[row][column];
}

template<typename T>
const T &Matrix<T>::getValue(int row, int column) const {
	return getValue(row, column);
}

template<typename T>
bool Matrix<T>::isMatch(const Matrix<T> &m) const {
	return false;
}


#endif //CV8_UT_18_20_MATRIX_H
