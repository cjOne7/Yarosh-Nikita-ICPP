#include "../headfiles/StaticObject.h"

StaticObject::StaticObject(int id, TypeOfObstacle typeOfObstacle) : Object(id), typeOfObstacle(typeOfObstacle) {}

TypeOfObstacle StaticObject::getTypeOfObstacle() const {
	return typeOfObstacle;
}

StaticObject::StaticObject(int id, double x, double y, TypeOfObstacle typeOfObstacle)
		: Object(id, x, y), typeOfObstacle(typeOfObstacle) {}
