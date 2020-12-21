#ifndef TESTSEMPROJECT_STATEMACHINE_H
#define TESTSEMPROJECT_STATEMACHINE_H


#include "State.h"

class StateMachine {
public:
	void execute(char c);

	void execute(State state, char c);
};


#endif //TESTSEMPROJECT_STATEMACHINE_H
