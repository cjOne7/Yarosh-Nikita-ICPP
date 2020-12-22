#include "api.h"

BoolValue::BoolValue(bool value) {
	boolValue = value;
}

bool BoolValue::get() const {
	return boolValue;
}

string BoolValue::serialize() const {
	stringstream ss;
	ss << (boolValue == 0 ? "false" : "true");
	return ss.str();
}
