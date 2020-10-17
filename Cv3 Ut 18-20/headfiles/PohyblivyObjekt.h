#ifndef CV3_UT_18_20_POHYBLIVYOBJEKT_H
#define CV3_UT_18_20_POHYBLIVYOBJEKT_H

#include "Objekt.h"

class PohyblivyObjekt : Objekt {
private:
	double uhelNatoceni;

public:
	double getUhelNatoceni() const;

	PohyblivyObjekt(int id);

	void setUhelNatoceni(double uhelNatoceni);
};


#endif //CV3_UT_18_20_POHYBLIVYOBJEKT_H
