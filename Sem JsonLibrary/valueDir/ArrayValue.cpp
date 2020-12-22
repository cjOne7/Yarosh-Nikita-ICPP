#include "api.h"

void ArrayValue::append(Value *element) {
	dynamicArray->append(element);
}

string ArrayValue::serialize() const {
	stringstream ss;
	for (int i = 0; i < dynamicArray->getSize(); ++i) {
		Value *value = dynamicArray->getElementAt(i);
		ss << value->serialize();
	}
	return ss.str();
}
