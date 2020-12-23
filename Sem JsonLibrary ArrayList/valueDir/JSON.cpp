#include "api.h"
#include "JsonFormatException.h"

void JSON::addValueToObject(ObjectValue *objectValue, string strValue, string key) {
	regex boolRegExp{"(true|false)"};
	regex nullRegExp{"null"};
	regex numberRegExp{"-?[\\d]+\\.?([\\d]+)?(\\s*)"};
	regex strRegExp{"\"[\\w, ]*?\"(\\s*)"};
	regex objectRegExp{"\\{[\\w:\\\", ]*\\}"};
	regex arrayRegExp{"\\[[\\w,:{}\" ]*\\]"};

	if (regex_match(strValue, boolRegExp)) {
		bool boolValue;
		istringstream(strValue) >> std::boolalpha >> boolValue;
		objectValue->append(KeyValuePair{key, new BoolValue(boolValue)});
	} else if (regex_match(strValue, nullRegExp)) {
		objectValue->append(KeyValuePair{key, new NullValue()});
	} else if (regex_match(strValue, numberRegExp)) {
		int intValue = stoi(strValue);
		objectValue->append(KeyValuePair{key, new NumberValue(intValue)});
	} else if (regex_match(strValue, strRegExp)) {
		objectValue->append(KeyValuePair{key, new StringValue(strValue)});
	} else {
		cout << "Unknown Value: " << strValue << endl << endl;
	}
}

string JSON::clearKey(const string &str) {
	int pos1 = str.find('"');
	int pos2 = str.rfind('"');
	return str.substr(pos1 + 1, pos2 - pos1 - 1);
}

static void trimLeft(string &jsonString) {
	regex whitespaceRegExp{"\\s*"};
	smatch m{};
	regex_search(jsonString, m, whitespaceRegExp);
	jsonString = jsonString.substr(m.str().size());
}

Value *JSON::deserialize(const string &str) {
	string jsonString = str;

	trimLeft(jsonString);
	if (jsonString[0] != '{') {
		throw JsonFormatException("Json object must start with '{'.");
	}

	regex jsonDelimiter{"(?:l|e|\\d|\"|}|])(\\s*),(\\s*)(?:\")"};
	ObjectValue *objectValue = new ObjectValue();
	regex keyRegExp{"\"[\\w ]+\"(\\s*)?:(\\s*)?"};
	smatch m{};
	while (regex_search(jsonString, m, keyRegExp)) {
		string key = m.str();
		//cut key
		jsonString = jsonString.substr(jsonString.find(key) + key.size());
		//and then find value

		regex_search(jsonString, m, jsonDelimiter);
		int commaPosition = jsonString.find(m.str());

		string strValue;
		//clear key from '"' and ':'
		key = clearKey(key);
		if (commaPosition == 0) {
			int endObjectBracketPos = jsonString.rfind("}");
			if (endObjectBracketPos == string::npos) {
				throw JsonFormatException("Json object must end with '}'.");
			}
			int curJsonSize = jsonString.size();
			strValue = jsonString.substr(0, curJsonSize - (curJsonSize - endObjectBracketPos));//remove last }
			addValueToObject(objectValue, strValue, key);
		} else {
			strValue = jsonString.substr(0, commaPosition + 1);
			addValueToObject(objectValue, strValue, key);
		}
	}
	return objectValue;
}

string JSON::serialize(const Value *value) {
	return value->serialize();
}
