#include "Person.h"

Person::Person(Address residence, const Date &dateOfBirth, string name, string surname)
		: residence(std::move(residence)), dateOfBirth(dateOfBirth), name(std::move(name)),
		  surname(std::move(surname)) {}

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