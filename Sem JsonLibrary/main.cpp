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
	KeyValuePair keyValuePair("bool", new BoolValue{true});
	dynamicArray->append({"bool1", new BoolValue{true}});
	dynamicArray->append({"bool2", new BoolValue{true}});
	dynamicArray->append({"bool3", new BoolValue{true}});

	cout << dynamicArray->getSize() << endl;

	keyValuePair = dynamicArray->getElementAt(0);
	cout << keyValuePair.getKey() << endl;

	delete dynamicArray;

	return 0;
}
