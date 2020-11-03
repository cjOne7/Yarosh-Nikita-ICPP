#include "PhoneList.h"

using namespace Model;

string PhoneList::findPhoneNumber(const string &name) const {
	if (name.empty()) {
		throw invalid_argument("Empty name");
	}
	for (int i = 0; i < linkedList->getSize(); ++i) {
		if (linkedList->get(i).getName() == name) {
			return linkedList->get(i).getTelephone();
		}
	}
	throw out_of_range("Telephone number is not found!");
}

string PhoneList::findPhoneNumber(int id) const {
	if (id < 0) {
		throw invalid_argument("Negative id");
	}
	for (int i = 0; i < linkedList->getSize(); ++i) {
		if (linkedList->get(i).getId() == id) {
			return linkedList->get(i).getTelephone();
		}
	}
	throw out_of_range("Telephone number is not found!");
}

void PhoneList::addPerson(const Person &person) {
	linkedList->addAsLast(person);
}
