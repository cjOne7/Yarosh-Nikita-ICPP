#pragma once
#include <string>
#include <stdexcept>
#include <ostream>

using namespace std;

class Address {
private:
	string city;
	string street;
	int postCode;
public:
	Address(const string& street, const string& city, int postCode);

	const string& getStreet() const;

	const string& getCity() const;

	int getPostCode() const;

	friend ostream& operator<<(ostream& os, const Address& address);
};


