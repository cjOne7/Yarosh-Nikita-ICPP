#ifndef CV5_UT_18_20_PHONELIST_H
#define CV5_UT_18_20_PHONELIST_H

#include "Person.h"
#include "MyLinkedList.h"

using namespace Entity;

namespace Model {

	class PhoneList {
	private:
		MyLinkedList<Person> *linkedList = new MyLinkedList<Person>();
	public:
		void addPerson(const Person& person);

		string findPhoneNumber(const string &name) const;

		string findPhoneNumber(int id) const;
	};

}


#endif //CV5_UT_18_20_PHONELIST_H
