#include <iostream>
#include <string>
#include <crtdbg.h>

#define _CRTDBG_MAP_ALLOC

using namespace std;

class Element {
public:
	Element() = default;

	~Element() {
		delete next;
	}

	explicit Element(string value) : value(std::move(value)) {}

	const string &getValue() const {
		return value;
	}

	Element *getNext() const {
		return next;
	}

	void setNext(Element *next) {
		Element::next = next;
	}

private:
	string value;
	Element *next = nullptr;
};

class LinkedList {
private:
	Element *root = nullptr;
	int size = 0;
public:
	virtual ~LinkedList() {
		delete root;
	}

	bool isEmpty() const {
		return size == 0;
	}

	bool isNotEmpty() const {
		return size != 0;
	}

	Element *getRoot() const {
		return root;
	}

	int getSize() const {
		return size;
	}

	void add(const string &value) {
		if (root == nullptr) {
			root = new Element(value);
		} else {
			Element *element = root;
			while (element->getNext() != nullptr) {
				element = element->getNext();
			}
			element->setNext(new Element(value));
		}
		size++;
	}

	void addFirst(const string &value) {
		if (root == nullptr) {
			root = new Element(value);
		} else {
			auto *element = new Element(value);
			element->setNext(root);
			root = element;
		}
		size++;
	}

	Element *find(const string &value) {
		Element *element = root;
		while (element != nullptr) {
			if (element->getValue() == value) {
				return element;
			}
			element = element->getNext();
		}
		return nullptr;
	}

	Element *remove(const string &value) {
		if (root->getValue() == value) {
			Element *element = root;
			root = root->getNext();
			size--;
			return element;
		}
		Element *element = root;
		while (element != nullptr) {
			if (element->getNext() != nullptr && element->getNext()->getValue() == value) {
				Element *deletedElement = element->getNext();
				element->setNext(element->getNext()->getNext());
				size--;
				return deletedElement;
			}
			element = element->getNext();
		}
		return nullptr;
	}

	void type() {
		Element *element = root;
		while (element != nullptr) {
			cout << element->getValue() << endl;
			element = element->getNext();
		}
	}

};

int main() {
	auto *linkedList = new LinkedList();
	linkedList->addFirst("1");
	linkedList->addFirst("2");
	linkedList->add("3");
	linkedList->addFirst("4");

//	Element *deletedElement = linkedList->remove("3");
//	if (deletedElement == nullptr) {
//		cout << "Element is not found." << endl;
//	} else {
//		deletedElement->setNext(nullptr);
//		cout << "Removed value: " << deletedElement->getValue() << endl;
//		delete deletedElement;
//	}

	linkedList->type();
	delete linkedList;

	if (_CrtDumpMemoryLeaks() == 0) {
		cout << "\nMemory leaks have not been found." << endl;
	} else {
		cout << "\nMemory leaks have been found." << endl;
	}
	return 0;
}
