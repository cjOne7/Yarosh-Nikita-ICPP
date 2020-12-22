#include "api.h"

string NullValue::serialize() const {
	stringstream ss;
	ss << "null";
	return ss.str();
}
