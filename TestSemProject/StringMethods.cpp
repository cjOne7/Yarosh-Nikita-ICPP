#include "StringMethods.h"

int StringMethods::strlen(const string &str) {
	int counter = 0;
	while (str[counter] != '\0') {
		counter++;
	}
	return counter;
}


