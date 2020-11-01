#ifndef CV5_UT_18_20_MYLINKEDLIST_H
#define CV5_UT_18_20_MYLINKEDLIST_H

#include <stdexcept>
#include <iostream>
#include <sstream>

using namespace std;

template<typename T>
class MyLinkedList {

	template<typename E>
	struct Node {
	public:
		E data = nullptr;
		Node<E> *prev = nullptr;
		Node<E> *next = nullptr;

		Node(E &data, Node *n = nullptr, Node *p = nullptr) : data(data), next(n), prev(p) {}
	};

public:
	bool isEmpty() const;

	void addAsLast(T &data);

	T get(int index) const;

	int getSize() const;

	virtual ~MyLinkedList();

private:
	int size = 0;
	Node<T> *head = nullptr;
	Node<T> *tail = nullptr;
};


template<typename T>
MyLinkedList<T>::~MyLinkedList<T>() {
	Node<T> *temp = head;
	while (temp != nullptr) {
		temp = temp->next;
		delete temp;
	}
}

template<typename T>
bool MyLinkedList<T>::isEmpty() const { return size == 0; }

template<typename T>
void MyLinkedList<T>::addAsLast(T &data) {
//	if (data == nullptr) {
//		throw invalid_argument("Data is null!");
//	}
	auto *newNode = new Node<T>(data, nullptr, tail);
	if (tail == nullptr) {
		tail = newNode;
		head = tail;
	} else {
		tail->next = newNode;
		tail = newNode;
	}
	size++;
}

template<typename T>
T MyLinkedList<T>::get(int index) const {
	if (index >= 0 && index < size) {
		Node<T> *node = head;
		for (int i = 0; i < index; ++i) {
			node = node->next;
		}
		return node->data;
	} else {
		ostringstream os;
		os << "Record in list with index " << index << " doesn't exist." << endl;
		throw out_of_range(os.str());
	}
}

template<typename T>
int MyLinkedList<T>::getSize() const {
	return size;
}


#endif //CV5_UT_18_20_MYLINKEDLIST_H
