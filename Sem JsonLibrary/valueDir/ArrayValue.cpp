#include "api.h"

void ArrayValue::append(Value *element) {
	dynamicArray->append(element);
}

string ArrayValue::serialize() const {
	stringstream ss;
	for (int i = 0; i < dynamicArray->getSize(); ++i) {
		ss << dynamicArray->getElementAt(i)->serialize();
	}
	return ss.str();
}
