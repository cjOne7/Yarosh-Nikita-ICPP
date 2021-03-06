#include <iostream>
#include "headfiles/Object.h"
#include "headfiles/StaticObject.h"
#include "headfiles/Game.h"

using namespace std;

int main() {
	Game game{};
	Object *object = new StaticObject{1, TypeOfObstacle::SmallPlant};
	Object *object1 = new StaticObject{2, TypeOfObstacle::SmallPlant};
	Object *object2 = new MoveableObject{3, 2, 3};
	Object *object3 = new MoveableObject{4};
	Object *object4 = new StaticObject{5, TypeOfObstacle::SmallPlant};
	Object *object5 = new MoveableObject{6};
	game.addObject(object);
	game.addObject(object1);
	game.addObject(object2);
	game.addObject(object3);
	game.addObject(object4);
	game.addObject(object5);

//	int *ids = game.findNumberOfStaticObjectIds(-1, 1, -1, 1);
//	for (int i = 0; i < game.getCurIndex(); ++i) {
//		if (ids[i] == 0) {
//			continue;
//		}
//		cout << ids[i] << endl;
//	}
//	delete ids;

	MoveableObject **pMoveableObject = game.findMoveableObjects(0, 0, 1);
	for (int i = 0; i < game.getCurIndex(); ++i) {
		if (pMoveableObject[i] == nullptr) {
			break;
		}
		cout << pMoveableObject[i]->getId() << endl;
	}

	delete[] pMoveableObject;
	delete object;
	delete object1;
	delete object2;
	delete object3;
	delete object4;
	delete object5;
	return 0;
}
