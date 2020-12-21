#include "StringValue.h"

StringValue::StringValue(string value) {
	this->value = value;
}

string StringValue::get() const {
	return value;
}

string StringValue::serialize() const {
	return "";
}
