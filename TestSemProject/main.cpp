#include <iostream>
#include "collection/LinkedList.h"
#include "StringMethods.h"

#include <regex>
#include <string>

#include "./valueDir/Value.h"
#include "valueDir/BoolValue.h"
#include "valueDir/NullValue.h"
#include "valueDir/NumberValue.h"

using namespace std;

bool isLetter(char character) {
	return (character >= 65 && character <= 90) || (character >= 97 && character <= 122);
}

string clearKey(const string &str) {
	int pos1 = str.find('"');
	int pos2 = str.rfind('"');
	return str.substr(pos1 + 1, pos2 - pos1 - 1);
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

	regex trueRegExp("true");
	regex falseRegExp("false");
	regex nullRegExp("null");
	regex numberRegExp("-?[\\d]+\\.?([\\d]+)?");


//	string jsonString = "{\"boolean\"  :  true,\"boolean1\" : false, \"num\"  :  123, \"null_value\" : null, \"str\" : \" some  string\"}";
//	LinkedList<Value *> *list = new LinkedList<Value *>;
//	regex keyRegExp("\"[\\w]+\"(\\s*)?:(\\s*)?");
//
//	smatch m;
//
//
//	while (regex_search(jsonString, m, keyRegExp)) {
//		string foundStr = m.str();
//		cout << "Key: " << foundStr << endl;
//		jsonString = jsonString.substr(jsonString.find(foundStr) + foundStr.size());
//		int pos = jsonString.find(",");
//		string strValue;
//		if (pos == string::npos) {
//			strValue = jsonString.substr(0, jsonString.size() - 1);
//
//			if (regex_match(strValue, trueRegExp) || regex_match(strValue, falseRegExp)) {
//				bool boolValue;
//				istringstream(strValue) >> std::boolalpha >> boolValue;
//				Value *value = new BoolValue(boolValue);
//				list->addAsLast(foundStr, value);
//			} else if (regex_match(strValue, nullRegExp)) {
//				Value *value = new NullValue();
//				list->addAsLast(foundStr, value);
//			} else if (regex_match(strValue, numberRegExp)) {
//				int intValue = stoi(strValue);
//				Value *value = new NumberValue(intValue);
//				list->addAsLast(foundStr, value);
//			} else {
//				cout << "Value: " << jsonString.substr(0, jsonString.size() - 1) << endl << endl;
//			}
//		} else {
//			cout << "Value: " << jsonString.substr(0, jsonString.find(",")) << endl << endl;
//		}
//	}
//	delete list;

	LinkedList<Value *> *list = new LinkedList<Value *>;
	Value *value = new NumberValue(12);
	list->addAsLast("num", value);
	list->type();


	return 0;
}