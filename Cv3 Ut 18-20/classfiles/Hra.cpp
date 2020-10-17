#include <iostream>
#include "../headfiles/Hra.h"
#include "../headfiles/StatickyObjekt.h"

using namespace std;

Hra::Hra() = default;

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
	int counter = 0;
	for (int i = 0; i < index; ++i) {
		auto *so = dynamic_cast<StatickyObjekt *>(objekty[i]);
		if (so == nullptr) {
			cout << "Object doesn't belong to StaticObject" << endl;
		} else {
			if (so->getX() >= xmin && so->getX() <= xmax && so->getY() >= ymin && so->getY() <= ymax) {
				counter++;
			}
		}
	}
	return &counter;
}

PohyblivyObjekt **Hra::najdiPohybliveObjektyVOblasti(double x, double y, double r) {
	return nullptr;
}

PohyblivyObjekt **Hra::najdiPohybliveObjektyVOblasti(double x, double y, double r, double umin, double umax) {
	return nullptr;
}