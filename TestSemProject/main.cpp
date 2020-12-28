#include <iostream>
#include "collection/LinkedList.h"
#include <regex>
#include <string>
#include <vector>

using namespace std;

int main() {
	string newStr = "{\"str\":\"Hello, !@#$%^&*()_/*-+=1234567890:;|,.<> ' \\\\ \\\" World?!\",\"str1\":\"Hello, ' \\\\ \\\"World?!\"}";
	cout << newStr << endl;
	for (int i = 0; i < newStr.size(); ++i) {
		if (newStr[i] == '\\' && newStr[i + 1] == '\"') {
			newStr = newStr.replace(i, 2, "\"");
		} else if (newStr[i] == '\\' && newStr[i + 1] == '\\') {
			newStr = newStr.replace(i, 2, "\\");
		}
	}
	cout << newStr << endl;
	return 0;
}