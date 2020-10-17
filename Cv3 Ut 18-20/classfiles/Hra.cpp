#include <iostream>
#include "../headfiles/Hra.h"

using namespace std;

Hra::Hra(int size) {
	this->size = size;
	objekty = new Objekt *[size];
}

Hra::~Hra() {
	cout << "~Hra()" << endl;
	delete[] objekty;
}

void Hra::vlozObjekt(Objekt *o) {
	if (o == nullptr) {
		throw runtime_error("NullPointerException");
	}
	if (size == index) {
		throw length_error("Array is full");
	}
	objekty[index] = o;
	index++;
}

int *Hra::najdiIdStatickychObjektu(double xmin, double xmax, double ymin, double ymax) {
	return nullptr;
}

PohyblivyObjekt **Hra::najdiPohybliveObjektyVOblasti(double x, double y, double r) {
	return nullptr;
}

PohyblivyObjekt **Hra::najdiPohybliveObjektyVOblasti(double x, double y, double r, double umin, double umax) {
	return nullptr;
}