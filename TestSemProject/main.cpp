#include <iostream>
#include "collection/LinkedList.h"
#include <regex>
#include <string>

using namespace std;

bool isNumber(const string &str) {
	try {
		stoi(str);
		return true;
	} catch (const invalid_argument &ex) {
		return false;
	}
}

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
	cout << isNumber("jj12wdaasd3");
	return 0;
}