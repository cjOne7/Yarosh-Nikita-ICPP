#pragma once

#include "../JSONApp/Address.h"
#include "../JSONApp/Subjects.h"

class Student {
private:
	NumberValue* id;
	StringValue* name;
	StringValue* surname;
	NumberValue* year;
	NumberValue* credits;
	Address* address;
	Subjects* subjects;
public:
	Student() = default;

	virtual ~Student();

	Student(NumberValue* id, StringValue* name, StringValue* surname, NumberValue* year,
		NumberValue* credits, Address* address, Subjects* subjects);

	NumberValue* getId() const;

	StringValue* getName() const;

	StringValue* getSurname() const;

	NumberValue* getYear() const;

	NumberValue* getCredits() const;

	Address* getAddress() const;

	Subjects* getSubjects() const;

	void setId(NumberValue* id);

	void setName(StringValue* name);

	void setSurname(StringValue* surname);

	void setYear(NumberValue* year);

	void setCredits(NumberValue* credits);

	void setAddress(Address* address);

	void setSubjects(Subjects* subjects);

	friend ostream& operator<<(ostream& os, const Student& student);

};

