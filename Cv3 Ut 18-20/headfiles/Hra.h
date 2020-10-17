#ifndef CV3_UT_18_20_HRA_H
#define CV3_UT_18_20_HRA_H
#define DEF_VALUE 10

#include "Objekt.h"
#include "PohyblivyObjekt.h"

class Hra {
private:
	Objekt **objekty = new Objekt *[DEF_VALUE];
public:
	void vlozObjekt(Objekt *o);

	int *najdiIdStatickychObjektu(double xmin, double xmax, double ymin, double ymax);

	PohyblivyObjekt **najdiPohybliveObjektyVOblasti(double x, double y, double r);

	PohyblivyObjekt **najdiPohybliveObjektyVOblasti(double x, double y, double r, double umin, double umax);
};


#endif //CV3_UT_18_20_HRA_H
