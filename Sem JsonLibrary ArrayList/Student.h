#ifndef SEM_JSONLIBRARY_ARRAYLIST_STUDENT_H
#define SEM_JSONLIBRARY_ARRAYLIST_STUDENT_H

#include <ostream>
#include "Address.h"
#include "Subjects.h"

class Student {
private:
	NumberValue *id = new NumberValue(0);
	StringValue *name = new StringValue("");
	StringValue *surname = new StringValue("");
	NumberValue *year = new NumberValue(2000);
	NumberValue *credits = new NumberValue(0);
	Address *address = new Address();
	Subjects *subjects = new Subjects();
public:
	Student() = default;

	virtual ~Student();

	Student(NumberValue *id, StringValue *name, StringValue *surname, NumberValue *year, NumberValue *credits,
			Address *address, Subjects *subjects);

	NumberValue *getId() const;

	StringValue *getName() const;

	StringValue *getSurname() const;

	NumberValue *getYear() const;

	NumberValue *getCredits() const;

	Address *getAddress() const;

	Subjects *getSubjects() const;

	void setId(NumberValue *id);

	void setName(StringValue *name);

	void setSurname(StringValue *surname);

	void setYear(NumberValue *year);

	void setCredits(NumberValue *credits);

	void setAddress(Address *address);

	void setSubjects(Subjects *subjects);

	friend ostream &operator<<(ostream &os, const Student &student);

};


#endif //SEM_JSONLIBRARY_ARRAYLIST_STUDENT_H
