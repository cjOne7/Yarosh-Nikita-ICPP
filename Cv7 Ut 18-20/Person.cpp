#include "Person.h"

Person::Person(Address residence, const Date &dateOfBirth, string name, string surname)
		: residence(std::move(residence)), dateOfBirth(dateOfBirth), name(std::move(name)),
		  surname(std::move(surname)) {}

ostream &operator<<(ostream &os, const Person &person) {
	os << "residence: " << person.residence
	   << " dateOfBirth: " << person.dateOfBirth
	   << " name: " << person.name
	   << " surname: " << person.surname;
	return os;
}

istream &operator>>(istream &is, Person &person) {
	is >> person.name >> person.surname >> person.dateOfBirth >> person.residence;
	return is;
}
