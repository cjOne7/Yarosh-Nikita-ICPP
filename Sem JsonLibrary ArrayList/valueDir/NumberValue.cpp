#include "api.h"

NumberValue::NumberValue(double value) {
	this->value = value;
}

double NumberValue::get() const {
	return value;
}

NumberValue::NumberValue(const NumberValue &numberValue) {
	this->value = numberValue.value;
}

string NumberValue::serialize() const {
	stringstream ss;
	ss << value;
	return ss.str();
}
