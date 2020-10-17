#ifndef CV3_UT_18_20_HRA_H
#define CV3_UT_18_20_HRA_H
#define DEF_VALUE 10

#include "Object.h"
#include "PohyblivyObjekt.h"

class Hra {
private:
	int curIndex = 0;
	int size = DEF_VALUE;
	Object **objekty = new Object *[DEF_VALUE];
public:
	Hra();

	Hra(int size);

	virtual ~Hra();

	void vlozObjekt(Object *o);

	int *najdiIdStatickychObjektu(double xmin, double xmax, double ymin, double ymax);

	PohyblivyObjekt **najdiPohybliveObjektyVOblasti(double x, double y, double r);

	PohyblivyObjekt **najdiPohybliveObjektyVOblasti(double x, double y, double r, double umin, double umax);
};


#endif //CV3_UT_18_20_HRA_H
