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
	if (id >= 0 && id < linkedList->getSize()) {
		for (int i = 0; i < linkedList->getSize(); ++i) {
			if (linkedList->get(i).id == id) {
				return linkedList->get(i).telephone;
			}
		}
	} else {
		ostringstream os;
		os << "Record in list with id " << id << " doesn't exist." << endl;
		throw out_of_range(os.str());
	}
	return std::__cxx11::string();
}
