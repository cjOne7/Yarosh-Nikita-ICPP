#include "StringValue.h"

StringValue::StringValue(string value) {
	this->value = value;
}

string StringValue::get() const {
	return value;
}

string StringValue::serialize() const {
	return value;
}

void StringValue::setValue(const string &value) {
	StringValue::value = value;
}

StringValue::StringValue(const StringValue &stringValue) {
	this->value = stringValue.value;
}