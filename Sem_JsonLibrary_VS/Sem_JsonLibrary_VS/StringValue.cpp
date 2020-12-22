#include "api.h"

StringValue::StringValue(string value) {
	this->value = value;
}

string StringValue::get() const {
	return value;
}

string replaceEscapeAndQuotes(const string& str) {
	string newStr;
	int counter = 0;
	while (str[counter] != '\0') {
		switch (str[counter]) {
		case '\b': newStr += "\\b";
			break;
		case '\f':newStr += "\\f";
			break;
		case '\n':newStr += "\\n";
			break;
		case '\r':newStr += "\\r";
			break;
		case '\t': newStr += "\\t";
			break;
		case '\"':newStr += "\\\"";
			break;
		case '\'':newStr += "\\\'";
			break;
		case '\\':newStr += "\\\\";
			break;
		default: newStr += str[counter];
			break;
		}
		counter++;
	}
	return newStr;
}

string StringValue::serialize() const {
	stringstream ss;
	ss << '"' << replaceEscapeAndQuotes(value) << '"';
	return ss.str();
}
