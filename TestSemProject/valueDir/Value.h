#ifndef TESTSEMPROJECT_VALUE_H
#define TESTSEMPROJECT_VALUE_H

#include <string>

using namespace std;

class Value {
public:
	virtual string serialize() const = 0;
};

#endif //TESTSEMPROJECT_VALUE_H
