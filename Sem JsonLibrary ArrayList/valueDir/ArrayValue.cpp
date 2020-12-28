#include "api.h"

void ArrayValue::append(Value *element) {
	dynamicArray->append(element);
}

string ArrayValue::serialize() const {
	stringstream ss;
	ss << "[";
	for (int i = 0; i < dynamicArray->getSize(); ++i) {
		ss << dynamicArray->getElementAt(i)->serialize();
		if (i != dynamicArray->getSize() - 1) {
			ss << ',';
		}
	}
	ss << "]";
	return ss.str();
}

DynamicArray<Value *> *ArrayValue::getDynamicArray() const {
	return dynamicArray;
}
