#include "Student.h"


Student::~Student() {
	delete id;
	delete name;
	delete surname;
	delete year;
	delete credits;
	delete address;
	delete subjects;
}
