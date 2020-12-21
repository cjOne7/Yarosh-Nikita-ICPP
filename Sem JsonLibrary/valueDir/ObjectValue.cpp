#include "api.h"

void ObjectValue::append(const KeyValuePair &pair) {
	dynamicArray->append(pair);
}

string ObjectValue::serialize() const {
	return "";
}
