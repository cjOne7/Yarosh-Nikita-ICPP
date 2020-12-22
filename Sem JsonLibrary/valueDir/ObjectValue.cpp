#include "api.h"

void ObjectValue::append(const KeyValuePair &pair) {
	dynamicArray->append(pair);
}

string ObjectValue::serialize() const {
	stringstream ss;
	ss << "{";
	for (int i = 0; i < dynamicArray->getSize(); ++i) {
		KeyValuePair keyValuePair = dynamicArray->getElementAt(i);
		ss << '"' << keyValuePair.getKey() << "\":" << keyValuePair.getValue()->serialize();
		if (i != dynamicArray->getSize() - 1) {
			ss << ',';
		}
	}
	ss << "}";
	return ss.str();
}
