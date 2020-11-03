#include "Person.h"

using namespace std;
using namespace Entity;

Person::Person(int id, const string &name, const string &telephone) {
	if (id < 0 || name.empty() || telephone.empty()) {
		throw invalid_argument("Wrong constructor params.");
	}
	this->id = id;
	this->name = name;
	this->telephone = telephone;
}

ostream &operator<<(ostream &os, const Person &person) {
	os << "id: " << person.getId() << " name: " << person.getName() << " telephone: " << person.getTelephone();
	return os;
}

int Person::getId() const {
	return id;
}

string Person::getName() const {
	return name;
}

string Person::getTelephone() const {
	return telephone;
}
