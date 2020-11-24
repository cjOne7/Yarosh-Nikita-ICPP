#ifndef CV7_UT_18_20_PERSON_H
#define CV7_UT_18_20_PERSON_H

#include "Address.h"
#include "Date.h"
#include <string>
#include <iostream>

using namespace std;

class Person {
private:
	Address residence;
	Date dateOfBirth;
	string name;
	string surname;

public:
	Person() = default;

	Person(Address residence, Date dateOfBirth, string name, string surname);

	friend ostream &operator<<(ostream &os, const Person &person);

	friend istream &operator>>(istream &is, Person &person);
};


#endif //CV7_UT_18_20_PERSON_H
