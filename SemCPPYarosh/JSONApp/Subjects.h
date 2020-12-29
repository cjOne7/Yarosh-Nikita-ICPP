#pragma once
#include <ostream>
#include "../JSONLibrary/api.h"

class Subjects {
private:
	ArrayValue* subjectsList;
public:
	Subjects() = default;

	virtual ~Subjects();

	Subjects(const ArrayValue& subjects);

	Subjects(ArrayValue* subjectsList);

	ArrayValue* getSubjectsList() const;

	void setSubjectsList(ArrayValue* subjectsList);

	friend ostream& operator<<(ostream& os, const Subjects& subject);

};