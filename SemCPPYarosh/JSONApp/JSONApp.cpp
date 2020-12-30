#include <iostream>
#include <fstream>
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC
#include <../JSONLibrary/api.h>
#include <../JSONLibrary/JsonFormatException.h>
#include "../JSONApp/Student.h"

void replaceEscape() {

}

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

	//cout << ss->str() << endl;

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

	string* strValue = readJson();
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
	print(dynamicStudentsArray);


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

			string name;
			cout << "Enter name: ";
			getline(cin >> ws, name);

			string surname;
			cout << "Enter surname: ";
			getline(cin >> ws, surname);

			int year;
			cout << "Enter year: ";
			cin >> year;

			int credits;
			cout << "Enter credits: ";
			cin >> credits;

			string city;
			cout << "Enter city: ";
			getline(cin >> ws, city);

			string street;
			cout << "Enter street: ";
			getline(cin >> ws, street);

			int postCode;
			cout << "Enter post code: ";
			cin >> postCode;

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
					StringValue* sv = new StringValue('"' + subject + '"');
					av->append(sv);
				}
			}
			Student* newStudent = new Student(new NumberValue(id), new StringValue('"' + name + '"'), new StringValue('"' + surname + '"')
				, new NumberValue(year), new NumberValue(credits), new Address(*ov), new Subjects(*av));
			delete ov;
			delete av;
			dynamicStudentsArray->append(newStudent);
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
				main();
			}
		}
		else {
			cout << "Unknown command." << endl;
		}
	}

	//stringstream* ss = new stringstream();
	//*ss << "{\"users\":[";
	//for (int i = 0; i < dynamicStudentsArray->getSize(); ++i) {
	//	//			cout << *dynamicStudentsArray->getElementAt(i) << endl;
	//	*ss << *dynamicStudentsArray->getElementAt(i);
	//	if (i != dynamicStudentsArray->getSize() - 1) {
	//		*ss << ',';
	//	}
	//}
	//*ss << "]}";

	//ofstream fileWriter{ "students.json" };
	//fileWriter.open("students.json");
	//if (fileWriter.is_open()) {
	//	Value* v = JSON::deserialize(ss->str());
	//	fileWriter << JSON::serialize(v) << endl;
	//	fileWriter.flush();
	//	fileWriter.close();
	//	delete v;
	//}
	//delete ss;


	//ArrayValue* av = new ArrayValue();
	//av->append(new StringValue("123"));
	//Student* st = new Student(new NumberValue(5), new StringValue("Aaron"), new StringValue("Kirk"), new NumberValue(3)
	//	, new NumberValue(30), new Address(), new Subjects(*av));
	//delete av;
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
