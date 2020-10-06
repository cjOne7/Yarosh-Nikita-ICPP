#include "Checkout.h"

Checkout::Checkout(int maxNumberOfGivenReceipts) : maxNumberOfGivenReceipts(maxNumberOfGivenReceipts) {}

int Checkout::getMaxNumberOfGivenReceipts() const {
	return maxNumberOfGivenReceipts;
}

void Checkout::setMaxNumberOfGivenReceipts(int maxNumberOfGivenReceipts) {
	Checkout::maxNumberOfGivenReceipts = maxNumberOfGivenReceipts;
}

int Checkout::getCurNumberOfGivenReceipts() const {
	return curNumberOfGivenReceipts;
}

void Checkout::setCurNumberOfGivenReceipts(int curNumberOfGivenReceipts) {
	Checkout::curNumberOfGivenReceipts = curNumberOfGivenReceipts;
}

Receipt &Checkout::createReceipt(double cost, double id) {
	//TODO Add implementation
}

Receipt &Checkout::getReceipt(int receiptId) {
	//TODO Add implementation
}

double Checkout::getAmount() const {
	//TODO Add implementation
	return 0;
}

double Checkout::getAmountWithDph() const {
	//TODO Add implementation
	return 0;
}
