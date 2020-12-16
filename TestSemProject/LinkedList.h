#ifndef CV5_UT_18_20_LINKEDLIST_H
#define CV5_UT_18_20_LINKEDLIST_H

#include <stdexcept>
#include <iostream>
#include <sstream>

using namespace std;

template<typename T>
class LinkedList {

public:
	bool isEmpty() const;

	T get(int index) const;

	int getSize() const;

	void addAsLast(T data);

	void addAsFirst(T data);

	void type() const;

	virtual ~LinkedList();

private:
	template<typename E>
	struct Node {
	public:

		E data = nullptr;
		Node<E> *prev = nullptr;
		Node<E> *next = nullptr;

		explicit Node(E &data, Node *n = nullptr, Node *p = nullptr) : data(data), next(n), prev(p) {}
	};

	int size = 0;
	Node<T> *head = nullptr;
	Node<T> *tail = nullptr;
};

template<typename T>
LinkedList<T>::~LinkedList<T>() {
	while (head != nullptr) {
		Node<T> *temp = head;
		head = head->next;
		delete temp;
	}
}

template<typename T>
void LinkedList<T>::addAsLast(T data) {
	auto newNode = new Node<T>(data, nullptr, tail);
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
void LinkedList<T>::addAsFirst(T data) {
	auto newNode = new Node<T>(data, head, nullptr);
	if (head == nullptr) {
		head = newNode;
		tail = head;
	} else {
		head->prev = newNode;
		head = newNode;
	}
	size++;
}

template<typename T>
T LinkedList<T>::get(int index) const {
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
int LinkedList<T>::getSize() const {
	return size;
}

template<typename T>
void LinkedList<T>::type() const {
	Node<T> *curNode = head;
	while (curNode != nullptr) {
		cout << curNode->data << endl;
		curNode = curNode->next;
	}
	delete curNode;
}

template<typename T>
bool LinkedList<T>::isEmpty() const {
	return size == 0;
}


#endif //CV5_UT_18_20_LINKEDLIST_H
