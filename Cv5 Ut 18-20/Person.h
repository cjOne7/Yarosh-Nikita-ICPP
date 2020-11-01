#ifndef CV5_UT_18_20_PERSON_H
#define CV5_UT_18_20_PERSON_H

#include <string>
#include <ostream>

using namespace std;

namespace Entity {
	class Person {
	public:
		int id;
		string name;
		string telephone;

		friend ostream &operator<<(ostream &os, const Person &person);

		Person(int id, const string &name, const string &telephone);
	};
}


#endif //CV5_UT_18_20_PERSON_H
