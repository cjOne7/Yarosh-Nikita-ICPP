#ifndef CV3_UT_18_20_STATICOBJECT_H
#define CV3_UT_18_20_STATICOBJECT_H

#include "Object.h"

enum TypeOfObstacle {
	Rock, SmallPlant, BigPlant
};

class StaticObject : public Object {
private:
	TypeOfObstacle typeOfObstacle;

public:
	StaticObject(int id, TypeOfObstacle typeOfObstacle);

	TypeOfObstacle getTypeOfObstacle() const;
};

#endif //CV3_UT_18_20_STATICOBJECT_H
