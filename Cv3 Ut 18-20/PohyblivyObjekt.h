#ifndef CV3_UT_18_20_POHYBLIVYOBJEKT_H
#define CV3_UT_18_20_POHYBLIVYOBJEKT_H


#include "Objekt.h"

class PohyblivyObjekt : Objekt {
public:
	double uhelNatoceni;

	double getUhelNatoceni() const;

	void setUhelNatoceni(double uhelNatoceni);
};


#endif //CV3_UT_18_20_POHYBLIVYOBJEKT_H
