#ifndef CV5_UT_18_20_MYLINKEDLIST_H
#define CV5_UT_18_20_MYLINKEDLIST_H

#include <stdexcept>
#include <iostream>

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

	struct Iterator {
	public:
		bool hasNext() {
			return false;
		}

		T next() {
			return nullptr;
		}
	};

public:
	bool isEmpty() const;

	void push_back(T &data);

	void push_front(T &data);

	T pop_back();

	T pop_front();

	T getFirst();

	T getLast();

	T get(int id);

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
void MyLinkedList<T>::push_back(T &data) {
	if (data == nullptr) {
		cout << "he" << endl;
	}
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
void MyLinkedList<T>::push_front(T &data) {
	auto *newNode = new Node<T>(data, head, nullptr);
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
T MyLinkedList<T>::getFirst() {
	return head->data;
}

template<typename T>
T MyLinkedList<T>::getLast() {
	return tail->data;
}

template<typename T>
T MyLinkedList<T>::get(int id) {

}


#endif //CV5_UT_18_20_MYLINKEDLIST_H
