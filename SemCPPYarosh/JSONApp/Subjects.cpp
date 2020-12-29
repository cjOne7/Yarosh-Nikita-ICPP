#include "../JSONApp/Subjects.h"

Subjects::Subjects(ArrayValue* subjectsList) {
	if (subjectsList != nullptr) {
		this->subjectsList = subjectsList;
	}
}

Subjects::~Subjects() {
	delete subjectsList;
}

Subjects::Subjects(const ArrayValue& subjects) {
	this->subjectsList = new ArrayValue(subjects);
}

ArrayValue* Subjects::getSubjectsList() const {
	return subjectsList;
}

void Subjects::setSubjectsList(ArrayValue* subjectsList) {
	Subjects::subjectsList = subjectsList;
}

ostream& operator<<(ostream& os, const Subjects& subject) {
	os << "subjects' list: " << subject.subjectsList->serialize();
	return os;
}