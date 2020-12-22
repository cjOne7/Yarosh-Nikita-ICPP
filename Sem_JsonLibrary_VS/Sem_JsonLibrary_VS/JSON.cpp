#include "api.h"

void JSON::addValueToObject(ObjectValue* objectValue, string strValue, string key) {
	regex boolRegExp{ "true|false" };
	regex nullRegExp{ "null" };
	regex numberRegExp{ "-?[\\d]+\\.?([\\d]+)?" };
	regex strRegExp{ "\"(\\s*)?[\\w ]*(\\s*)?\"" };
	//	regex objectRegExp{"{(\\s*)?[\\w\": ]*(\\s*)?}"};
	regex arrayRegExp("\\[[\\w,:{}\" ]*\\]");

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

string JSON::clearKey(const string& str) {
	int pos1 = str.find('"');
	int pos2 = str.rfind('"');
	return str.substr(pos1 + 1, pos2 - pos1 - 1);
}

Value* JSON::deserialize(const string& str) {
	ObjectValue* objectValue = new ObjectValue();
	string jsonString = str;
	regex keyRegExp{ "\"[\\w ]+\"(\\s*)?:(\\s*)?" };
	smatch m;
	while (regex_search(jsonString, m, keyRegExp)) {
		string foundStr = m.str();
		//cut key
		jsonString = jsonString.substr(jsonString.find(foundStr) + foundStr.size());
		//and then find value
		int pos = jsonString.find(",");
		string strValue;
		//clear key from '"' and ':'
		foundStr = clearKey(foundStr);
		if (pos == string::npos) {
			strValue = jsonString.substr(0, jsonString.size() - 1);
			addValueToObject(objectValue, strValue, foundStr);
		}
		else {
			strValue = jsonString.substr(0, pos);
			addValueToObject(objectValue, strValue, foundStr);
		}
	}

	return objectValue;
}

string JSON::serialize(const Value* value) {
	return value->serialize();
}
