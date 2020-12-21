#ifndef TESTSEMPROJECT_NULLVALUE_H
#define TESTSEMPROJECT_NULLVALUE_H


#include "Value.h"

class NullValue : public Value {

public:
	string serialize() const override;
};


#endif //TESTSEMPROJECT_NULLVALUE_H
