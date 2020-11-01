#ifndef CV5_UT_18_20_PHONELIST_H
#define CV5_UT_18_20_PHONELIST_H

#include "Person.h"
using namespace Entity;

namespace Model {
	class PhoneList {
	public:
		void addPerson(Person person);
		string findPhoneNumber(string name) const;
		string findPhoneNumber(int id) const;
	};
}


#endif //CV5_UT_18_20_PHONELIST_H
