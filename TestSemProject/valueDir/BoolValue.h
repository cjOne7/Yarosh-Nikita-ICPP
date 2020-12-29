#ifndef TESTSEMPROJECT_BOOLVALUE_H
#define TESTSEMPROJECT_BOOLVALUE_H


#include "Value.h"

class BoolValue : public Value {
private:
	bool boolValue;

public:
	BoolValue(bool value);

	BoolValue(const BoolValue &boolValue);

	bool get() const;

	string serialize() const override;
};


#endif //TESTSEMPROJECT_BOOLVALUE_H
