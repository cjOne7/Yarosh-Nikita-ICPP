#ifndef SEM_JSONLIBRARY_ARRAYLIST_SUBJECTS_H
#define SEM_JSONLIBRARY_ARRAYLIST_SUBJECTS_H

#include <ostream>
#include "./valueDir/api.h"

class Subjects {
private:
	ArrayValue *subjectsList;
public:
	Subjects() = default;

	Subjects(const ArrayValue &subjects);

	virtual ~Subjects();

	Subjects(ArrayValue *subjectsList);

	ArrayValue *getSubjectsList() const;

	void setSubjectsList(ArrayValue *subjectsList);

	friend ostream &operator<<(ostream &os, const Subjects &subject);

};


#endif //SEM_JSONLIBRARY_ARRAYLIST_SUBJECTS_H
