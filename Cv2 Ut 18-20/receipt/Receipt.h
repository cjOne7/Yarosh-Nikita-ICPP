#pragma once
#ifndef CV2_UT_18_20_RECEIPT_H
#define CV2_UT_18_20_RECEIPT_H

#include <ostream>

class Receipt {
public:
	Receipt(int numberOfReceipt, double amount, double dph);

	int getNumberOfReceipt() const;

	void setNumberOfReceipt(int numberOfReceipt);

	double getAmount() const;

	void setAmount(double amount);

	double getDph() const;

	void setDph(double dph);

	friend std::ostream &operator<<(std::ostream &os, const Receipt &receipt);

	virtual ~Receipt();

private:
	int numberOfReceipt = 0;
	double amount = 0.0;
	double dph = 0.0;
};

#endif //CV2_UT_18_20_RECEIPT_H
