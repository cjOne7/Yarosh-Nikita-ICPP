#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
	LinkedList<int> linkedList{};
	linkedList.addAsLast("10", 10);
	linkedList.addAsLast("20", 20);
	linkedList.addAsLast("30", 30);
	linkedList.addAsLast("40", 40);
	linkedList.type();
	try {
		cout << linkedList.get("101") << endl;
	} catch (const ElementNotFoundException &ex) {
		cerr << ex.what() << endl;
	}
	return 0;
}
