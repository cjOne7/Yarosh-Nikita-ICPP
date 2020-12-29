#include <iostream>
#include "collection/LinkedList.h"
#include <regex>
#include <string>

using namespace std;

int main() {
//	string newStr = "{\"str\":\"Hello, !@#$%^&*()_/*-+=1234567890:;|,.<> ' \\\\ \\\" World?!\",\"str1\":\"Hello, ' \\\\ \\\"World?!\"}";
//	cout << newStr << endl;
//	for (int i = 0; i < newStr.size(); ++i) {
//		if (newStr[i] == '\\' && newStr[i + 1] == '\"') {
//			newStr = newStr.replace(i, 2, "\"");
//		} else if (newStr[i] == '\\' && newStr[i + 1] == '\\') {
//			newStr = newStr.replace(i, 2, "\\");
//		}
//	}
//	cout << newStr << endl;
	StringValue *stringValue = new StringValue("123");
	StringValue *stringValue1 = new StringValue(*stringValue);
	stringValue->setValue("123456");
	cout << stringValue << endl;
	cout << stringValue1 << endl;
	return 0;
}