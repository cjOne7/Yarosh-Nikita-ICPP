#ifndef CV3_UT_18_20_GAME_H
#define CV3_UT_18_20_GAME_H
#define DEF_VALUE 10

#include "Object.h"
#include "MoveableObject.h"

class Game {
private:
	int curIndex = 0;
	int size = DEF_VALUE;
	Object **objects = new Object *[DEF_VALUE];
public:
	Game();

	Game(int size);

	virtual ~Game();

	int getCurIndex() const;

	void addObject(Object *o);

	int *findNumberOfStaticObjectIds(double xMin, double xMax, double yMin, double yMax);

	MoveableObject **findMoveableObjects(double x, double y, double r);

	MoveableObject **findMoveableObjectsInSpecialArea(double x, double y, double r, double umin, double umax);
};

#endif //CV3_UT_18_20_GAME_H
