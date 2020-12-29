#include <iostream>
#include "valueDir/api.h"
#include "valueDir/JsonFormatException.h"
#include "Student.h"
#include <fstream>

string buildOutputString(const DynamicArray<Student *> &dynamicStudentsArray) {
	stringstream *ss = new stringstream();
	*ss << "{\"users\":[";
	for (int i = 0; i < dynamicStudentsArray.getSize(); ++i) {
		//			cout << *dynamicStudentsArray->getElementAt(i) << endl;
		*ss << *dynamicStudentsArray.getElementAt(i);
		if (i != dynamicStudentsArray.getSize() - 1) {
			*ss << ',';
		}
	}
	*ss << "]}";
	return (*ss).str();
}

int main() {
	try {
//		ofstream fileWriter{};
//		fileWriter.open("students.json");
//		if (fileWriter.is_open()) {
//			fileWriter << JSON::serialize(value) << endl;
//			fileWriter.close();
//		}

		ifstream fileReader{};
		fileReader.open("students.json");
		string *strValue = new string("");
		if (fileReader.is_open()) {
			getline(fileReader, *strValue);
			for (int i = 0; i < strValue->size(); ++i) {
				if ((*strValue)[i] == '\\' && (*strValue)[i + 1] == '\"') {
					*strValue = strValue->replace(i, 2, "\"");
				} else if ((*strValue)[i] == '\\' && (*strValue)[i + 1] == '\\') {
					*strValue = strValue->replace(i, 2, "\\");
				}
			}
		}
		fileReader.close();

		Value *value = JSON::deserialize(*strValue);
//		cout << JSON::serialize(value) << endl;
		delete strValue;

		DynamicArray<Student *> *dynamicStudentsArray = new DynamicArray<Student *>();
		if (ObjectValue *objectValue = dynamic_cast<ObjectValue *>(value)) {
			if (ArrayValue *arrayValue = dynamic_cast<ArrayValue *>(objectValue->getDynamicObjectArray()->getElementAt(
					0).getValue())) {
				for (int i = 0; i < arrayValue->getDynamicArray()->getSize(); i++) {
					if (ObjectValue *objectArrayValue = dynamic_cast<ObjectValue *>(arrayValue->getDynamicArray()->getElementAt(
							i))) {
						DynamicArray<KeyValuePair> *students = objectArrayValue->getDynamicObjectArray();
						Student *student = new Student();
						if (NumberValue *id = dynamic_cast<NumberValue *>(students->getElementAt(0).getValue())) {
							student->setId(new NumberValue(*id));
						}
						if (StringValue *name = dynamic_cast<StringValue *>(students->getElementAt(1).getValue())) {
							student->setName(new StringValue(*name));
						}
						if (StringValue *surname = dynamic_cast<StringValue *>(students->getElementAt(2).getValue())) {
							student->setSurname(new StringValue(*surname));
						}
						if (NumberValue *year = dynamic_cast<NumberValue *>(students->getElementAt(3).getValue())) {
							student->setYear(new NumberValue(*year));
						}
						if (NumberValue *credits = dynamic_cast<NumberValue *>(students->getElementAt(4).getValue())) {
							student->setCredits(new NumberValue(*credits));
						}
						if (ObjectValue *addressObj = dynamic_cast<ObjectValue *>(students->getElementAt(
								5).getValue())) {
							student->setAddress(new Address(*addressObj));
						}
						if (ArrayValue *subjectsArr = dynamic_cast<ArrayValue *>(students->getElementAt(
								6).getValue())) {
							student->setSubjects(new Subjects(new ArrayValue(*subjectsArr)));
						}
						dynamicStudentsArray->append(student);
					}
				}
			}
		}
		delete value;
//		cout << "Select user:" << endl;
//		stringstream ss;
//		cout << endl;
//		ss << "{\"users\":[";
//		for (int i = 0; i < dynamicStudentsArray->getSize(); ++i) {
////			cout << *dynamicStudentsArray->getElementAt(i) << endl;
//			ss << *dynamicStudentsArray->getElementAt(i);
//			if (i != dynamicStudentsArray->getSize() - 1) {
//				ss << ',';
//			}
//		}
//		ss << "]}";
//		cout << ss.str() << endl;

//		int command = 0;
//		cout << "Enter command number:" << endl;
//		cin >> command;
//		bool state = true;
//		while (state) {
//			switch (command) {
//				case 0: cout << "Exiting..." << endl;
//					state = false;
//					break;
//			}
//		}


		ofstream fileWriter{};
		fileWriter.open("students.json");
		if (fileWriter.is_open()) {
			fileWriter << JSON::serialize(JSON::deserialize(buildOutputString(*dynamicStudentsArray))) << endl;
			fileWriter.close();
		}
//		writeJson(dynamicStudentsArray);

//		fileReader.open("students.json");
//		strValue = "";
//		if (fileReader.is_open()) {
//			while (getline(fileReader, strValue)) {
//				for (int i = 0; i < strValue.size(); ++i) {
//					if (strValue[i] == '\\' && strValue[i + 1] == '\"') {
//						strValue = strValue.replace(i, 2, "\"");
//					} else if (strValue[i] == '\\' && strValue[i + 1] == '\\') {
//						strValue = strValue.replace(i, 2, "\\");
//					}
//				}
//				value = JSON::deserialize(strValue);
//			}
//		}
//		fileReader.close();
//		cout << JSON::serialize(value) << endl;

		for (int i = 0; i < dynamicStudentsArray->getSize(); ++i) {
			delete dynamicStudentsArray->getElementAt(i);
		}
		delete dynamicStudentsArray;
	} catch (const JsonFormatException &ex) {
		cerr << ex.what() << endl;
	}

	return 0;
}
