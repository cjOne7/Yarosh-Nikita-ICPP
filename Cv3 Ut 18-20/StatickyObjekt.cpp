#include "StatickyObjekt.h"

StatickyObjekt::StatickyObjekt(int id, TypPrekazky typPrekazky) : Objekt(id), typPrekazky(typPrekazky) {}

TypPrekazky StatickyObjekt::getTypPrekazky() const {
	return typPrekazky;
}
