#include "GrowingContainer.h"
#include <iostream>

using namespace std;

template<typename T>
GrowingContainer<T>::GrowingContainer() {
	array = new T[START_SIZE];
}

template<typename T>
bool GrowingContainer<T>::isEmpty() const {
	return size == 0;
}

template<typename T>
bool GrowingContainer<T>::isFull() const {
	return size == capacity;
}

template<typename T>
void GrowingContainer<T>::boostArray() {
	capacity = growingCoefficient * capacity;
	T *newArray = new T[capacity];
	for (int i = 0; i < size; ++i) {
		newArray[i] = array[i];
	}
	array = newArray;
	delete[] newArray;
}

template<typename T>
void GrowingContainer<T>::remove(int index) {
	if (index < 0 || index >= size) {
		throw out_of_range("ArrayIndexOutOfBoundsException");
	}
	int i = 0;
	while (i != size - index - 1) {
		array[index + i] = array[index + i + 1];
		i++;
	}
	size--;
}

template<typename T>
void GrowingContainer<T>::add(const T &object) {
	if (isFull()) {
		boostArray();
	}
	array[size++] = object;
}

template<typename T>
void GrowingContainer<T>::add(int index, const T &object) {
	checkSize(index);
	if (isFull()) {
		boostArray();
	}
	for (int i = size; i > index; i--) {
		array[i] = array[i - 1];
	}
	array[index] = object;
	size++;
}

template<typename T>
GrowingContainer<T>::~GrowingContainer<T>() {
	delete[] array;
}

template<typename T>
void GrowingContainer<T>::dump() const {
	for (int i = 0; i < size; ++i) {
		cout << array[i] << endl;
	}
}

template<typename T>
T &GrowingContainer<T>::operator[](int index) {
	checkSize(index);
	return array[index];
}

template<typename T>
T GrowingContainer<T>::operator[](int index) const {
	checkSize(index);
	return array[index];
}

template<typename T>
void GrowingContainer<T>::checkSize(int index) const {
	if (index < 0 || index >= size) {
		throw out_of_range("ArrayIndexOutOfBoundsException");
	}
}

template
class GrowingContainer<int>;

template
class GrowingContainer<string>;