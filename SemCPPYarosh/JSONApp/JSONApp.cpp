#include <iostream>
#include <../JSONLibrary/api.h>
#include <../JSONLibrary/JsonFormatException.h>
#include <fstream>
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC
#include "../JSONApp/Adress.h"

void perlaceEscape() {

}

int main() {
	//   Value* value = JSON::deserialize(
	//       "{\"users\":[{\"id\":1,\"name\":\"Nikita\",\"surname\":\"Yarosh\",\"year\":3,\"credits\":30,\"address\":{\"city\":\"Pardubice\",\"street\":\"Studentska 199\",\"post code\":53009},\"subjects' list\":[\"IMOSI\",\"IWWW\",\"ICPP\",\"IDAS2\"]},{\"id\":2,\"name\":\"Vlad\",\"surname\":\"Ermolaev\",\"year\":3,\"credits\":30,\"address\":{\"city\":\"Kolin\",\"street\":\"Studentska 199\",\"post code\":53009},\"subjects' list\":[\"IMOSI\",\"IWWW\",\"ICPP\",\"IDAS2\"]},{\"id\":3,\"name\":\"Andrii\",\"surname\":\"Andrusenko\",\"year\":3,\"credits\":30,\"address\":{\"city\":\"Prelouc\",\"street\":\"Studentska 199\",\"post code\":53009},\"subjects' list\":[\"IMOSI\",\"IWWW\",\"ICPP\",\"IDAS2\"]},{\"id\":4,\"name\":\"Dmytro\",\"surname\":\"Hrychanok\",\"year\":3,\"credits\":30,\"address\":{\"city\":\"Pardubice\",\"street\":\"Studentska 199\",\"post code\":53009},\"subjects' list\":[]}]}");
	   //ofstream fileWriter{};
	   //fileWriter.open("students.json");
	   //if (fileWriter.is_open()) {
	   //	fileWriter << JSON::serialize(value);
	   //}
	   //fileWriter.close();
	   //cout << JSON::serialize(value) << endl;

	ifstream fileReader{ "students.json" };
	string* strValue = new string("");
	if (fileReader.is_open()) {
		getline(fileReader, *strValue);
		for (int i = 0; i < strValue->size(); ++i) {
			if ((*strValue)[i] == '\\' && (*strValue)[i + 1] == '\"') {
				*strValue = strValue->replace(i, 2, "\"");
			}
			else if ((*strValue)[i] == '\\' && (*strValue)[i + 1] == '\\') {
				*strValue = strValue->replace(i, 2, "\\");
			}
		}
		Value* value = JSON::deserialize(*strValue);
		if (ObjectValue* objectValue = dynamic_cast<ObjectValue*>(value)) {
			if (ArrayValue* arrayValue = dynamic_cast<ArrayValue*>(objectValue->getDynamicObjectArray()->getElementAt(0).getValue())) {
				for (int i = 0; i < arrayValue->getDynamicArray()->getSize(); ++i) {
					if (ObjectValue* objectArrayValue = dynamic_cast<ObjectValue*>(arrayValue->getDynamicArray()->getElementAt(i))) {
						cout << objectArrayValue->serialize() << endl;
					}
				}
			}
		}
		//cout << JSON::serialize(value) << endl;
		delete strValue;
		delete value;
	}
	fileReader.close();

	if (_CrtDumpMemoryLeaks() == 0) {
		cout << "\nMemory leaks have not been found." << endl;
	}
	else {
		cout << "\nMemory leaks have been found." << endl;
	}

	return 0;
}
