#include "Address.h"

ostream &operator<<(ostream &os, const Address &address) {
	os << address.street << " " << address.city << " " << address.postCode;
	return os;
}

istream &operator>>(istream &is, Address &address) {
	is >> address.street >> address.city >> address.postCode;
	return is;
}

Address::Address(const string &street, const string &city, int postCode) : street(street), city(city),
																		   postCode(postCode) {}