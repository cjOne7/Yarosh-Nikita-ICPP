#include "../JSONApp/Student.h"

Student::Student(NumberValue* id, StringValue* name, StringValue* surname, NumberValue* year, 
	NumberValue* credits, Address* address, Subjects* subjects)
	: id(id), name(name), surname(surname), year(year), credits(credits), address(address), subjects(subjects) {}

Student::~Student() {
	//delete id;
	//delete name;
	//delete surname;
	//delete year;
	//delete credits;
	delete address;
	delete subjects;
}

NumberValue* Student::getId() const {
	return id;
}

StringValue* Student::getName() const {
	return name;
}

StringValue* Student::getSurname() const {
	return surname;
}

NumberValue* Student::getYear() const {
	return year;
}

NumberValue* Student::getCredits() const {
	return credits;
}

Address* Student::getAddress() const {
	return address;
}

Subjects* Student::getSubjects() const {
	return subjects;
}

void Student::setId(NumberValue* id) {
	Student::id = id;
}

void Student::setName(StringValue* name) {
	Student::name = name;
}

void Student::setSurname(StringValue* surname) {
	Student::surname = surname;
}

void Student::setYear(NumberValue* year) {
	Student::year = year;
}

void Student::setCredits(NumberValue* credits) {
	Student::credits = credits;
}

void Student::setAddress(Address* address) {
	Student::address = address;
}

void Student::setSubjects(Subjects* subjects) {
	Student::subjects = subjects;
}

ostream& operator<<(ostream& os, const Student& student) {
	os << "{id: " << student.id->serialize()
		<< ", name: " << student.name->serialize()
		<< ", surname: " << student.surname->serialize()
		<< ", year: " << student.year->serialize()
		<< ", credits: " << student.credits->serialize()
		<< ", address: " << *student.address
		<< ", " << *student.subjects << "}";
	return os;
}
