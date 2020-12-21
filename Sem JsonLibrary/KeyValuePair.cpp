#include "./valueDir/api.h"

KeyValuePair::KeyValuePair(string key, Value *value) {
	this->key = key;
	this->value = value;
}

Value *KeyValuePair::getValue() const {
	return value;
}

string KeyValuePair::getKey() const {
	return key;
}