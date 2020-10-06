#pragma once
#ifndef CV2_UT_18_20_RECEIPT_H
#define CV2_UT_18_20_RECEIPT_H

class Receipt {
public:
	Receipt(int numberOfReceipt, double amount, double dph);

	int getNumberOfReceipt() const;

	void setNumberOfReceipt(int numberOfReceipt);

	double getAmount() const;

	void setAmount(double amount);

	double getDph() const;

	void setDph(double dph);

private:
	int numberOfReceipt;
	double amount;
	double dph;
};

#endif //CV2_UT_18_20_RECEIPT_H
