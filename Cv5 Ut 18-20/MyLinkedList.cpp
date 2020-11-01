#include "MyLinkedList.h"
#include <stdexcept>

using namespace std;

//template<typename T>
//MyLinkedList<T>::~MyLinkedList<T>() {
//	while (head) {
//		Node *temp{head};
//		head = head->next;
//		delete temp;
//	}
//}
//
//template<typename T>
//bool MyLinkedList<T>::isEmpty() const { return (!head || !tail); }
//
//template<typename T>
//void MyLinkedList<T>::push_back(T data) {
//	auto *newNode = new Node(data, nullptr, tail);
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
//void MyLinkedList<T>::push_front(T data) {
//	auto *newNode = new Node(data, head, nullptr);
//	if (head == nullptr) {
//		head = newNode;
//		tail = head;
//	} else {
//		head->prev = newNode;
//		head = newNode;
//	}
//	size++;
//}
//
//template<typename T>
//T MyLinkedList<T>::pop_back() {
//	if (isEmpty()) {
//		throw logic_error("List is isEmpty!");
//	}
//	Node *temp{tail};
//	T data(tail->data);
//	tail = tail->prev;
//	if (tail == nullptr) {
//		tail->next = nullptr;
//	} else {
//		head = nullptr;
//	}
//	size--;
//	delete temp;
//	return data;
//}
//
//template<typename T>
//T MyLinkedList<T>::pop_front() {
//	if (isEmpty()) {
//		throw logic_error("List is isEmpty!");
//	}
//	Node *temp{head};
//	T data(head->data);
//	head = head->next;
//	if (head == nullptr) {
//		head->prev = nullptr;
//	} else {
//		tail = nullptr;
//	}
//	size--;
//	delete temp;
//	return data;
//}
//
//template<typename T>
//T MyLinkedList<T>::getFirst() {
//	return head->data;
//}
//
//template<typename T>
//T MyLinkedList<T>::getLast() {
//	return tail->data;
//}
//
//template<typename T>
//T MyLinkedList<T>::get(int id) {
//
//}
