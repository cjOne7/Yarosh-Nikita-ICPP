#include "PhoneList.h"
#include <sstream>

using namespace Model;

void PhoneList::addPerson(Person person) {
	linkedList->addAsLast(person);
}

string PhoneList::findPhoneNumber(string name) const {
	return std::__cxx11::string();
}

string PhoneList::findPhoneNumber(int id) const {
	try {
		for (int i = 0; i < linkedList->getSize(); ++i) {
			if (linkedList->get(i).id == id) {
				return linkedList->get(i).telephone;
			}
		}
	}
	catch (out_of_range &ex) {
		cerr << ex.what() << endl;
	}
}
