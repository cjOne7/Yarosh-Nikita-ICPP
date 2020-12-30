#include <iostream>
#include <fstream>
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC
#include <../JSONLibrary/api.h>
#include <../JSONLibrary/JsonFormatException.h>
#include "../JSONApp/Student.h"

void writeJson(DynamicArray<Student*>* dynamicStudentsArray) {
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
	if (fileWriter.is_open()) {
		fileWriter << ss->str() << endl;
		fileWriter.flush();
		fileWriter.close();
	}
	delete ss;
}

string* readJson() {
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
	return strValue;
}

void print(DynamicArray<Student*>* dynamicStudentsArray) {
	for (int i = 0; i < dynamicStudentsArray->getSize(); ++i) {
		cout << *dynamicStudentsArray->getElementAt(i) << endl;
	}
}

int getMaxId(DynamicArray<Student*>* dynamicStudentsArray) {
	int max = dynamicStudentsArray->getElementAt(0)->getId()->get();
	for (int i = 1; i < dynamicStudentsArray->getSize(); ++i) {
		if (dynamicStudentsArray->getElementAt(i)->getId()->get() > max) {
			max = dynamicStudentsArray->getElementAt(i)->getId()->get();
		}
	}
	return max;
}

DynamicArray<Student*>* parseToDynamicArray(Value* value) {
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

	return dynamicStudentsArray;
}

string enterValue(const string &msg) {
	string str;
	cout << msg;
	getline(cin >> ws, str);
	return str;
}

void startConsoleApp(DynamicArray<Student*>* dynamicStudentsArray) {
	bool state = true;
	while (state) {
		string command;
		cout << endl;
		cout << "0 - save and exit" << endl;
		cout << "1..n - choose user for editing or delete by index" << endl;
		cout << "add - add new user" << endl;
		cout << "print - print users' list" << endl;
		cin >> command;
		if (command[0] == '0') {
			cout << "Saving..." << endl;
			writeJson(dynamicStudentsArray);
			cout << "Exiting..." << endl;
			state = false;
		}
		else if (command == "add") {
			int id = getMaxId(dynamicStudentsArray) + 1;
			string name = enterValue("Enter name: ");
			string surname = enterValue("Enter surname: ");
			try {
				string yearStr = enterValue("Enter year: ");
				int year = stoi(yearStr);

				string creditsStr = enterValue("Enter credits: ");
				int credits = stoi(creditsStr);

				string city = enterValue("Enter city: ");
				string street = enterValue("Enter street: ");

				string postCodeStr = enterValue("Enter post code: ");
				int postCode = stoi(postCodeStr);

				ObjectValue* ov = new ObjectValue();
				ov->append(KeyValuePair{ "city", new StringValue('"' + city + '"') });
				ov->append(KeyValuePair{ "street", new StringValue('"' + street + '"') });
				ov->append(KeyValuePair{ "post code", new NumberValue(postCode) });
				ArrayValue* av = new ArrayValue();
				while (true) {
					cout << "0 - exit" << endl;
					string subject;
					cout << "Enter subject: ";
					getline(cin >> ws, subject);
					if (subject[0] == '0') {
						break;
					}
					else {
						av->append(new StringValue('"' + subject + '"'));
					}
				}
				Student* newStudent = new Student(new NumberValue(id), new StringValue('"' + name + '"'), new StringValue('"' + surname + '"')
					, new NumberValue(year), new NumberValue(credits), new Address(*ov), new Subjects(*av));
				delete ov;
				delete av;
				dynamicStudentsArray->append(newStudent);
			}
			catch (const invalid_argument& ex) {
				cerr << "Conversion could not be performed" << endl;
			}
		}
		else if (command == "print") {
			print(dynamicStudentsArray);
		}
		else if (command[0] >= 48 && command[0] <= 57) {
			try {
				cout << dynamicStudentsArray->getElementAt(stoi(command)) << endl;
			}
			catch (const out_of_range& ex) {
				cerr << "User with id " << command << " doesn't exist." << endl;
				startConsoleApp(dynamicStudentsArray);
			}
		}
		else {
			cout << "Unknown command." << endl;
		}
	}
}

int main() {
	string* strValue = readJson();
	Value* value = JSON::deserialize(*strValue);
	delete strValue;
	
	DynamicArray<Student*>* dynamicStudentsArray = parseToDynamicArray(value);
	print(dynamicStudentsArray);

	startConsoleApp(dynamicStudentsArray);

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
