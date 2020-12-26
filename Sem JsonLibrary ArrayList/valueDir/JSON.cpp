#include "api.h"
#include "JsonFormatException.h"

ObjectValue *readObject(string &jsonString);

ArrayValue *readArray(string &jsonString);

void addValueToObject(ObjectValue *objectValue, string strValue, string key) {
	regex boolRegExp{"(true|false)"};
	regex nullRegExp{"null"};
	regex numberRegExp{"-?[\\d]+\\.?([\\d]+)?(\\s*)"};
	regex strRegExp{"\"[\\w, ]*?\"(\\s*)"};
	regex arrayRegExp{"\\[[\\w,:{}\"\\. ]*\\]"};

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
	} else if (regex_match(strValue, arrayRegExp)) {
//		ArrayValue *arrayValue = new ArrayValue();
//		objectValue->append(KeyValuePair{key, arrayValue});
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

string cutValue(string &jsonString, const string &foundStr) {
	int objectStartPosition = jsonString.find(foundStr);
	string str = jsonString.substr(objectStartPosition, foundStr.size());
	jsonString = jsonString.substr(objectStartPosition + foundStr.size());
	return str;
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

}

ArrayValue *readArray(string &jsonString) {
	regex objectRegExp{"\\{[\\w:\\\"\\{},\\[ \\]]*\\}"};
	regex arrayRegExp{"\\[[\\w,:{}\"\\.\\[ \\]]*\\]"};

	auto arrayValue = new ArrayValue();
	regex commaDelimiterInArray{"(l|e|\\d|\"|\\}|\\])\\s*,\\s*(n|t|f|\\d|\"|\\{|\\[)"};
	checkBracketsPosition(jsonString, '[', ']');
	cutBrackets(jsonString);
	smatch m{};
	while (regex_search(jsonString, m, commaDelimiterInArray)) {
		if (jsonString[0] == '{') {
			regex_search(jsonString, m, objectRegExp);
			string object = cutValue(jsonString, m.str());//return object
			arrayValue->append(readObject(object));
		} else if (jsonString[0] == '[') {
			regex_search(jsonString, m, arrayRegExp);
			string array = cutValue(jsonString, m.str());//return array
			if (jsonString[0] == ',') {
				jsonString[0] = ' ';
				trim(jsonString);
			}
			arrayValue->append(readArray(array));
		} else {
			string strValue = jsonString.substr(0, jsonString.find(m.str()) + 1);
			jsonString = jsonString.substr(jsonString.find(m.str()) + 2);
			if (jsonString[0] == ',') {
				jsonString[0] = ' ';
			}
			trim(jsonString);
			trim(strValue);
			addValueToArray(arrayValue, strValue);
		}
	}
	if (!jsonString.empty()) {
		trim(jsonString);
		if (jsonString[0] == '{') {
			arrayValue->append(readObject(jsonString));
		} else if (jsonString[0] == '[') {
			arrayValue->append(readArray(jsonString));
		} else {
			addValueToArray(arrayValue, jsonString);
		}
	}
	return arrayValue;
}

ObjectValue *readObject(string &jsonString) {
	checkBracketsPosition(jsonString, '{', '}');
	cutBrackets(jsonString);
	auto objectValue = new ObjectValue();

	regex commaDelimiterInObject{"(l|e|\\d|\"|\\}|\\])\\s*,\\s*\""};
	regex objectRegExp{"\\{[\\w:\\\"\\{},\\[ \\]]*\\}"};
	regex arrayRegExp{"\\[[\\w,:{}\"\\.\\[ \\]]*\\]"};

	regex keyRegExp{"\"[\\w ]+\"\\s*:\\s*"};
	smatch m{};
	while (regex_search(jsonString, m, keyRegExp)) {
		string key = m.str();
		jsonString = jsonString.substr(jsonString.find(key) + key.size());//cut key
		key = clearKey(key);//clear key from '"' and ':'
		if (jsonString[0] == '{') {
			regex_search(jsonString, m, objectRegExp);
			string object = cutValue(jsonString, m.str());//return object
			objectValue->append(KeyValuePair{key, readObject(object)});
		} else if (jsonString[0] == '[') {
			regex_search(jsonString, m, arrayRegExp);
			string array = cutValue(jsonString, m.str());//return array
			objectValue->append(KeyValuePair{key, readArray(array)});
		} else {
			regex_search(jsonString, m, commaDelimiterInObject);
			int position = jsonString.find(m.str());
			string strValue;
			if (isDigit(jsonString[0]) || position != 0) {
				strValue = jsonString.substr(0, position + 1);
				addValueToObject(objectValue, strValue, key);
			} else {
				strValue = jsonString.substr(0);
				addValueToObject(objectValue, strValue, key);
			}
		}
	}
	return objectValue;
}

Value *JSON::deserialize(const string &str) {
	string jsonString = str;
	return readObject(jsonString);
}

string JSON::serialize(const Value *value) {
	return value->serialize();
}
