#include "api.h"

StringValue::StringValue(string value) {
	this->value = value;
}

string StringValue::get() const {
	return value;
}

string replaceEscapesAndQuotes(const string &str) {
	string newStr;
	newStr.push_back(str[0]);
	for (int i = 1; i < str.size() - 1; ++i) {
		switch (str[i]) {
			case '\"':newStr += "\\\"";
				break;
			case '\\':newStr += "\\\\";
				break;
			default: newStr += str[i];
				break;
		}
	}
	newStr.push_back(str[str.size() - 1]);
	return newStr;
}

string StringValue::serialize() const {
	stringstream ss;
	ss << replaceEscapesAndQuotes(value);
	return ss.str();
}

