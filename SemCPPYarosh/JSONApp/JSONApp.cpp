#include <iostream>
#include <fstream>
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC
#include <api.h>
#include <JsonFormatException.h>
#include "Student.h"

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

string enterValue(const string& msg) {
	string str;
	cout << msg;
	getline(cin >> ws, str);
	return str;
}

bool isNumber(const string& str) {
	try {
		stoi(str);
		return true;
	}
	catch (const invalid_argument& ex) {
		return false;
	}
}

void editStudent(Student* student, DynamicArray<Student*>* dynamicStudentsArray, int index) {
	try {
		bool state = true;
		while (state) {
			cout << *student << endl;
			cout << endl;
			cout << "1 - edit name" << endl;
			cout << "2 - edit surname" << endl;
			cout << "3 - edit year" << endl;
			cout << "4 - edit credits" << endl;
			cout << "5 - edit city" << endl;
			cout << "6 - edit street" << endl;
			cout << "7 - edit post code" << endl;
			cout << "8 - edit subjects" << endl;
			cout << "9 - delete this user" << endl;
			cout << "0 - back" << endl;
			string command = enterValue("Start editing. Enter command number: ");
			if (command[0] == '1') {
				delete student->getName();
				string  newName = enterValue("Enter new name: ");
				student->setName(new StringValue('"' + newName + '"'));
			}
			else if (command[0] == '2') {
				delete student->getSurname();
				string  newSurname = enterValue("Enter new surname: ");
				student->setSurname(new StringValue('"' + newSurname + '"'));
			}
			else if (command[0] == '3') {
				delete student->getYear();
				string  newYearStr = enterValue("Enter new year: ");
				int newYear = stoi(newYearStr);
				student->setYear(new NumberValue(newYear));
			}
			else if (command[0] == '4') {
				delete student->getCredits();
				string  newCreditsStr = enterValue("Enter new credits' value: ");
				int newCredits = stoi(newCreditsStr);
				student->setCredits(new NumberValue(newCredits));
			}
			else if (command[0] == '5') {
				delete student->getAddress()->getCity();
				string  newCity = enterValue("Enter new city: ");
				student->getAddress()->setCity(new StringValue('"' + newCity + '"'));
			}
			else if (command[0] == '6') {
				delete student->getAddress()->getStreet();
				string  newStreet = enterValue("Enter new street: ");
				student->getAddress()->setStreet(new StringValue('"' + newStreet + '"'));
			}
			else if (command[0] == '7') {
				delete student->getAddress()->getPostCode();
				string  newPostCodeStr = enterValue("Enter new post code: ");
				int newPostCode = stoi(newPostCodeStr);
				student->getAddress()->setPostCode(new NumberValue(newPostCode));
			}
			else if (command[0] == '8') {
				ArrayValue* av = new ArrayValue();
				while (true) {
					cout << "0 - exit" << endl;
					string subject = enterValue("Enter new subject: ");
					if (subject[0] == '0') {
						break;
					}
					else {
						av->append(new StringValue('"' + subject + '"'));
					}
				}
				delete student->getSubjects();
				student->setSubjects(new Subjects(*av));
				delete av;
			}
			else if (command[0] == '9') {
				cout << "Deleting..." << endl;
				delete dynamicStudentsArray->remove(index);
				cout << "Exiting..." << endl;
				state = false;
			}
			else if (command[0] == '0') {
				cout << "Exitting..." << endl;
				state = false;
			}
		}
	}
	catch (const invalid_argument& ex) {
		cerr << "Conversion could not be performed" << endl;
		editStudent(student, dynamicStudentsArray, index);
	}
}

void startConsoleApp(DynamicArray<Student*>* dynamicStudentsArray) {
	print(dynamicStudentsArray);
	bool state = true;
	while (state) {
		string command;
		cout << endl;
		cout << "0 - save and exit" << endl;
		cout << "0..n-1 - choose user for editing or delete by index, where n is max size of list" << endl;
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
					string subject = enterValue("Enter subject: ");
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
		else if (isNumber(command)) {
			try {
				int index = stoi(command);
				Student* curStudent = dynamicStudentsArray->getElementAt(index);
				editStudent(curStudent, dynamicStudentsArray, index);
			}
			catch (const out_of_range& ex) {
				cerr << "User with id " << command << " doesn't exist." << endl;
				startConsoleApp(dynamicStudentsArray);
			}
			catch (const invalid_argument& ex) {
				cerr << "Conversion could not be performed" << endl;
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
	startConsoleApp(dynamicStudentsArray);

	//ArrayValue* av = new ArrayValue();
	//ObjectValue* ov = new ObjectValue();
	//av->append(new StringValue("123"));
	//Student* st = new Student(new NumberValue(5), new StringValue("Aaron"), new StringValue("Kirk"), new NumberValue(3)
	//	, new NumberValue(30), new Address(*ov), new Subjects(*av));
	//delete av;
	//delete ov;

	//delete st->getName();
	//st->setName(new StringValue("new name"));

	//cout << *st << endl;
	//delete st;


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
