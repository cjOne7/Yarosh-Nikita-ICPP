#include "Receipt.h"

Receipt::Receipt(int numberOfReceipt, double amount, double dph)
		: numberOfReceipt(numberOfReceipt), amount(amount), dph(dph) {}
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
