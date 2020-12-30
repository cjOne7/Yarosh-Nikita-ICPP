#include "pch.h"
#include "../JSONLibrary/api.h"

BoolValue::BoolValue(bool value) {
	boolValue = value;
}

BoolValue::BoolValue(const BoolValue& boolValue) {
	this->boolValue = boolValue.boolValue;
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

NumberValue::NumberValue(const NumberValue& numberValue) {
	this->value = numberValue.value;
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

DynamicArray<Value*>* ArrayValue::getDynamicArray() const
{
	return dynamicArray;
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

DynamicArray<KeyValuePair>* ObjectValue::getDynamicObjectArray() const
{
	return dynamicObjectArray;
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

StringValue::StringValue(string value) {
	this->value = value;
}

StringValue::StringValue(const StringValue& stringValue) {
	this->value = stringValue.value;
}

string StringValue::get() const {
	return value;
}

string StringValue::serialize() const {
	stringstream ss;
	ss << replaceEscapesAndQuotes(value);
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
