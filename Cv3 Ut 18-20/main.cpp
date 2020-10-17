#include <iostream>
#include "headfiles/Objekt.h"
#include "headfiles/StatickyObjekt.h"
#include "headfiles/Hra.h"

using namespace std;

int main() {
	Hra hra{};
	StatickyObjekt statickyObjekt{1, TypPrekazky::Skala};

	return 0;
}
