#ifndef CV5_UT_18_20_PERSON_H
#define CV5_UT_18_20_PERSON_H

#include <string>
#include <ostream>

using namespace std;

namespace Entity {
	class Person {
	private:
		int id = -1;
		string name;
		string telephone;
	public:

		friend ostream &operator<<(ostream &os, const Person &person);

		int getId() const;

		const string &getName() const;

		const string &getTelephone() const;

		Person(int id, const string &name, const string &telephone);
	};
}


#endif //CV5_UT_18_20_PERSON_H
