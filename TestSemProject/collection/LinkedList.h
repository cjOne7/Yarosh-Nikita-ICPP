#ifndef CV5_UT_18_20_LINKEDLIST_H
#define CV5_UT_18_20_LINKEDLIST_H

#include <stdexcept>
#include <iostream>
#include <sstream>
#include "ElementNotFoundException.h"
#include "../valueDir/Value.h"

using namespace std;

template<typename T>
class LinkedList {

public:
	bool isEmpty() const;

	T get(const string &key) const;

	int getSize() const;

	void addAsLast(const string &key, T data);

	void addAsFirst(const string &key, T data);

	void type() const;

	virtual ~LinkedList();

private:
	template<typename V>
	struct Node {
	public:
		string key;
		V data = nullptr;
		Node<V> *prev = nullptr;
		Node<V> *next = nullptr;

		explicit Node(string key, V &data, Node *n = nullptr, Node *p = nullptr)
				: key(move(key)), data(data), next(n), prev(p) {}
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
void LinkedList<T>::addAsLast(const string &key, T data) {
	auto newNode = new Node<T>(key, data, nullptr, tail);
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
void LinkedList<T>::addAsFirst(const string &key, T data) {
	auto newNode = new Node<T>(key, data, head, nullptr);
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
T LinkedList<T>::get(const string &key) const {
	if (key.empty()) {
		throw out_of_range("Key is empty.");
	} else {
		Node<T> *node = head;
		while (node != nullptr) {
			if (node->key == key) {
				return node->data;
			}
			node = node->next;
		}
//		throw logic_error("Element not found");
		throw ElementNotFoundException("Element not found");
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
		cout << "Key: " << curNode->key << "\nData: " << curNode->data << endl << endl;
		curNode = curNode->next;
	}
	delete curNode;
}

template<typename T>
bool LinkedList<T>::isEmpty() const {
	return size == 0;
}


#endif //CV5_UT_18_20_LINKEDLIST_H
