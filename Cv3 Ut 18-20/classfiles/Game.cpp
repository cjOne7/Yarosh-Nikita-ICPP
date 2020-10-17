#include <iostream>
#include "../headfiles/Game.h"
#include "../headfiles/StaticObject.h"
#include <cmath>

using namespace std;

Game::Game() = default;

Game::Game(int size) {
	this->size = size;
	objects = new Object *[size];
}

Game::~Game() {
	cout << "Game()" << endl;
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
	int *ids = new int[curIndex];
	int counterSO = 0;
	for (int i = 0; i < curIndex; ++i) {
		auto *so = dynamic_cast<StaticObject *>(objects[i]);
		if (so != nullptr) {
			if (so->getX() >= xMin && so->getX() <= xMax && so->getY() >= yMin && so->getY() <= yMax) {
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

MoveableObject **Game::findMoveableObjects(double x, double y, double r) {
	if (curIndex == 0) {
		return nullptr;
	}

	auto **ptrHra = new MoveableObject *[curIndex];
	int counterSO = 0;
	for (int i = 0; i < curIndex; ++i) {
		auto *po = dynamic_cast<MoveableObject *>(objects[i]);
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

MoveableObject **Game::findMoveableObjectsInSpecialArea(double x, double y, double r, double umin, double umax) {
	return nullptr;
}