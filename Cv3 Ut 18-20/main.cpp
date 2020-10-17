#include <iostream>
#include "headfiles/Objekt.h"
#include "headfiles/StatickyObjekt.h"
#include "headfiles/Hra.h"

using namespace std;

int main() {
	Hra hra{};
	Objekt* objekt = new StatickyObjekt{1, TypPrekazky::MalaRostlina};
	hra.vlozObjekt(objekt);
	return 0;
}
