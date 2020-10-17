#ifndef CV3_UT_18_20_OBJEKT_H
#define CV3_UT_18_20_OBJEKT_H


class Objekt {
private:
	int id;
	double x, y;

public:
	Objekt(int id);

	Objekt(int id, double x, double y);

	virtual ~Objekt();

	double getX() const;

	void setX(double x);

	double getY() const;

	void setY(double y);

	int getId() const;
};


#endif //CV3_UT_18_20_OBJEKT_H
