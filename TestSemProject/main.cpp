#include <iostream>
#include "collection/LinkedList.h"

#include <regex>
#include <string>

using namespace std;

bool isLetter(char character) {
	return (character >= 65 && character <= 90) || (character >= 97 && character <= 122);
}

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

	if (regex_match(strValue, boolRegExp)) {
		bool boolValue;
		istringstream(strValue) >> std::boolalpha >> boolValue;
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

int main() {
//	LinkedList<int> linkedList{};
//	linkedList.addAsLast("10", 10);
//	linkedList.addAsLast("20", 20);
//	linkedList.addAsLast("30", 30);
//	linkedList.addAsLast("40", 40);
//	linkedList.type();
//	try {
//		cout << linkedList.get("101") << endl;
//	} catch (const ElementNotFoundException &ex) {
//		cerr << ex.what() << endl;
//	}
//
//	string jsonString = "{\"boolean\":true,\"boolean1\":false}";
//
//	cout << jsonString.find("\"", 35) << endl;
//
//
//	int counter = -1;
//	string keyContainer = "";
//	int startIndex, endIndex, quotesCounter = 0;
//	while (jsonString[counter++] != '\0') {
//		if (jsonString[counter] == '{') {
////			cout << jsonString[counter] << endl;
//		} else if (jsonString[counter] == ' ' || jsonString[counter] == '\n') {
//			continue;
//		} else if (jsonString[counter] == '"') {
//			if (quotesCounter == 0) {
//				startIndex = counter;
//				quotesCounter++;
//			} else if (quotesCounter == 1) {
//				endIndex = counter;
//				cout << jsonString.substr(startIndex + 1, endIndex - startIndex - 1) << endl;
//				quotesCounter = 0;
//			}
//		} else if (jsonString[counter] == ':') {
//
//		} else if (isLetter(jsonString[counter])) {
////			cout << jsonString[counter] << endl;
//		}
//	}

//	regex boolRegExp("true|false");
//	regex nullRegExp("null");
//	regex numberRegExp("-?[\\d]+\\.?([\\d]+)?");
//	regex strRegExp("\"(\\s*)?[\\w ]*(\\s*)?\"");


	string jsonString = "{\"boolean\"  :  true,\"boolean1\" : false, \"num dsa_ds\"   :  123, \"null_value\" : null, \"str\" : \" some  string\"}";
	LinkedList<Value *> *list = new LinkedList<Value *>;
	regex keyRegExp("\"[\\w ]+\"(\\s*)?:(\\s*)?");

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
			addValueToList(list, strValue, foundStr);
//			cout << "Value: " << strValue << endl << endl;
		} else {
			strValue = jsonString.substr(0, pos);
			addValueToList(list, strValue, foundStr);
//			cout << "Value: " << strValue << endl << endl;
		}
	}
	list->type();
	delete list;


	return 0;
}