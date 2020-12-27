#include <iostream>
#include "valueDir/api.h"
#include "valueDir/JsonFormatException.h"

int main() {
	try {
//just test
//		Value *value = JSON::deserialize("{\"arr\": [12, [1, true], [21],7]}");
		Value *value = JSON::deserialize("{\"alpha\":{\"beta\":100,\"gamma\":200},\"delta\":[0,1,2,3,4,null,{\"a\":\"b\",\"c\":{},\"d\":[],\"e\":true,\"f\":false,\"g\":[{},{},{},[],[]]}]}");
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
//				"{\"users\":[{\"id\":1,\"name\":\"Nikita\"},{\"id\":2,\"name\":\"Aaron\"},{\"id\":3,\"name\":\"Miliella\"},{\"id\":4,\"name\":\"Doragon\"}]}");
//test all
//		Value *value = JSON::deserialize(
//				"{\"v_true\":true,\"v_false\":false,\"v_null\":null,\"v_int\":123,\"v_double\":1.23,\"v_string\":\"Hello, World\",\"v_array\":[1,2.3,true,false,null,{},[]]}");
		cout << JSON::serialize(value);
		delete value;
	} catch (const JsonFormatException &ex) {
		cerr << ex.what() << endl;
	}

	return 0;
}
