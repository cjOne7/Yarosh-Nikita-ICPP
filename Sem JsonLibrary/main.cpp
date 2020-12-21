#include <iostream>
#include "valueDir/api.h"
#include "enums/DataTypesEnum.h"

using namespace std;

int main() {
//	cout << (char) 0x2c << endl;
//	cout << (char) 0x3a << endl;
//	cout << (char) 0x5b << endl;
//	cout << (char) 0x5d << endl;
//	cout << (char) 0x7b << endl;
//	cout << (char) 0x7d << endl;
	//white-spaces
//	cout << (char) 0x09 << endl;
//	cout << (char) 0x0a << endl;
//	cout << (char) 0x0d << endl;
//	cout << (char) 0x20 << endl;

//	DataTypes d = DataTypes::NULL_;
//	cout << (char) d << endl;


//	char str[] = "{\n  \"boolean\": true\n}";
//	int counter = 0;
//	while (str[counter++] != '\0') {
//		cout << str[counter] << endl;
//	}

	JSON json{};
	json.deserialize("{\"boolean\": true}");
//	cout << "{\n  \"boolean\": true\n}" << endl;

	return 0;
}
