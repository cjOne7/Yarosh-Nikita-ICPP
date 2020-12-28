#ifndef SEM_JSONLIBRARY_ARRAYLIST_STUDENT_H
#define SEM_JSONLIBRARY_ARRAYLIST_STUDENT_H

#include "Address.h"
#include "Subject.h"

class Student {
private:
	NumberValue *id;
	StringValue *name;
	StringValue *surname;
	NumberValue *year;
	NumberValue *credits;
	Address *address;
	Subject *subjects;
public:
	Student() = default;

	virtual ~Student();


};


#endif //SEM_JSONLIBRARY_ARRAYLIST_STUDENT_H
