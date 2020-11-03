#ifndef CV5_UT_18_20_PHONELIST_H
#define CV5_UT_18_20_PHONELIST_H

#include "Person.h"
#include "MyLinkedList.h"

using namespace Entity;

namespace Model {
	template<typename T>
	class PhoneList {
	private:
		MyLinkedList<T> *linkedList = new MyLinkedList<T>();
	public:
		void addPerson(T person);

		string findPhoneNumber(const string &name) const;

		string findPhoneNumber(int id) const;
	};

	template<typename T>
	string PhoneList<T>::findPhoneNumber(const string &name) const {
		try {
			if (name.empty()) {
				throw invalid_argument("Empty name");
			}
			for (int i = 0; i < linkedList->getSize(); ++i) {
				if (linkedList->get(i).getName() == name) {
					return linkedList->get(i).getTelephone();
				}
			}
		}
		catch (out_of_range &ex) {
			cerr << ex.what() << endl;
		}
		catch (invalid_argument &ex) {
			cerr << ex.what() << endl;
		}
		return "";
	}

	template<typename T>
	string PhoneList<T>::findPhoneNumber(int id) const {
		try {
			if (id < 0) {
				throw invalid_argument("Negative id");
			}
			for (int i = 0; i < linkedList->getSize(); ++i) {
				if (linkedList->get(i).getId() == id) {
					return linkedList->get(i).getTelephone();
				}
			}
		}
		catch (out_of_range &ex) {
			cerr << ex.what() << endl;
		}
		catch (invalid_argument &ex) {
			cerr << ex.what() << endl;
		}
		return "";
	}

	template<typename T>
	void PhoneList<T>::addPerson(T person) {
		linkedList->addAsLast(person);
	}
}


#endif //CV5_UT_18_20_PHONELIST_H
