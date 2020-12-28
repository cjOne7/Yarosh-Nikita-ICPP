#ifndef SEM_JSONLIBRARY_ARRAYLIST_ADDRESS_H
#define SEM_JSONLIBRARY_ARRAYLIST_ADDRESS_H

#include <string>
#include <stdexcept>

using namespace std;

class Address {
private:
	string city;
	string street;
	int postCode;
public:
	Address(const string &street, const string &city, int postCode);

	const string &getStreet() const;

	const string &getCity() const;

	int getPostCode() const;
};


#endif //SEM_JSONLIBRARY_ARRAYLIST_ADDRESS_H
