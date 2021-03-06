#pragma once
#ifndef CV2_UT_18_20_RECEIPT_H
#define CV2_UT_18_20_RECEIPT_H

#include <ostream>

class Receipt {
public:
	Receipt();

	Receipt(int numberOfReceipt, double amount, double dph);

	double getAmount() const;

	double getDph() const;

	friend std::ostream &operator<<(std::ostream &os, const Receipt &receipt);

private:
	int numberOfReceipt = 0;
	double amount = 0.0;
	double dph = 0.0;
};

#endif //CV2_UT_18_20_RECEIPT_H
