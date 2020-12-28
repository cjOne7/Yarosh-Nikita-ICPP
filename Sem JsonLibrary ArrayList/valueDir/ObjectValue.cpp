#include "api.h"

void ObjectValue::append(const KeyValuePair &pair) {
	dynamicObjectArray->append(pair);
}

string ObjectValue::serialize() const {
	stringstream ss;
	ss << "{";
	for (int i = 0; i < dynamicObjectArray->getSize(); ++i) {
		KeyValuePair keyValuePair = dynamicObjectArray->getElementAt(i);
		ss << '"' << keyValuePair.getKey() << "\":" << keyValuePair.getValue()->serialize();
		if (i != dynamicObjectArray->getSize() - 1) {
			ss << ',';
		}
	}
	ss << "}";
	return ss.str();
}

DynamicArray<KeyValuePair> *ObjectValue::getDynamicObjectArray() const {
	return dynamicObjectArray;
}
