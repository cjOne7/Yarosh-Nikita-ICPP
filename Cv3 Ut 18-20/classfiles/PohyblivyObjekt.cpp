#include "../headfiles/PohyblivyObjekt.h"

PohyblivyObjekt::PohyblivyObjekt(int id) : Object(id) {}

double PohyblivyObjekt::getUhelNatoceni() const {
	return uhelNatoceni;
}

void PohyblivyObjekt::setUhelNatoceni(double uhelNatoceni) {
	PohyblivyObjekt::uhelNatoceni = uhelNatoceni;
}
