#include <iostream>
#include "headfiles/Object.h"
#include "headfiles/StaticObject.h"
#include "headfiles/Hra.h"

using namespace std;

int main() {
	Hra hra{};
	Object* object = new StaticObject{1, TypeOfObstacle::SmallPlant};
	hra.vlozObjekt(object);

	return 0;
}
