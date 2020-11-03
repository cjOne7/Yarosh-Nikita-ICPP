#ifndef CV5_UT_18_20_PERSON_H
#define CV5_UT_18_20_PERSON_H

#include <string>
#include <ostream>

using namespace std;

namespace Entity {
	class Person {
	private:
		int id;
		string name;
		string telephone;
	public:

		int getId() const;

		string getName() const;

		string getTelephone() const;

		Person(int id, const string &name, const string &telephone);

		friend ostream &operator<<(ostream &os, const Person &person);
	};
}


#endif //CV5_UT_18_20_PERSON_H
