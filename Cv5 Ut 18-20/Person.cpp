#include "Person.h"

Entity::Person::Person(int id, const string &name, const string &telephone) : id(id), name(name),
																			  telephone(telephone) {}

ostream &Entity::operator<<(ostream &os, const Entity::Person &person) {
	os << "id: " << person.id << " name: " << person.name << " telephone: " << person.telephone;
	return os;
}
