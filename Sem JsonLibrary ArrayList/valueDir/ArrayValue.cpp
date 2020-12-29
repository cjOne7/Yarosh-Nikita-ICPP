#include "api.h"

void ArrayValue::append(Value *element) {
	dynamicArray->append(element);
}

ArrayValue::ArrayValue(const ArrayValue &arrayValue) {
	this->dynamicArray = new DynamicArray<Value *>;
	for (int i = 0; i < arrayValue.dynamicArray->getSize(); ++i) {
		if (StringValue *subject = dynamic_cast<StringValue *>(arrayValue.dynamicArray->getElementAt(i))) {
			this->dynamicArray->append(new StringValue(*subject));
		}
	}
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
