#include "./api.h"
#include "./JsonFormatException.h"

enum JsonBrackets {
	START_OBJECT = '{',
	END_OBJECT = '}',
	START_ARRAY = '[',
	END_ARRAY = ']'
};

ObjectValue* readObject(string& jsonString);

ArrayValue* readArray(string& jsonString);

string clearKey(const string& str) {
	int pos1 = str.find('"');
	int pos2 = str.rfind('"');
	return str.substr(pos1 + 1, pos2 - pos1 - 1);
}

void trimLeft(string& jsonString) {
	regex whitespaceRegExp{ "\\s*" };
	smatch m{};
	regex_search(jsonString, m, whitespaceRegExp);
	jsonString = jsonString.substr(m.str().size());
}

void trimRight(string& jsonString) {
	regex whitespaceRegExp{ "\\s+" };
	smatch m{};
	int strSize = jsonString.size();
	int whiteSpacesCounter = 0;
	for (int i = strSize - 1; i > 0; i--) {
		string c;
		c.push_back(jsonString[i]);
		if (regex_search(c, m, whitespaceRegExp)) {
			whiteSpacesCounter++;
		}
		else {
			break;
		}
	}
	jsonString = jsonString.substr(0, strSize - whiteSpacesCounter);
}

void trim(string& jsonString) {
	trimLeft(jsonString);
	trimRight(jsonString);
}

void checkBracketsPosition(string& jsonString, const char leftBracket, const char rightBracket) {
	trim(jsonString);
	if (jsonString[0] != leftBracket) {
		throw JsonFormatException("Value must start with correct bracket.");
	}
	if (jsonString[jsonString.size() - 1] != rightBracket) {
		throw JsonFormatException("Value must end with correct bracket.");
	}
}

void cutBrackets(string& jsonString) {
	jsonString = jsonString.substr(1);//cut '{'
	jsonString = jsonString.substr(0, jsonString.size() - 1);//cut '}'
}

Value* getValue(const string& strValue) {
	if (regex_match(strValue, regex{ "(true|false)" })) {
		bool boolValue;
		istringstream(strValue) >> boolalpha >> boolValue;
		return new BoolValue(boolValue);
	}
	else if (regex_match(strValue, regex{ "null" })) {
		return new NullValue();
	}
	else if (regex_match(strValue, regex{ "-?[\\d]+\\.?([\\d]+)?(\\s*)" })) {
		return new NumberValue(stod(strValue));
	}
	else if (regex_match(strValue, regex{ "\"[\\w, ]*?\"(\\s*)" })) {
		return new StringValue(strValue);
	}
	else {
		cout << "Unknown Value: " << strValue << endl << endl;
		throw JsonFormatException("Unknown value");
	}
}

bool isDigit(const char character) {
	return character >= 48 && character <= 57;
}

void replaceComma(string& jsonString) {
	if (jsonString[0] == ',') {
		jsonString[0] = ' ';
		trim(jsonString);
	}
}

string cutValue(string& jsonString, const char leftBracket, const char rightBracket) {
	DynamicArray<int> leftBracketsIndexes{};
	DynamicArray<int> rightBracketsIndexes{};
	int i = 0;
	while (true) {
		if (jsonString[i] == leftBracket) {
			leftBracketsIndexes.append(i);
		}
		else if (jsonString[i] == rightBracket) {
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

ArrayValue* readArray(string& jsonString) {
	auto arrayValue = new ArrayValue();
	checkBracketsPosition(jsonString, JsonBrackets::START_ARRAY, JsonBrackets::END_ARRAY);
	cutBrackets(jsonString);
	smatch m{};
	while (regex_search(jsonString, m, regex{ "(l|e|\\d|\"|\\}|\\])\\s*,\\s*(n|t|f|\\d|\"|\\{|\\[)" })) {
		if (jsonString[0] == JsonBrackets::START_OBJECT) {
			string object = cutValue(jsonString, JsonBrackets::START_OBJECT, JsonBrackets::END_OBJECT);
			arrayValue->append(readObject(object));
		}
		else if (jsonString[0] == JsonBrackets::START_ARRAY) {
			string array = cutValue(jsonString, JsonBrackets::START_ARRAY, JsonBrackets::END_ARRAY);
			arrayValue->append(readArray(array));
		}
		else {
			string strValue = jsonString.substr(0, jsonString.find(m.str()) + 1);
			jsonString = jsonString.substr(jsonString.find(m.str()) + 2);
			replaceComma(jsonString);
			trim(jsonString);
			trim(strValue);
			arrayValue->append(getValue(strValue));
		}
	}
	if (!jsonString.empty()) {
		trim(jsonString);
		if (jsonString[0] == JsonBrackets::START_OBJECT) {
			arrayValue->append(readObject(jsonString));
		}
		else if (jsonString[0] == JsonBrackets::START_ARRAY) {
			arrayValue->append(readArray(jsonString));
		}
		else {
			arrayValue->append(getValue(jsonString));
		}
	}
	return arrayValue;
}

ObjectValue* readObject(string& jsonString) {
	checkBracketsPosition(jsonString, JsonBrackets::START_OBJECT, JsonBrackets::END_OBJECT);
	cutBrackets(jsonString);
	auto objectValue = new ObjectValue();

	smatch m{};
	while (regex_search(jsonString, m, regex{ "\"[\\w ]*\"\\s*:\\s*" })) {
		string key = m.str();
		jsonString = jsonString.substr(jsonString.find(key) + key.size());//cut key
		key = clearKey(key);//clear key from '"' and ':'
		if (jsonString[0] == JsonBrackets::START_OBJECT) {//if object was found
			string object = cutValue(jsonString, JsonBrackets::START_OBJECT, JsonBrackets::END_OBJECT);
			objectValue->append(KeyValuePair{ key, readObject(object) });
		}
		else if (jsonString[0] == JsonBrackets::START_ARRAY) {//if array was found
			string array = cutValue(jsonString, JsonBrackets::START_ARRAY, JsonBrackets::END_ARRAY);
			objectValue->append(KeyValuePair{ key, readArray(array) });
		}
		else {//if primitives were found
			regex_search(jsonString, m, regex{ "(l|e|\\d|\"|\\}|\\])\\s*,\\s*\"" });
			int position = jsonString.find(m.str());
			string strValue;
			if ((isDigit(jsonString[0]) && (regex_match(string{ jsonString[1] }, regex{ "[\\s]" })
				|| jsonString[1] == ',' || jsonString[1] == '\0')) || position != 0) {
				strValue = jsonString.substr(0, position + 1);
			}
			else {
				strValue = jsonString.substr(0);
			}
			objectValue->append(KeyValuePair{ key, getValue(strValue) });
		}
	}
	return objectValue;
}

Value* JSON::deserialize(const string& string) {
	std::string jsonString = string;
	return readObject(jsonString);
}

string JSON::serialize(const Value* value) {
	return value->serialize();
}
