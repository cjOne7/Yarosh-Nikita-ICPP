#include "api.h"

NumberValue::NumberValue(double value) {
	this->value = value;
}

double NumberValue::get() const {
	return value;
}

string NumberValue::serialize() const {
	stringstream ss;
	ss << value;
	return ss.str();
}
