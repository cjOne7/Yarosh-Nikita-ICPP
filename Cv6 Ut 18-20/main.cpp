#include "GrowingContainer.h"
#include <iostream>

using namespace std;

int main() {
	GrowingContainer<int> growingContainer{};
	growingContainer.add(1);
	growingContainer.add(2);
	growingContainer.add(3);
	growingContainer.add(4);
	growingContainer.add(3, 500);

	growingContainer.remove(3);
	growingContainer.dumpData();

	cout << growingContainer[2] << endl;
	return 0;
}
