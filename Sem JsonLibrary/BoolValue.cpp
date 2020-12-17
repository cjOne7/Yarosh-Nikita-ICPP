#include "api.h"

BoolValue::BoolValue(bool value) {
	this->boolValue = value;
}

bool BoolValue::get() const {
	return boolValue;
}
