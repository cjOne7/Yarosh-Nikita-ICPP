#include <iostream>
#include "../headfiles/Hra.h"
#include "../headfiles/StaticObject.h"
#include <cmath>

using namespace std;

Hra::Hra() = default;

Hra::Hra(int size) {
	this->size = size;
	objekty = new Object *[size];
}

Hra::~Hra() {
	cout << "~Hra()" << endl;
	delete[] objekty;
}

void Hra::vlozObjekt(Object *o) {
	if (o == nullptr) {
		throw runtime_error("NullPointerException");
	}
	if (size == curIndex) {
		throw length_error("Array is full");
	}
	objekty[curIndex] = o;
	curIndex++;
}

int *Hra::najdiIdStatickychObjektu(double xmin, double xmax, double ymin, double ymax) {
	if (curIndex == 0) {
		return nullptr;
	}
	int *ids = new int[curIndex];
	int counterSO = 0;
	for (int i = 0; i < curIndex; ++i) {
		auto *so = dynamic_cast<StaticObject *>(objekty[i]);
		if (so != nullptr) {
			if (so->getX() >= xmin && so->getX() <= xmax && so->getY() >= ymin && so->getY() <= ymax) {
				ids[i] = so->getId();
				counterSO++;
			}
		}
	}
	if (counterSO == 0) {
		delete[] ids;
	} else {
		return ids;
	}
}

PohyblivyObjekt **Hra::najdiPohybliveObjektyVOblasti(double x, double y, double r) {
	if (curIndex == 0) {
		return nullptr;
	}

	auto **ptrHra = new PohyblivyObjekt *[curIndex];
	int counterSO = 0;
	for (int i = 0; i < curIndex; ++i) {
		auto *po = dynamic_cast<PohyblivyObjekt *>(objekty[i]);
		if (po != nullptr) {
			if (pow((po->getX() - x), 2) + pow((po->getY() - y), 2) <= pow(r, 2)) {
				ptrHra[i] = po;
				counterSO++;
			}
		}
	}
	if (counterSO == 0) {
		delete[] ptrHra;
	} else {
		return ptrHra;
	}
}

PohyblivyObjekt **Hra::najdiPohybliveObjektyVOblasti(double x, double y, double r, double umin, double umax) {
	return nullptr;
}