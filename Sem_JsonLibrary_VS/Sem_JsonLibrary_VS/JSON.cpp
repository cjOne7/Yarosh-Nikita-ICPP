#include "api.h"
#include "JsonFormatException.h"

void addValueToObject(ObjectValue* objectValue, string strValue, string key) {
	regex boolRegExp{ "(true|false)" };
	regex nullRegExp{ "null" };
	regex numberRegExp{ "-?[\\d]+\\.?([\\d]+)?(\\s*)" };
	regex strRegExp{ "\"[\\w, ]*?\"(\\s*)" };

	if (regex_match(strValue, boolRegExp)) {
		bool boolValue;
		istringstream(strValue) >> std::boolalpha >> boolValue;
		objectValue->append(KeyValuePair{ key, new BoolValue(boolValue) });
	}
	else if (regex_match(strValue, nullRegExp)) {
		objectValue->append(KeyValuePair{ key, new NullValue() });
	}
	else if (regex_match(strValue, numberRegExp)) {
		int intValue = stoi(strValue);
		objectValue->append(KeyValuePair{ key, new NumberValue(intValue) });
	}
	else if (regex_match(strValue, strRegExp)) {
		objectValue->append(KeyValuePair{ key, new StringValue(strValue) });
	}
	else {
		cout << "Unknown Value: " << strValue << endl << endl;
	}
}

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

void checkObjectBrackets(string& jsonString) {
	trim(jsonString);
	if (jsonString[0] != '{') {
		throw JsonFormatException("Json object must start with '{'.");
	}
	if (jsonString[jsonString.size() - 1] != '}') {
		throw JsonFormatException("Json object must end with '}'.");
	}
}

void eraseObjectBrackets(string& jsonString) {
	jsonString = jsonString.substr(1);//cut '{'
	jsonString = jsonString.substr(0, jsonString.size() - 1);//cut '}'
}

ObjectValue* readObject(string& jsonString) {
	checkObjectBrackets(jsonString);
	eraseObjectBrackets(jsonString);
	auto objectValue = new ObjectValue();

	regex commaDelimiter{ "(l|e|\\d|\"|\\}|\\])\\s*,\\s*\"" };
	regex objectRegExp{ "\\{[\\w:\\\"\\{},\\[ \\]]*\\}" };
	regex arrayRegExp{ "\\[[\\w,:{}\" ]*\\]" };

	regex keyRegExp{ "\"[\\w ]+\"\\s*:\\s*" };
	smatch m{};
	while (regex_search(jsonString, m, keyRegExp)) {
		string key = m.str();
		//cut key
		jsonString = jsonString.substr(jsonString.find(key) + key.size());
		//and then find value
		if (jsonString[0] == '{') {
			regex_search(jsonString, m, objectRegExp);
			int objectStartPosition = jsonString.find(m.str());
			string str = jsonString.substr(objectStartPosition, m.str().size());
			//			cout << str << endl;
			key = clearKey(key);
			jsonString = jsonString.substr(objectStartPosition + m.str().size());
			objectValue->append(KeyValuePair{ key, readObject(str) });
		}
		else if (jsonString[0] == '[') {
			regex_search(jsonString, m, arrayRegExp);
		}
		else {
			regex_search(jsonString, m, commaDelimiter);
			int position = jsonString.find(m.str());
			string strValue;
			//clear key from '"' and ':'
			key = clearKey(key);
			if (position == 0) {//== 0 if not found
				strValue = jsonString.substr(0);//remove last }
				addValueToObject(objectValue, strValue, key);
			}
			else {
				strValue = jsonString.substr(0, position + 1);
				addValueToObject(objectValue, strValue, key);
			}
		}
	}
	return objectValue;
}

Value* JSON::deserialize(const string& str) {
	string jsonString = str;
	return readObject(jsonString);
}

string JSON::serialize(const Value* value) {
	return value->serialize();
}
