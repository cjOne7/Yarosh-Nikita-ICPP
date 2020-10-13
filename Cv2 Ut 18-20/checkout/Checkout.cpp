#include "Checkout.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Checkout::Checkout() {
	this->receipts = new Receipt[10];
}

Checkout::Checkout(int maxNumberOfGivenReceipts) : maxNumberOfGivenReceipts(maxNumberOfGivenReceipts) {
	this->receipts = (Receipt *) malloc(sizeof(Receipt) * maxNumberOfGivenReceipts);
}

Checkout::~Checkout() {
	delete[] receipts;
}

Receipt &Checkout::createReceipt(double cost, double dph) {
	if (curNumberOfGivenReceipts == maxNumberOfGivenReceipts) {
		ostringstream stringStream;
		stringStream << "You can't add any more receipts to cash register."
						"\nCurrent index is " << curNumberOfGivenReceipts
					 << "\nMax enabled items are " << maxNumberOfGivenReceipts << endl;
		string mess = stringStream.str();
		throw length_error(mess);
	}
	Receipt receipt{curNumberOfGivenReceipts, cost, dph};
	this->receipts[curNumberOfGivenReceipts] = receipt;
	this->curNumberOfGivenReceipts++;
	return receipt;
}

Receipt &Checkout::getReceipt(int receiptId) {
	if (receiptId < 0 || receiptId >= this->curNumberOfGivenReceipts) {
		throw out_of_range("Nonexistent element with index: " + to_string(receiptId));
	}
	return this->receipts[receiptId];
}

double Checkout::getAmountsSum() const {
	double sum = 0;
	for (int i = 0; i < this->curNumberOfGivenReceipts; ++i) {
		sum += this->receipts[i].getAmount();
	}
	return sum;
}

double Checkout::getAmountsSumWithDph() const {
	double sum = 0;
	for (int i = 0; i < this->curNumberOfGivenReceipts; ++i) {
		sum += this->receipts[i].getAmount() * (1 + this->receipts[i].getDph());
	}
	return sum;
}
