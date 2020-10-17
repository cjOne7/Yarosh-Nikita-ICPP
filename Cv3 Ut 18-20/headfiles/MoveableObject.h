#ifndef CV3_UT_18_20_MOVEABLEOBJECT_H
#define CV3_UT_18_20_MOVEABLEOBJECT_H

#include "Object.h"

class MoveableObject : public Object {
private:
	double rotationAngle;

public:
	MoveableObject(int id);

	MoveableObject(int id, double x, double y);

	MoveableObject(int id, double x, double y, double rotationAngle);

	double getRotationAngle() const;

	void setRotationAngle(double rotationAngle);
};

#endif //CV3_UT_18_20_MOVEABLEOBJECT_H
