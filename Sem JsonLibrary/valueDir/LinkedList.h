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

	void addAsLast(KeyValuePair *data);

	void addAsFirst(KeyValuePair *data);

	void type() const;

	virtual ~LinkedList();

private:
	template<typename V>
	struct Node {
	public:
		KeyValuePair *pair = nullptr;
		Node<KeyValuePair *> *prev = nullptr;
		Node<KeyValuePair *> *next = nullptr;

		explicit Node(KeyValuePair *pair, Node *n = nullptr, Node *p = nullptr)
				: pair(pair), next(n), prev(p) {}
	};

	int size = 0;
	Node<KeyValuePair *> *head = nullptr;
	Node<KeyValuePair *> *tail = nullptr;
};

template<typename T>
LinkedList<T>::~LinkedList<T>() {
	while (head != nullptr) {
		Node<KeyValuePair *> *temp = head;
		head = head->next;
		delete temp;
	}
}

template<typename T>
void LinkedList<T>::addAsLast(KeyValuePair *data) {
	auto newNode = new Node<KeyValuePair *>(data, nullptr, tail);
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
void LinkedList<T>::addAsFirst(KeyValuePair *data) {
	auto newNode = new Node<KeyValuePair *>(data, head, nullptr);
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
		throw invalid_argument("Key is empty.");
	} else {
		Node<KeyValuePair *> *node = head;
		while (node != nullptr) {
			if (node->pair->getKey() == key) {
				return node->pair->getValue();
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
	Node<KeyValuePair *> *curNode = head;
	while (curNode != nullptr) {
		cout << "Key: " << curNode->pair->getKey() << endl;

		if (NullValue *nullValue = dynamic_cast<NullValue *>(curNode->pair->getValue())) {
			cout << "Data: null" << endl << endl;
		} else if (BoolValue *boolValue = dynamic_cast<BoolValue *>(curNode->pair->getValue())) {
			cout << "Data: " << (boolValue->get() == 0 ? "false" : "true") << endl << endl;
		} else if (NumberValue *numberValue = dynamic_cast<NumberValue *>(curNode->pair->getValue())) {
			cout << "Data: " << numberValue->get() << endl << endl;
		} else if (StringValue *stringValue = dynamic_cast<StringValue *>(curNode->pair->getValue())) {
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
