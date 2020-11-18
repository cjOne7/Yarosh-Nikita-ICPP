#ifndef CV7_UT_18_20_ADDRESS_H
#define CV7_UT_18_20_ADDRESS_H

#include <string>
#include <iostream>

using namespace std;

class Address {
private:
	string street;
	string city;
	int postCode;
public:
	Address() = default;

	Address(const string &street, const string &city, int postCode);

	friend ostream &operator<<(ostream &os, const Address &address);

	friend istream &operator>>(istream &is, Address &address);
};


#endif //CV7_UT_18_20_ADDRESS_H
