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

	////delete av;
	////delete four;
	//delete ov;

	try {
		Value* value = JSON::deserialize(
			"{\"boolean\":true,\"obj\":{}}");
		//		Value *value = JSON::deserialize(
		//				"{\"boolean\":true,\"obj\":{\"obj_num\":258,\"new_inner_obj\":{\"str\":\" some string\"}},\"null_value\":null} ");
		//		Value *value = JSON::deserialize(
		//				"{\"boolean\":true,\"boolean1\":false,\"num asdd\":123,\"null_value\":null,\"str\":\" some, string\"}");

		cout << JSON::serialize(value);
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