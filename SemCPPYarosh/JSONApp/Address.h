#pragma once

#include <string>
#include <stdexcept>
#include <ostream>
#include <../JSONLibrary/api.h>

using namespace std;

class Address {
private:
	StringValue* city;
	StringValue* street;
	NumberValue* postCode;
public:
	Address() = default;

	Address(ObjectValue* address);

	virtual ~Address();

	StringValue* getCity() const;

	StringValue* getStreet() const;

	NumberValue* getPostCode() const;

	void setCity(StringValue* city);

	void setStreet(StringValue* street);

	void setPostCode(NumberValue* postCode);

	friend ostream& operator<<(ostream& os, const Address& address);
};
