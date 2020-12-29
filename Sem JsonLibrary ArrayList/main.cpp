#include <iostream>
#include "valueDir/api.h"
#include "valueDir/JsonFormatException.h"
#include "Student.h"
#include <fstream>

int main() {
	try {
//		Value *value = JSON::deserialize(
//				"{\"str\": \"Hello, !@#$%^&*()_/*-+=1234567890:;|,.<> \' \\ \" World?!\", \"str\": \"Hello, \'\\\"World?!\"}");
//just test
//		Value *value = JSON::deserialize(
//				"{\"id\":1,\"name\":\"Nikita\",\"surname\":\"Yarosh\",\"year\":3,\"credits\":30,\"address\":{\"city\":\"Pardubice\",\"street\":\"Studentska 199\",\"post code\":53009},\"subjects' list\":[]}");
//		Value *value = JSON::deserialize(
//				"{ \"alpha\":{      \"beta\" : 100 , \"gamma\":200},\"delta\" : [ 0 , 1 , 2 ,3      ,4  ,null      , { \"a\"          :\"b\",\"c\":    { }        ,\"d\": [  ] ,\"e\":true,\"f\":false,\"g\":[{ },{ }, {}, [],[ ]]  } ] }");
//test objects sequence
//		Value *value = JSON::deserialize(
//				"{\"boolean\":true,\"obj1\":{\"obj_value1\":10,\"inner_obj1\":{},\"arr\":[1]}}");
//test objects sequences and inner objects
//		Value *value = JSON::deserialize(
//				"{\"obj1\":{\"obj_value1\":1 ,\"inner_obj1\":{\"inner_obj_value1\":100},\"inner_obj2\":{\"inner_obj_value2\":200}},\"obj2\":{\"obj_value2\":20}}");
//test arrays sequence
//		Value *value = JSON::deserialize(
//				"{\"boolean\":true,\"arr1\":[1,true],\"arr2\":[2,false]}");
//test inner objects in objects and arrays in arrays
//		Value *value = JSON::deserialize(
//				"{\"boolean\":true,\"arr\":[1,true,[null, 1.2],[]],\"obj\":{\"obj_value\":123,\"inner_obj\":{\"inner_obj_value\":\"inner string\"}}}");
//test primitives
//		Value *value = JSON::deserialize(
//				"{\"boolean\":true, \"boolean1\":false, \"num asdd\":123.2,\"null_value\":null, \"str\":\" some, string\"}");
//array of objects
//		Value *value = JSON::deserialize(
//				"{\"users\":[{\"id\":1,\"name\":\"Nikita\",\"surname\":\"Yarosh\",\"year\":3,\"credits\":30,\"address\":{\"city\":\"Pardubice\",\"street\":\"Studentska 199\",\"post code\":53009},\"subjects' list\":[\"IMOSI\",\"IWWW\",\"ICPP\",\"IDAS2\"]},{\"id\":2,\"name\":\"Vlad\",\"surname\":\"Ermolaev\",\"year\":3,\"credits\":30,\"address\":{\"city\":\"Kolin\",\"street\":\"Studentska 199\",\"post code\":53009},\"subjects' list\":[\"IMOSI\",\"IWWW\",\"ICPP\",\"IDAS2\"]},{\"id\":3,\"name\":\"Andrii\",\"surname\":\"Andrusenko\",\"year\":3,\"credits\":30,\"address\":{\"city\":\"Prelouc\",\"street\":\"Studentska 199\",\"post code\":53009},\"subjects' list\":[\"IMOSI\",\"IWWW\",\"ICPP\",\"IDAS2\"]},{\"id\":4,\"name\":\"Dmytro\",\"surname\":\"Hrychanok\",\"year\":3,\"credits\":30,\"address\":{\"city\":\"Pardubice\",\"street\":\"Studentska 199\",\"post code\":53009},\"subjects' list\":[\"IMOSI\",\"IWWW\",\"ICPP\",\"IDAS2\"]}]}");
//test all
//		Value *value = JSON::deserialize(
//				"{\"v_true\":true,\"v_false\":false,\"v_null\":null,\"v_int\":123,\"v_double\":1.23,\"v_string\":\"Hello, World\",\"v_array\":[1,2.3,true,false,null,{},[]]}");
//		cout << JSON::serialize(value);
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
//		cout << "Select user:" << endl;
		stringstream ss;
		cout << endl;
		ss << "{\"users\":[";
		for (int i = 0; i < dynamicStudentsArray->getSize(); ++i) {
//			cout << *dynamicStudentsArray->getElementAt(i) << endl;
			ss << *dynamicStudentsArray->getElementAt(i);
			if (i != dynamicStudentsArray->getSize() - 1) {
				ss << ',';
			}
		}
		ss << "]}";
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

		delete value;
		for (int i = 0; i < dynamicStudentsArray->getSize(); ++i) {
			delete dynamicStudentsArray->getElementAt(i);
		}
		delete dynamicStudentsArray;


		ofstream fileWriter{};
		fileWriter.open("students.json");
		if (fileWriter.is_open()) {
			fileWriter << JSON::serialize(JSON::deserialize(ss.str())) << endl;
			fileWriter.close();
		}

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

//		delete value;
	} catch (const JsonFormatException &ex) {
		cerr << ex.what() << endl;
	}

	return 0;
}
