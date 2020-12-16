#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
	LinkedList<int> linkedList{};
	linkedList.addAsLast(10);
	linkedList.addAsLast(20);
	linkedList.addAsLast(30);
	linkedList.addAsLast(40);
	linkedList.type();
	return 0;
}
