//
// Created by nikya on 17.10.2020.
//

#include "Objekt.h"

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

Objekt::Objekt(int id) : id(id){}
