#include "BoolValue.h"

BoolValue::BoolValue(bool value) {
	boolValue = value;
}

BoolValue::BoolValue(const BoolValue &boolValue) {
	this->boolValue = boolValue.boolValue;
}

bool BoolValue::get() const {
	return boolValue;
}

string BoolValue::serialize() const {
	return "";
}