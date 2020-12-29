#ifndef SEM_JSONLIBRARY_ARRAYLIST_ADDRESS_H
#define SEM_JSONLIBRARY_ARRAYLIST_ADDRESS_H

#include <string>
#include <stdexcept>
#include <ostream>
#include "./valueDir/api.h"

using namespace std;

class Address {
private:
	StringValue *city = new StringValue("");
	StringValue *street = new StringValue("");
	NumberValue *postCode = new NumberValue(0);
public:
	Address() = default;

	Address(const ObjectValue &address);

	Address(ObjectValue *address);

	virtual ~Address();

	StringValue *getCity() const;

	StringValue *getStreet() const;

	NumberValue *getPostCode() const;

	void setCity(StringValue *city);

	void setStreet(StringValue *street);

	void setPostCode(NumberValue *postCode);

	friend ostream &operator<<(ostream &os, const Address &address);
};


#endif //SEM_JSONLIBRARY_ARRAYLIST_ADDRESS_H
