#include <iostream>
#include "Receipt.h"

using namespace std;

Receipt::Receipt(int numberOfReceipt, double amount, double dph) : numberOfReceipt(numberOfReceipt), amount(amount), dph(dph) {
	cout << "Receipt(int numberOfReceipt, double amount, double dph)" << endl;
}

Receipt::~Receipt() {
	cout << "~Receipt()" << endl;
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
