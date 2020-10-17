#ifndef CV3_UT_18_20_STATICKYOBJEKT_H
#define CV3_UT_18_20_STATICKYOBJEKT_H

#include "Objekt.h"

enum TypPrekazky {
	Skala, MalaRostlina, VelkaRostlina
};

class StatickyObjekt : public Objekt {
private:
	TypPrekazky typPrekazky;

public:
	StatickyObjekt(int id, TypPrekazky typPrekazky);

	TypPrekazky getTypPrekazky() const;

};

#endif //CV3_UT_18_20_STATICKYOBJEKT_H
