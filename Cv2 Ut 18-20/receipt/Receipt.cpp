#include <iostream>
#include "Receipt.h"

using namespace std;

Receipt::Receipt(int numberOfReceipt, double amount, double dph)
		: numberOfReceipt(numberOfReceipt), amount(amount), dph(dph) {
	cout << "Receipt(int numberOfReceipt, double amount, double dph)" << endl;
}

Receipt::~Receipt() {
	cout << "~Receipt()" << endl;
}

int Receipt::getNumberOfReceipt() const {
	return numberOfReceipt;
}

void Receipt::setNumberOfReceipt(int numberOfReceipt) {
	Receipt::numberOfReceipt = numberOfReceipt;
}

double Receipt::getAmount() const {
	return amount;
}

void Receipt::setAmount(double amount) {
	Receipt::amount = amount;
}

double Receipt::getDph() const {
	return dph;
}

void Receipt::setDph(double dph) {
	Receipt::dph = dph;
}

ostream &operator<<(ostream &os, const Receipt &receipt) {
	os << "numberOfReceipt: " << receipt.numberOfReceipt << " amount: " << receipt.amount << " dph: " << receipt.dph;
	return os;
}
