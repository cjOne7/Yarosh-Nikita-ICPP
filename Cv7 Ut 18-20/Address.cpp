#include "Address.h"


const string &Address::getStreet() const {
	return street;
}

const string &Address::getCity() const {
	return city;
}

int Address::getPostCode() const {
	return postCode;
}

Address::Address(string street, string city, int postCode)
		: street(std::move(street)), city(std::move(city)), postCode(postCode) {}

ostream &operator<<(ostream &os, const Address &address) {
	os << "street: " << address.street << " city: " << address.city << " postCode: " << address.postCode;
	return os;
}

istream &operator>>(istream &is, Address &address) {
	is >> address.street >> address.city >> address.postCode;
	return is;
}
