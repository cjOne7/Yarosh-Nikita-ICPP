#include <iostream>
#include "Receipt.h"

using namespace std;

Receipt::Receipt() {}

Receipt::Receipt(int numberOfReceipt, double amount, double dph)
		: numberOfReceipt(numberOfReceipt), amount(amount), dph(dph) {
}

double Receipt::getAmount() const {
	return amount;
}

double Receipt::getDph() const {
	return dph;
}

ostream &operator<<(ostream &os, const Receipt &receipt) {
	os << "numberOfReceipt: " << receipt.numberOfReceipt << " amount: " << receipt.amount << " dph: " << receipt.dph;
	return os;
}


