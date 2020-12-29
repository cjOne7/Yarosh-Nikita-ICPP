#include "../JSONApp/Address.h"

Address::Address(ObjectValue* address) {
	if (address != nullptr) {
		DynamicArray<KeyValuePair>* dynamicArray = address->getDynamicObjectArray();
		if (StringValue* city = dynamic_cast<StringValue*>(dynamicArray->getElementAt(0).getValue())) {
			this->city = city;
		}
		if (StringValue* street = dynamic_cast<StringValue*>(dynamicArray->getElementAt(1).getValue())) {
			this->street = street;
		}
		if (NumberValue* postCode = dynamic_cast<NumberValue*>(dynamicArray->getElementAt(2).getValue())) {
			this->postCode = postCode;
		}
	}
}

Address::~Address() {
	/*delete city;
	delete street;
	delete postCode;*/
}

StringValue* Address::getCity() const {
	return city;
}

StringValue* Address::getStreet() const {
	return street;
}

NumberValue* Address::getPostCode() const {
	return postCode;
}

void Address::setCity(StringValue* city) {
	Address::city = city;
}

void Address::setStreet(StringValue* street) {
	Address::street = street;
}

void Address::setPostCode(NumberValue* postCode) {
	Address::postCode = postCode;
}

ostream& operator<<(ostream& os, const Address& address) {
	os << "{city: " << address.city->serialize()
		<< ", street: " << address.street->serialize()
		<< ", post code: " << address.postCode->serialize() << "}";
	return os;
}
