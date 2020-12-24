#include <iostream>
#include "collection/LinkedList.h"
#include <regex>
#include <string>

using namespace std;

string clearKey(const string &str) {
	int pos1 = str.find('"');
	int pos2 = str.rfind('"');
	return str.substr(pos1 + 1, pos2 - pos1 - 1);
}

void addValueToList(LinkedList<Value *> *list, string strValue, string key) {
	regex boolRegExp("true|false");
	regex nullRegExp("null");
	regex numberRegExp("-?[\\d]+\\.?([\\d]+)?");
	regex strRegExp("\"(\\s*)?[\\w ]*(\\s*)?\"");
	regex arrayRegExp("\\[[\\w,:{}\" ]*\\]");


	if (regex_match(strValue, boolRegExp)) {
		bool boolValue;
		istringstream(strValue) >> boolalpha >> boolValue;
		Value *value = new BoolValue(boolValue);
		list->addAsLast(key, value);
	} else if (regex_match(strValue, nullRegExp)) {
		Value *value = new NullValue();
		list->addAsLast(key, value);
	} else if (regex_match(strValue, numberRegExp)) {
		int intValue = stoi(strValue);
		Value *value = new NumberValue(intValue);
		list->addAsLast(key, value);
	} else if (regex_match(strValue, strRegExp)) {
		Value *value = new StringValue(strValue);
		list->addAsLast(key, value);
	} else {
		cout << "Unknown Value: " << strValue << endl << endl;
	}
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
	jsonString = jsonString.substr(0, strSize - whiteSpacesCounter + 1);
}

void trim(string &jsonString) {
	trimLeft(jsonString);
	trimRight(jsonString);
}

int main() {
//	regex boolRegExp("true|false");
//	regex nullRegExp("null");
//	regex numberRegExp("-?[\\d]+\\.?([\\d]+)?");
//	regex strRegExp("\"(\\s*)?[\\w ]*(\\s*)?\"");

//	string jsonString = "{\"boolean\"  :  true,\"boolean1\" : false, \"num dsa_ds\"   :  123, \"null_value\" : null, \"str\" : \" some  string\"}";
//	LinkedList<Value *> *list = new LinkedList<Value *>;
//	regex keyRegExp("\"[\\w ]+\"(\\s*)?:(\\s*)?");
//
//	smatch m;
//
//	while (regex_search(jsonString, m, keyRegExp)) {
//		string foundStr = m.str();
//		//cut key
//		jsonString = jsonString.substr(jsonString.find(foundStr) + foundStr.size());
//		//and then find value
//		int pos = jsonString.find(",");
//		string strValue;
//		//clear key from '"' and ':'
//		foundStr = clearKey(foundStr);
//		if (pos == string::npos) {
//			strValue = jsonString.substr(0, jsonString.size() - 1);
//			addValueToList(list, strValue, foundStr);
////			cout << "Value: " << strValue << endl << endl;
//		} else {
//			strValue = jsonString.substr(0, pos);
//			addValueToList(list, strValue, foundStr);
////			cout << "Value: " << strValue << endl << endl;
//		}
//	}
//	list->type();
//	delete list;

	string testStr = "das asd   ";
	cout << testStr << endl;
	trimRight(testStr);
	cout << testStr << endl;
	return 0;
}