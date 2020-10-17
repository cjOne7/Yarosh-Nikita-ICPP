#ifndef CV3_UT_18_20_MONSTRUM_H
#define CV3_UT_18_20_MONSTRUM_H


#include "PohyblivyObjekt.h"

class Monstrum : public PohyblivyObjekt {
private:
	int hp, maxHp;
public:
	int getHp() const;

	void setHp(int hp);

	int getMaxHp() const;

	void setMaxHp(int maxHp);
};


#endif //CV3_UT_18_20_MONSTRUM_H
