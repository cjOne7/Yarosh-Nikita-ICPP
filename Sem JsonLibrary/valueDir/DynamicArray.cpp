//#include "api.h"
//
//template<typename T>
//DynamicArray<T>::DynamicArray() {
//}
//
//template<typename T>
//DynamicArray<T>::~DynamicArray<T>() {
//	while (head != nullptr) {
//		Node<T> *temp = head;
//		head = head->next;
//		delete temp;
//	}
//}
//
//template<typename T>
//void DynamicArray<T>::append(const T &element) {
//	Node<T> newNode = new Node<T>(data, nullptr, tail);
//	if (tail == nullptr) {
//		tail = newNode;
//		head = tail;
//	} else {
//		tail->next = newNode;
//		tail = newNode;
//	}
//	size++;
//}
//
//template<typename T>
//int DynamicArray<T>::getSize() const {
//	return size;
//}
//
//template<typename T>
//const T &DynamicArray<T>::getElementAt(int index) const {
//	if (index < 0 || index >= size) {
//		throw invalid_argument("Index must be in an available range.");
//	}
//	return nullptr;
//}
