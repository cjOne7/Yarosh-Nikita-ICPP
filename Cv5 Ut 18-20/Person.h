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
		friend ostream &operator<<(ostream &os, const Person &person);

		Person(int id, string name, string telephone);
	};
}


#endif //CV5_UT_18_20_PERSON_H
