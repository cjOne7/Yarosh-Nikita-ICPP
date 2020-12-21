#include <iostream>
#include "api.h"

using namespace std;

Value *JSON::deserialize(const string &string) {

	int counter = -1;
	while (string[counter++] != '\0') {
		cout << string[counter] << endl;
	}
	return nullptr;
}

string JSON::serialize(const Value *value) {
	return "";
}
