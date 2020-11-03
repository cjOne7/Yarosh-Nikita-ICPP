#include "Person.h"

using namespace std;
using namespace Entity;

Person::Person(int id, string name, string telephone)
		: id(id), name(move(name)), telephone(move(telephone)) {}

ostream &operator<<(ostream &os, const Person &person) {
	os << "id: " << person.id << " name: " << person.name << " telephone: " << person.telephone;
	return os;
}
