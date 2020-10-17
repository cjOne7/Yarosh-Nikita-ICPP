#include "../headfiles/Objekt.h"

Objekt::Objekt(int id) : id(id) {
	this->x = 0;
	this->y = 0;
}

Objekt::~Objekt() {
}

double Objekt::getX() const {
	return x;
}

void Objekt::setX(double x) {
	Objekt::x = x;
}

double Objekt::getY() const {
	return y;
}

void Objekt::setY(double y) {
	Objekt::y = y;
}

int Objekt::getId() const {
	return id;
}
