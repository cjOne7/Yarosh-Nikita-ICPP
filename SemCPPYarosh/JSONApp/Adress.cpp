#include "Adress.h"

const string& Address::getStreet() const {
	return street;
}

const string& Address::getCity() const {
	return city;
}

int Address::getPostCode() const {
	return postCode;
}

Address::Address(const string& street, const string& city, int postCode) : street(street), city(city), postCode(postCode) {
	if (street.empty() || city.empty() || postCode <= 0) {
		throw invalid_argument("Invalid address arguments");
	}
}

ostream& operator<<(ostream& os, const Address& address) {
	os << "city: " << address.city << " street: " << address.street << " postCode: " << address.postCode;
	return os;
}
