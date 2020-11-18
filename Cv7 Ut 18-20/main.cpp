#include <iostream>
#include <fstream>
#include "Person.h"

using namespace std;

void loadBinary() {

}

void writeBinary() {

}

int main() {
	ofstream out{};
	out.open("test.dat", ios_base::binary);
	if (out.is_open()) {
		out << "radka textu";
		out.close();
	} else {
		cerr << "Soubor se nepodarilo otevrit...";
	}
	return 0;

}
