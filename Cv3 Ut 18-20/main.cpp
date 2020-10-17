#include <iostream>
#include "headfiles/Object.h"
#include "headfiles/StaticObject.h"
#include "headfiles/Game.h"

using namespace std;

int main() {
	Game game{};
	Object *object = new StaticObject{1, TypeOfObstacle::SmallPlant};
	Object *object1 = new StaticObject{2, TypeOfObstacle::SmallPlant};
	Object *object2 = new MoveableObject{3};
	Object *object3 = new MoveableObject{4};
	Object *object4 = new StaticObject{5, TypeOfObstacle::SmallPlant};
	game.addObject(object);
	game.addObject(object1);
	game.addObject(object2);
	game.addObject(object3);
	game.addObject(object4);

	cout << *game.findNumberOfStaticObjectIds(-1, 1, -1, 1) << endl;

	return 0;
}
