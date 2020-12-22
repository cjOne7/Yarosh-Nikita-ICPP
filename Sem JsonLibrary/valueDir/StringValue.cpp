#include "api.h"

StringValue::StringValue(string value) {
	this->value = value;
}

string StringValue::get() const {
	return value;
}

string StringValue::serialize() const {
	stringstream ss;
	ss << '"' << value << '"';
	return ss.str();
}

