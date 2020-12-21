#ifndef TESTSEMPROJECT_STRINGVALUE_H
#define TESTSEMPROJECT_STRINGVALUE_H


#include "Value.h"

class StringValue : public Value {
private:
	string value;
public:
	StringValue(string value);

	string get() const;

	string serialize() const override;
};


#endif //TESTSEMPROJECT_STRINGVALUE_H
