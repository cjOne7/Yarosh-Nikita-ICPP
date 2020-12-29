#include "NumberValue.h"

NumberValue::NumberValue(double value) {
	this->value = value;
}

double NumberValue::get() const {
	return value;
}

string NumberValue::serialize() const {
	return "";
}

NumberValue::NumberValue(const NumberValue &numberValue) {
	this->value = numberValue.value;
}
