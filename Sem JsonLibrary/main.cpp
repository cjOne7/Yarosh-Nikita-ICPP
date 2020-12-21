#include <iostream>
#include "valueDir/api.h"


int main() {

	ObjectValue *ov = new ObjectValue{};
	ov->append(KeyValuePair{"bool", new BoolValue{true}});
	ov->append(KeyValuePair{"null", new NullValue{}});
	ov->append(KeyValuePair{"string", new StringValue{"hello world \\ \" experiment"}});
	ov->append(KeyValuePair{"number", new NumberValue{3.141592}});

	return 0;
}
