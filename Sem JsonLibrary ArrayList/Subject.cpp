#include "Subject.h"

Subject::Subject(ArrayValue *subjectsList) {
	if (subjectsList != nullptr) {
		this->subjectsList = subjectsList;
	}
}

Subject::~Subject() {
	delete subjectsList;
}

ArrayValue *Subject::getSubjectsList() const {
	return subjectsList;
}

ostream &operator<<(ostream &os, const Subject &subject) {
	os << "subjects list: " << subject.subjectsList->serialize();
	return os;
}
