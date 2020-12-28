#include <iostream>
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC
#include "api.h"
#include "JsonFormatException.h"

int main() {
	//ObjectValue* ov = new ObjectValue{};
	//ov->append(KeyValuePair{ "bool", new BoolValue{true} });
	//ov->append(KeyValuePair{ "null", new NullValue{} });
	//ov->append(KeyValuePair{ "string", new StringValue{"hello world \\ \" experiment"} });
	//ov->append(KeyValuePair{ "number", new NumberValue{3.141592} });
	//ArrayValue* av = new ArrayValue{};
	//av->append(new NumberValue{ 0 });
	//av->append(new NumberValue{ 1 });
	//av->append(new StringValue{ "two" });
	//av->append(new NumberValue{ 3 });
	//ObjectValue* four = new ObjectValue{};
	//four->append(KeyValuePair{ "four", new NumberValue{4} });
	//av->append(four);
	//av->append(new NumberValue{ 5 });
	//ov->append(KeyValuePair{ "array", av });
	//cout << JSON::serialize(ov) << endl;

	//delete ov;

	try {
		Value* value = JSON::deserialize("{\"users\":[{\"id\":1,\"name\":\"Nikita\",\"surname\":\"Yarosh\",\"year\":3,\"credits\":30,\"address\":{\"city\":\"Pardubice\",\"street\":\"Studentska 199\",\"post code\":53009},\"subjects' list\":[\"IMOSI\",\"IWWW\",\"ICPP\",\"IDAS2\"]},{\"id\":2,\"name\":\"Vlad\",\"surname\":\"Ermolaev\",\"year\":3,\"credits\":30,\"address\":{\"city\":\"Kolin\",\"street\":\"Studentska 199\",\"post code\":53009},\"subjects' list\":[\"IMOSI\",\"IWWW\",\"ICPP\",\"IDAS2\"]},{\"id\":3,\"name\":\"Andrii\",\"surname\":\"Andrusenko\",\"year\":3,\"credits\":30,\"address\":{\"city\":\"Prelouc\",\"street\":\"Studentska 199\",\"post code\":53009},\"subjects' list\":[\"IMOSI\",\"IWWW\",\"ICPP\",\"IDAS2\"]},{\"id\":4,\"name\":\"Dmytro\",\"surname\":\"Hrychanok\",\"year\":3,\"credits\":30,\"address\":{\"city\":\"Pardubice\",\"street\":\"Studentska 199\",\"post code\":53009},\"subjects' list\":[\"IMOSI\",\"IWWW\",\"ICPP\",\"IDAS2\"]}]}");
		cout << JSON::serialize(value) << endl;
		delete value;
	}
	catch (const JsonFormatException& ex) {
		cerr << ex.what() << endl;
	}

	if (_CrtDumpMemoryLeaks() == 0) {
		cout << "\nMemory leaks have not been found." << endl;
	} else {
		cout << "\nMemory leaks have been found." << endl;
	}
	return 0;
}