#include <iostream>
#include "valueDir/api.h"

int main() {
//	ObjectValue *ov = new ObjectValue{};
//	ov->append(KeyValuePair{"bool", new BoolValue{true}});
//	ov->append(KeyValuePair{"null", new NullValue{}});
//	ov->append(KeyValuePair{"string", new StringValue{"hello world \\ \" experiment"}});
//	ov->append(KeyValuePair{"number", new NumberValue{3.141592}});
//	ArrayValue *av = new ArrayValue{};
//	av->append(new NumberValue{0});
//	av->append(new NumberValue{1});
//	av->append(new StringValue{"two"});
//	av->append(new NumberValue{3});
//	ObjectValue *four = new ObjectValue{};
//	four->append(KeyValuePair{"four", new NumberValue{4}});
//	av->append(four);
//	av->append(new NumberValue{5});
//	ov->append(KeyValuePair{"array", av});
//	cout << JSON::serialize(ov) << endl;
//
//	delete ov;

	Value *value = JSON::deserialize("{\"boolean\"  :  true,"
									 "\"num dsa_ds\"   :  123,"
									 " \"null_value\" : null, "
									 "\"str\" : \" some  ,string\","
									 "\"str_1\":\"some test string\"}");
	cout << JSON::serialize(value);
	delete value;

	return 0;
}
