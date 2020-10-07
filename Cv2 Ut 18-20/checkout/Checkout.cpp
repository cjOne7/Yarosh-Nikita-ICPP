#include "Checkout.h"
#include <iostream>
#include <string>
#include <sstream>
#include <exception>

using namespace std;

Checkout::Checkout() {
	cout << "Checkout()" << endl;
	this->receipts = (Receipt *) malloc(sizeof(Receipt) * this->maxNumberOfGivenReceipts);
}

Checkout::Checkout(int maxNumberOfGivenReceipts) : maxNumberOfGivenReceipts(maxNumberOfGivenReceipts) {
	cout << "Checkout(int maxNumberOfGivenReceipts)" << endl;
	this->receipts = (Receipt *) malloc(sizeof(Receipt) * maxNumberOfGivenReceipts);
}

Checkout::~Checkout() {
	cout << "~Checkout()" << endl;
	delete[] receipts;
}

Receipt &Checkout::createReceipt(double cost, double dph) {
//	Receipt receipt{this->curNumberOfGivenReceipts, cost, dph};
//	this->vectorReceipts.push_back(receipt);
//	this->curNumberOfGivenReceipts++;
//
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
//	return this->vectorReceipts.at(receiptId);
}

double Checkout::getAmountsSum() const {
	double sum = 0;
	for (int i = 0; i < this->curNumberOfGivenReceipts; ++i) {
		sum += this->receipts[i].getAmount();
	}
//	for (int i = 0; i < vectorReceipts.size(); ++i) {
//		sum += vectorReceipts.at(i).getAmount();
//	}
	return sum;
}

double Checkout::getAmountsSumWithDph() const {
	double sum = 0;
	for (int i = 0; i < this->curNumberOfGivenReceipts; ++i) {
		sum += this->receipts[i].getAmount() * (1 + this->receipts[i].getDph());
	}
//	for (int i = 0; i < vectorReceipts.size(); ++i) {
//		sum += vectorReceipts.at(i).getAmount() * (1 + vectorReceipts.at(i).getDph());
//	}
	return sum;
}

int Checkout::getMaxNumberOfGivenReceipts() const {
	return maxNumberOfGivenReceipts;
}

void Checkout::setMaxNumberOfGivenReceipts(int maxNumberOfGivenReceipts) {
	Checkout::maxNumberOfGivenReceipts = maxNumberOfGivenReceipts;
}

int Checkout::getCurNumberOfGivenReceipts() const {
	return curNumberOfGivenReceipts;
}

Receipt *Checkout::getReceipts() const {
	return receipts;
}
