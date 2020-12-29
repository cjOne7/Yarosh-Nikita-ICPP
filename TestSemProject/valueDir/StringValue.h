#ifndef TESTSEMPROJECT_STRINGVALUE_H
#define TESTSEMPROJECT_STRINGVALUE_H


#include "Value.h"

class StringValue : public Value {
private:
	string value;
public:
	StringValue(string value);

	StringValue(const StringValue &stringValue);

	string get() const;

	void setValue(const string &value);

	string serialize() const override;
};


#endif //TESTSEMPROJECT_STRINGVALUE_H
