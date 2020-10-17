#include "../headfiles/MoveableObject.h"

MoveableObject::MoveableObject(int id) : Object(id) {}

MoveableObject::MoveableObject(int id, double x, double y) : Object(id, x, y) {}

MoveableObject::MoveableObject(int id, double x, double y, double rotationAngle)
		: Object(id, x, y), rotationAngle(rotationAngle) {}

double MoveableObject::getRotationAngle() const {
	return rotationAngle;
}

void MoveableObject::setRotationAngle(double rotationAngle) {
	MoveableObject::rotationAngle = rotationAngle;
}

