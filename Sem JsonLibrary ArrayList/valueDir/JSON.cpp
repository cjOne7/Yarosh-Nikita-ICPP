#include "api.h"
#include "JsonFormatException.h"

enum JsonBrackets {
	START_OBJECT = '{',
	END_OBJECT = '}',
	START_ARRAY = '[',
	END_ARRAY = ']'
};

ObjectValue *readObject(string &jsonString);

ArrayValue *readArray(string &jsonString);

void addValueToObject(ObjectValue *objectValue, string strValue, string key) {
	regex boolRegExp{"(true|false)"};
	regex nullRegExp{"null"};
	regex numberRegExp{"-?[\\d]+\\.?([\\d]+)?(\\s*)"};
	regex strRegExp{"\"[\\w, ]*?\"(\\s*)"};

	if (regex_match(strValue, boolRegExp)) {
		bool boolValue;
		istringstream(strValue) >> boolalpha >> boolValue;
		objectValue->append(KeyValuePair{key, new BoolValue(boolValue)});
	} else if (regex_match(strValue, nullRegExp)) {
		objectValue->append(KeyValuePair{key, new NullValue()});
	} else if (regex_match(strValue, numberRegExp)) {
		double numberValue = stod(strValue);
		objectValue->append(KeyValuePair{key, new NumberValue(numberValue)});
	} else if (regex_match(strValue, strRegExp)) {
		objectValue->append(KeyValuePair{key, new StringValue(strValue)});
	} else {
		cout << "Unknown Value: " << strValue << endl << endl;
	}
}

string clearKey(const string &str) {
	int pos1 = str.find('"');
	int pos2 = str.rfind('"');
	return str.substr(pos1 + 1, pos2 - pos1 - 1);
}

void trimLeft(string &jsonString) {
	regex whitespaceRegExp{"\\s*"};
	smatch m{};
	regex_search(jsonString, m, whitespaceRegExp);
	jsonString = jsonString.substr(m.str().size());
}

void trimRight(string &jsonString) {
	regex whitespaceRegExp{"\\s+"};
	smatch m{};
	int strSize = jsonString.size();
	int whiteSpacesCounter = 0;
	for (int i = strSize - 1; i > 0; i--) {
		string c;
		c.push_back(jsonString[i]);
		if (regex_search(c, m, whitespaceRegExp)) {
			whiteSpacesCounter++;
		} else {
			break;
		}
	}
	jsonString = jsonString.substr(0, strSize - whiteSpacesCounter);
}

void trim(string &jsonString) {
	trimLeft(jsonString);
	trimRight(jsonString);
}

void checkBracketsPosition(string &jsonString, const char leftBracket, const char rightBracket) {
	trim(jsonString);
	if (jsonString[0] != leftBracket) {
		throw JsonFormatException("Value must start with correct bracket.");
	}
	if (jsonString[jsonString.size() - 1] != rightBracket) {
		throw JsonFormatException("Value must end with correct bracket.");
	}
}

void cutBrackets(string &jsonString) {
	jsonString = jsonString.substr(1);//cut '{'
	jsonString = jsonString.substr(0, jsonString.size() - 1);//cut '}'
}

void addValueToArray(ArrayValue *arrayValue, string strValue) {
	regex boolRegExp{"(true|false)"};
	regex nullRegExp{"null"};
	regex numberRegExp{"-?[\\d]+\\.?([\\d]+)?(\\s*)"};
	regex strRegExp{"\"[\\w, ]*?\"(\\s*)"};

	if (regex_match(strValue, boolRegExp)) {
		bool boolValue;
		istringstream(strValue) >> boolalpha >> boolValue;
		arrayValue->append(new BoolValue(boolValue));
	} else if (regex_match(strValue, nullRegExp)) {
		arrayValue->append(new NullValue());
	} else if (regex_match(strValue, numberRegExp)) {
		double numberValue = stod(strValue);
		arrayValue->append(new NumberValue(numberValue));
	} else if (regex_match(strValue, strRegExp)) {
		arrayValue->append(new StringValue(strValue));
	} else {
		cout << "Unknown Value: " << strValue << endl << endl;
	}
}

bool isDigit(const char character) {
	return character >= 48 && character <= 57;
}

void replaceComma(string &jsonString) {
	if (jsonString[0] == ',') {
		jsonString[0] = ' ';
		trim(jsonString);
	}
}

string cutValue(string &jsonString, const char leftBracket, const char rightBracket) {
	DynamicArray<int> leftBracketsIndexes{};
	DynamicArray<int> rightBracketsIndexes{};
	int i = 0;
	while (true) {
		if (jsonString[i] == leftBracket) {
			leftBracketsIndexes.append(i);
		} else if (jsonString[i] == rightBracket) {
			rightBracketsIndexes.append(i);
		}
		i++;
		if (leftBracketsIndexes.getSize() == rightBracketsIndexes.getSize() || i >= jsonString.size()) {
			break;
		}
	}
	string value = jsonString.substr(0, i);
	jsonString = jsonString.substr(i);
	replaceComma(jsonString);
	return value;
}

ArrayValue *readArray(string &jsonString) {
	auto arrayValue = new ArrayValue();
	checkBracketsPosition(jsonString, JsonBrackets::START_ARRAY, JsonBrackets::END_ARRAY);
	cutBrackets(jsonString);
	smatch m{};
	while (regex_search(jsonString, m, regex{"(l|e|\\d|\"|\\}|\\])\\s*,\\s*(n|t|f|\\d|\"|\\{|\\[)"})) {
		if (jsonString[0] == JsonBrackets::START_OBJECT) {
			string object = cutValue(jsonString, JsonBrackets::START_OBJECT, JsonBrackets::END_OBJECT);
			arrayValue->append(readObject(object));
		} else if (jsonString[0] == JsonBrackets::START_ARRAY) {
			string array = cutValue(jsonString, JsonBrackets::START_ARRAY, JsonBrackets::END_ARRAY);
			arrayValue->append(readArray(array));
		} else {
			string strValue = jsonString.substr(0, jsonString.find(m.str()) + 1);
			jsonString = jsonString.substr(jsonString.find(m.str()) + 2);
			replaceComma(jsonString);
			trim(jsonString);
			trim(strValue);
			addValueToArray(arrayValue, strValue);
		}
	}
	if (!jsonString.empty()) {
		trim(jsonString);
		if (jsonString[0] == JsonBrackets::START_OBJECT) {
			arrayValue->append(readObject(jsonString));
		} else if (jsonString[0] == JsonBrackets::START_ARRAY) {
			arrayValue->append(readArray(jsonString));
		} else {
			addValueToArray(arrayValue, jsonString);
		}
	}
	return arrayValue;
}

ObjectValue *readObject(string &jsonString) {
	checkBracketsPosition(jsonString, JsonBrackets::START_OBJECT, JsonBrackets::END_OBJECT);
	cutBrackets(jsonString);
	auto objectValue = new ObjectValue();

	smatch m{};
	while (regex_search(jsonString, m, regex{"\"[\\w ]+\"\\s*:\\s*"})) {
		string key = m.str();
		jsonString = jsonString.substr(jsonString.find(key) + key.size());//cut key
		key = clearKey(key);//clear key from '"' and ':'
		if (jsonString[0] == JsonBrackets::START_OBJECT) {//if object was found
			string object = cutValue(jsonString, JsonBrackets::START_OBJECT, JsonBrackets::END_OBJECT);
			objectValue->append(KeyValuePair{key, readObject(object)});
		} else if (jsonString[0] == JsonBrackets::START_ARRAY) {//if array was found
			string array = cutValue(jsonString, JsonBrackets::START_ARRAY, JsonBrackets::END_ARRAY);
			objectValue->append(KeyValuePair{key, readArray(array)});
		} else {//if primitives were found
			regex_search(jsonString, m, regex{"(l|e|\\d|\"|\\}|\\])\\s*,\\s*\""});
			int position = jsonString.find(m.str());
			string strValue;
			if ((isDigit(jsonString[0]) &&
				 (regex_match(string{jsonString[1]}, regex{"[\\s]"}) || jsonString[1] == ',' || jsonString[1] == '\0'))
				|| position != 0) {
				strValue = jsonString.substr(0, position + 1);
			} else {
				strValue = jsonString.substr(0);
			}
			addValueToObject(objectValue, strValue, key);
		}
	}
	return objectValue;
}

Value *JSON::deserialize(const string &string) {
	std::string jsonString = string;
	return readObject(jsonString);
}

string JSON::serialize(const Value *value) {
	return value->serialize();
}
