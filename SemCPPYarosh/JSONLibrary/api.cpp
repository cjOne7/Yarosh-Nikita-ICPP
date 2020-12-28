#include "pch.h"
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

string NullValue::serialize() const {
	stringstream ss;
	ss << "null";
	return ss.str();
}

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

void ArrayValue::append(Value* element) {
	dynamicArray->append(element);
}

string ArrayValue::serialize() const {
	stringstream ss;
	ss << "[";
	for (int i = 0; i < dynamicArray->getSize(); ++i) {
		ss << dynamicArray->getElementAt(i)->serialize();
		if (i != dynamicArray->getSize() - 1) {
			ss << ',';
		}
	}
	ss << "]";
	return ss.str();
}

void ObjectValue::append(const KeyValuePair& pair) {
	dynamicObjectArray->append(pair);
}

string ObjectValue::serialize() const {
	stringstream ss;
	ss << "{";
	for (int i = 0; i < dynamicObjectArray->getSize(); ++i) {
		KeyValuePair keyValuePair = dynamicObjectArray->getElementAt(i);
		ss << '"' << keyValuePair.getKey() << "\":" << keyValuePair.getValue()->serialize();
		if (i != dynamicObjectArray->getSize() - 1) {
			ss << ',';
		}
	}
	ss << "}";
	return ss.str();
}

string replaceEscapesAndQuotes(const string& str) {
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

StringValue::StringValue(string value) {
	this->value = value;
}

string StringValue::get() const {
	return value;
}

string StringValue::serialize() const {
	stringstream ss;
	//ss << replaceEscapesAndQuotes(value);
	ss << value;
	return ss.str();
}

KeyValuePair::KeyValuePair(string key, Value* value) {
	this->key = key;
	this->value = value;
}

string KeyValuePair::getKey() const {
	return key;
}

Value* KeyValuePair::getValue() const {
	return value;
}
