#include "../headfiles/Object.h"

Object::Object(int id) : id(id), x(0), y(0) {}

Object::Object(int id, double x, double y) : id(id), x(x), y(y) {}

Object::~Object() {
}

double Object::getX() const {
	return x;
}

void Object::setX(double x) {
	Object::x = x;
}

double Object::getY() const {
	return y;
}

void Object::setY(double y) {
	Object::y = y;
}

int Object::getId() const {
	return id;
}
