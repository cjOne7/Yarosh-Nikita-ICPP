#ifndef SEM_JSONLIBRARY_BRACKETSENUM_H
#define SEM_JSONLIBRARY_BRACKETSENUM_H

#include <stdexcept>
#include <iostream>
#include <sstream>
#include "ElementNotFoundException.h"
#include "api.h"

using namespace std;

template<typename T>
class LinkedList {

public:
	bool isEmpty() const;

	Value *get(const string &key) const;

	int getSize() const;

	void addAsLast(const string &key, Value *data);

	void addAsFirst(const string &key, Value *data);

	void type() const;

	virtual ~LinkedList();

private:
	template<typename V>
	struct Node {
	public:
		string key;
		Value *data = nullptr;
		Node<Value *> *prev = nullptr;
		Node<Value *> *next = nullptr;

		explicit Node(string key, Value *&data, Node *n = nullptr, Node *p = nullptr)
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
void LinkedList<T>::addAsLast(const string &key, Value *data) {
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
void LinkedList<T>::addAsFirst(const string &key, Value *data) {
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
Value *LinkedList<T>::get(const string &key) const {
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
		throw ElementNotFoundException("Element not found");
	}
}

template<typename T>
int LinkedList<T>::getSize() const {
	return size;
}

template<typename T>
void LinkedList<T>::type() const {
	Node<Value *> *curNode = head;
	while (curNode != nullptr) {
		cout << "Key: " << curNode->key << endl;

		if (NullValue *nullValue = dynamic_cast<NullValue *>(curNode->data)) {
			cout << "Data: null" << endl << endl;
		} else if (BoolValue *boolValue = dynamic_cast<BoolValue *>(curNode->data)) {
			cout << "Data: " << (boolValue->get() == 0 ? "false" : "true") << endl << endl;
		} else if (NumberValue *numberValue = dynamic_cast<NumberValue *>(curNode->data)) {
			cout << "Data: " << numberValue->get() << endl << endl;
		} else if (StringValue *stringValue = dynamic_cast<StringValue *>(curNode->data)) {
			cout << "Data: " << stringValue->get() << endl << endl;
		} else {
			cout << "What a fuck is this?!" << endl;
		}
		curNode = curNode->next;
	}
	delete curNode;
}

template<typename T>
bool LinkedList<T>::isEmpty() const {
	return size == 0;
}


#endif //SEM_JSONLIBRARY_BRACKETSENUM_H
