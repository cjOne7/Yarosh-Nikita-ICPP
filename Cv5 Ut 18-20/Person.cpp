#include "Person.h"

using namespace std;
using namespace Entity;

Person::Person(int id, string name, string telephone)
		: id(id), name(move(name)), telephone(move(telephone)) {}

ostream &operator<<(ostream &os, const Person &person) {
	os << "id: " << person.getId() << " name: " << person.getName() << " telephone: " << person.getTelephone();
	return os;
}

int Person::getId() const {
	return id;
}

const string &Person::getName() const {
	return name;
}

const string &Person::getTelephone() const {
	return telephone;
}
