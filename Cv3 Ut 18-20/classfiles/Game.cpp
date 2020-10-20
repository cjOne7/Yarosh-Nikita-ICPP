#include <iostream>
#include "../headfiles/Game.h"
#include "../headfiles/StaticObject.h"
#include <cmath>
#include <vector>

using namespace std;

Game::Game() = default;

Game::Game(int size) {
	this->size = size;
	objects = new Object *[size];
}

Game::~Game() {
	delete[] objects;
}

void Game::addObject(Object *o) {
	if (o == nullptr) {
		throw runtime_error("NullPointerException");
	}
	if (size == curIndex) {
		throw length_error("Array is full");
	}
	objects[curIndex++] = o;
}

int *Game::findNumberOfStaticObjectIds(double xMin, double xMax, double yMin, double yMax) {
	if (curIndex == 0) {
		return nullptr;
	}
	vector<int> vIds;
	int counterSO = 0;
	for (int i = 0; i < curIndex; ++i) {
		auto *so = dynamic_cast<StaticObject *>(objects[i]);
		if (so != nullptr) {
			if (so->getX() >= xMin && so->getX() <= xMax && so->getY() >= yMin && so->getY() <= yMax) {
				vIds.push_back(so->getId());
				counterSO++;
			}
		}
	}
	if (counterSO == 0) {
		return new int[0];
	} else {
		int *ids = new int[counterSO];
		for (int i = 0; i < vIds.size(); ++i) {
			ids[i] = vIds.at(i);
		}
		return ids;
	}
}

MoveableObject **Game::findMoveableObjects(double x, double y, double r) {
	if (curIndex == 0) {
		return nullptr;
	}
	auto **ptrMoveableObjects = new MoveableObject *[curIndex];
	for (int i = 0; i < curIndex; ++i) {
		ptrMoveableObjects[i] = nullptr;
	}
	int counterMO = 0;
	for (int i = 0; i < curIndex; ++i) {
		auto *mo = dynamic_cast<MoveableObject *>(objects[i]);
		if (mo != nullptr) {
			if (pow((mo->getX() - x), 2) + pow((mo->getY() - y), 2) <= pow(r, 2)) {
				ptrMoveableObjects[counterMO++] = mo;
			}
		}
	}
	return counterMO == 0 ? nullptr : ptrMoveableObjects;
}

MoveableObject **Game::findMoveableObjectsInSpecialArea(double x, double y, double r, double umin, double umax) {
	if (curIndex == 0) {
		return nullptr;
	}
	auto **ptrMoveableObjects = new MoveableObject *[curIndex];
	int counterMO = 0;
	for (int i = 0; i < sizeof(objects); i++) {
		auto *mo = dynamic_cast<MoveableObject *>(objects[i]);
		if (mo != nullptr) {
			double distanceToPoint = sqrt((pow(x - objects[i]->getX(), 2)) + pow(y - objects[i]->getY(), 2));
			if (distanceToPoint <= r && mo->getRotationAngle() >= umin && mo->getRotationAngle() <= umax) {
				ptrMoveableObjects[counterMO++] = mo;
			}
		}
	}

	return counterMO == 0 ? nullptr : ptrMoveableObjects;
}

int Game::getCurIndex() const {
	return curIndex;
}
