#include "GrowingContainer.h"
#include <iostream>

using namespace std;

int main() {
	GrowingContainer<int> growingContainer{};
	growingContainer.add(1);
	growingContainer.add(2);
	growingContainer.add(3);
	growingContainer.add(4);
	growingContainer.add(4);
	growingContainer.add(4);
	growingContainer.add(4);
//	growingContainer.add(3, 500);

	growingContainer.remove(growingContainer.getSize() - 1);
	growingContainer.dumpData();
	return 0;
}
