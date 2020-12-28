#ifndef SEM_JSONLIBRARY_ARRAYLIST_ADDRESS_H
#define SEM_JSONLIBRARY_ARRAYLIST_ADDRESS_H

#include <string>
#include <stdexcept>
#include <ostream>
#include "./valueDir/api.h"

using namespace std;

class Address {
private:
	StringValue *city;
	StringValue *street;
	NumberValue *postCode;
public:
	Address() = default;

	Address(ObjectValue* address);

	virtual ~Address();

	StringValue *getCity() const;

	StringValue *getStreet() const;

	NumberValue *getPostCode() const;

	friend ostream &operator<<(ostream &os, const Address &address);
};


#endif //SEM_JSONLIBRARY_ARRAYLIST_ADDRESS_H
