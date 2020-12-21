#ifndef TESTSEMPROJECT_NUMBERVALUE_H
#define TESTSEMPROJECT_NUMBERVALUE_H


#include <ostream>
#include "Value.h"

class NumberValue : public Value {
private:
	double value;
public:
	NumberValue(double value);

	double get() const;

	string serialize() const override;
};


#endif //TESTSEMPROJECT_NUMBERVALUE_H
