#include <iostream>
#include "valueDir/api.h"
#include "valueDir/JsonFormatException.h"
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
		Value *value = JSON::deserialize(
				"{\"users\":[{\"id\":1,\"name\":\"Nikita\",\"surname\":\"Yarosh\",\"year\":3,\"credits\":30,\"address\":{\"city\":\"Pardubice\",\"street\":\"Studentska 199\",\"post code\":53009},\"subjects' list\":[\"IMOSI\",\"IWWW\",\"ICPP\",\"IDAS2\"]},{\"id\":2,\"name\":\"Vlad\",\"surname\":\"Ermolaev\",\"year\":3,\"credits\":30,\"address\":{\"city\":\"Kolin\",\"street\":\"Studentska 199\",\"post code\":53009},\"subjects' list\":[\"IMOSI\",\"IWWW\",\"ICPP\",\"IDAS2\"]},{\"id\":3,\"name\":\"Andrii\",\"surname\":\"Andrusenko\",\"year\":3,\"credits\":30,\"address\":{\"city\":\"Prelouc\",\"street\":\"Studentska 199\",\"post code\":53009},\"subjects' list\":[\"IMOSI\",\"IWWW\",\"ICPP\",\"IDAS2\"]},{\"id\":4,\"name\":\"Dmytro\",\"surname\":\"Hrychanok\",\"year\":3,\"credits\":30,\"address\":{\"city\":\"Pardubice\",\"street\":\"Studentska 199\",\"post code\":53009},\"subjects' list\":[\"IMOSI\",\"IWWW\",\"ICPP\",\"IDAS2\"]}]}");
//test all
//		Value *value = JSON::deserialize(
//				"{\"v_true\":true,\"v_false\":false,\"v_null\":null,\"v_int\":123,\"v_double\":1.23,\"v_string\":\"Hello, World\",\"v_array\":[1,2.3,true,false,null,{},[]]}");
//		cout << JSON::serialize(value);
		ofstream fileWriter{};
		fileWriter.open("students.json");
		if (fileWriter.is_open()) {
			fileWriter << JSON::serialize(value);
			fileWriter.close();
		}

		ifstream fileReader{};
		fileReader.open("students.json");
		string strValue = "";
		if (fileReader.is_open()) {
			while (getline(fileReader, strValue)) {
				for (int i = 0; i < strValue.size(); ++i) {
					if (strValue[i] == '\\' && strValue[i + 1] == '\"') {
						strValue = strValue.replace(i, 2, "\"");
					} else if (strValue[i] == '\\' && strValue[i + 1] == '\\') {
						strValue = strValue.replace(i, 2, "\\");
					}
				}
				value = JSON::deserialize(strValue);
			}
		}
		fileReader.close();
		cout << JSON::serialize(value) << endl;

		fileWriter.open("students.json");
		if (fileWriter.is_open()) {
			fileWriter << JSON::serialize(value);
			fileWriter.close();
		}

		fileReader.open("students.json");
		strValue = "";
		if (fileReader.is_open()) {
			while (getline(fileReader, strValue)) {
				for (int i = 0; i < strValue.size(); ++i) {
					if (strValue[i] == '\\' && strValue[i + 1] == '\"') {
						strValue = strValue.replace(i, 2, "\"");
					} else if (strValue[i] == '\\' && strValue[i + 1] == '\\') {
						strValue = strValue.replace(i, 2, "\\");
					}
				}
				value = JSON::deserialize(strValue);
			}
		}
		fileReader.close();
		cout << JSON::serialize(value) << endl;

		delete value;
	} catch (const JsonFormatException &ex) {
		cerr << ex.what() << endl;
	}

	return 0;
}
