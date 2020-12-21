#include <iostream>
#include "valueDir/api.h"
#include "valueDir/LinkedList.h"

using namespace std;

int main() {
//	LinkedList<KeyValuePair *> *list = new LinkedList<KeyValuePair *>();
//	list->addAsLast(new KeyValuePair{"null", new NullValue{}});
//	list->addAsLast(new KeyValuePair{"num", new NumberValue{123}});
//	list->addAsLast(new KeyValuePair{"bool", new BoolValue{true}});
//	list->type();

	DynamicArray<KeyValuePair> *dynamicArray = new DynamicArray<KeyValuePair>();
//	cout << dynamicArray->getSize() << endl;
	dynamicArray->append({"bool", new BoolValue{true}});
	delete dynamicArray;

	return 0;
}
