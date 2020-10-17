#include "../headfiles/StaticObject.h"

StaticObject::StaticObject(int id, TypeOfObstacle typeOfObstacle) : Object(id), typeOfObstacle(typeOfObstacle) {}

TypeOfObstacle StaticObject::getTypeOfObstacle() const {
	return typeOfObstacle;
}
