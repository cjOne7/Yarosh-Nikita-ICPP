#include "Person.h"

using namespace std;

Person::Person(Address residence, Date dateOfBirth, string name, string surname)
		: residence(move(residence)), dateOfBirth(move(dateOfBirth)), name(move(name)), surname(move(surname)) {

}

ostream &operator<<(ostream &os, const Person &person) {
	os << person.name << " "
	   << person.surname << " "
	   << person.residence << " "
	   << person.dateOfBirth;
	return os;
}

istream &operator>>(istream &is, Person &person) {
	is >> person.name >> person.surname >> person.residence >> person.dateOfBirth;
	return is;
}