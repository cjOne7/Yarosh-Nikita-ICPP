#ifndef CV3_UT_18_20_OBJECT_H
#define CV3_UT_18_20_OBJECT_H

class Object {
private:
	int id;
	double x, y;

public:
	Object(int id);

	Object(int id, double x, double y);

	virtual ~Object();

	double getX() const;

	void setX(double x);

	double getY() const;

	void setY(double y);

	int getId() const;
};


#endif //CV3_UT_18_20_OBJECT_H
