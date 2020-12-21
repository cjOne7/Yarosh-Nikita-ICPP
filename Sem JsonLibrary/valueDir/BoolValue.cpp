#include "api.h"

BoolValue::BoolValue(bool value) {
	boolValue = value;
}

bool BoolValue::get() const {
	return boolValue;
}

string BoolValue::serialize() const {
	return "";
}
