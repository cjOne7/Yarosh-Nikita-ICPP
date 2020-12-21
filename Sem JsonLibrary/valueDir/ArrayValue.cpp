#include "api.h"

void ArrayValue::append(Value *element) {
	dynamicArray->append(element);
}

string ArrayValue::serialize() const {
	return "";
}
