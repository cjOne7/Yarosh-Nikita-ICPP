#include <iostream>
#include <fstream>
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC
#include <../JSONLibrary/api.h>
#include <../JSONLibrary/JsonFormatException.h>
#include "../JSONApp/Student.h"

void replaceEscape() {

}

string buildOutputString(const DynamicArray<Student*>& dynamicStudentsArray) {
	stringstream ss;
	cout << endl;
	ss << "{\"users\":[";
	for (int i = 0; i < dynamicStudentsArray.getSize(); ++i) {
		//			cout << *dynamicStudentsArray->getElementAt(i) << endl;
		ss << *dynamicStudentsArray.getElementAt(i);
		if (i != dynamicStudentsArray.getSize() - 1) {
			ss << ',';
		}
	}
	ss << "]}";
	return ss.str();
}

void writeJson(const DynamicArray<Student*>& dynamicStudentsArray) {
	ofstream fileWriter{ "students.json" };
	if (fileWriter.is_open()) {
		fileWriter << JSON::serialize(JSON::deserialize(buildOutputString(dynamicStudentsArray))) << endl;
		fileWriter.close();
	}
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

	ifstream fileReader{};
	fileReader.open("students.json");
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
	}
	fileReader.close();

	Value* value = JSON::deserialize(*strValue);
	delete strValue;

	DynamicArray<Student*>* dynamicStudentsArray = new DynamicArray<Student*>();
	if (ObjectValue* objectValue = dynamic_cast<ObjectValue*>(value)) {
		if (ArrayValue* arrayValue = dynamic_cast<ArrayValue*>(objectValue->getDynamicObjectArray()->getElementAt(0).getValue())) {
			for (int i = 0; i < arrayValue->getDynamicArray()->getSize(); i++) {
				if (ObjectValue* objectArrayValue = dynamic_cast<ObjectValue*>(arrayValue->getDynamicArray()->getElementAt(i))) {
					DynamicArray<KeyValuePair>* students = objectArrayValue->getDynamicObjectArray();
					Student* student = new Student();
					if (NumberValue* id = dynamic_cast<NumberValue*>(students->getElementAt(0).getValue())) {
						student->setId(new NumberValue(*id));
					}
					if (StringValue* name = dynamic_cast<StringValue*>(students->getElementAt(1).getValue())) {
						student->setName(new StringValue(*name));
					}
					if (StringValue* surname = dynamic_cast<StringValue*>(students->getElementAt(2).getValue())) {
						student->setSurname(new StringValue(*surname));
					}
					if (NumberValue* year = dynamic_cast<NumberValue*>(students->getElementAt(3).getValue())) {
						student->setYear(new NumberValue(*year));
					}
					if (NumberValue* credits = dynamic_cast<NumberValue*>(students->getElementAt(4).getValue())) {
						student->setCredits(new NumberValue(*credits));
					}
					if (ObjectValue* addressObj = dynamic_cast<ObjectValue*>(students->getElementAt(5).getValue())) {
						student->setAddress(new Address(*addressObj));
					}
					if (ArrayValue* subjectsArr = dynamic_cast<ArrayValue*>(students->getElementAt(6).getValue())) {
						student->setSubjects(new Subjects(new ArrayValue(*subjectsArr)));
					}
					dynamicStudentsArray->append(student);
				}
			}
		}
	}
	delete value;


	stringstream* ss = new stringstream();
	*ss << "{\"users\":[";
	for (int i = 0; i < dynamicStudentsArray->getSize(); ++i) {
		//			cout << *dynamicStudentsArray->getElementAt(i) << endl;
		*ss << *dynamicStudentsArray->getElementAt(i);
		if (i != dynamicStudentsArray->getSize() - 1) {
			*ss << ',';
		}
	}
	*ss << "]}";

	ofstream fileWriter{ "students.json" };
	fileWriter.open("students.json");
	if (fileWriter.is_open()) {
		Value* v = JSON::deserialize(ss->str());
		fileWriter << JSON::serialize(v) << endl;
		fileWriter.flush();
		fileWriter.close();
		delete v;
	}
	delete ss;
	

	//ArrayValue* av = new ArrayValue();
	//av->append(new StringValue("123"));
	//Student* st = new Student(new NumberValue(5), new StringValue("Aaron"), new StringValue("Kirk"), new NumberValue(3)
	//	, new NumberValue(30), new Address(), new Subjects(*av));
	//delete av;
	//delete st;

	//ofstream fileWriter{};
	//fileWriter.open("students.json");
	//if (fileWriter.is_open()) {
	//	fileWriter << JSON::serialize(JSON::deserialize(buildOutputString(*dynamicStudentsArray))) << endl;
	//	fileWriter.close();
	//}
	//writeJson(*dynamicStudentsArray);

	for (int i = 0; i < dynamicStudentsArray->getSize(); ++i) {
		delete dynamicStudentsArray->getElementAt(i);
	}
	delete dynamicStudentsArray;


	if (_CrtDumpMemoryLeaks() == 0) {
		cout << "\nMemory leaks have not been found." << endl;
	}
	else {
		cout << "\nMemory leaks have been found." << endl;
	}

	return 0;
}
