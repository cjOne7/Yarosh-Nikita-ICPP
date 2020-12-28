#ifndef SEM_JSONLIBRARY_ARRAYLIST_SUBJECT_H
#define SEM_JSONLIBRARY_ARRAYLIST_SUBJECT_H

#include <ostream>
#include "./valueDir/api.h"

class Subject {
private:
	ArrayValue *subjectsList;
public:
	Subject() = default;

	virtual ~Subject();

	Subject(ArrayValue *subjectsList);

	ArrayValue *getSubjectsList() const;

	friend ostream &operator<<(ostream &os, const Subject &subject);

};


#endif //SEM_JSONLIBRARY_ARRAYLIST_SUBJECT_H
