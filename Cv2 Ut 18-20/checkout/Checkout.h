#pragma once
#ifndef CV2_UT_18_20_CHECKOUT_H
#define CV2_UT_18_20_CHECKOUT_H

#include "../receipt/Receipt.h"

class Checkout {
public:
	static int idCounter;

	Checkout(int maxNumberOfGivenReceipts);

	Receipt &createReceipt(double cost, double id);

	Receipt &getReceipt(int receiptId);

	double getAmount() const;

	double getAmountWithDph() const;

	int getMaxNumberOfGivenReceipts() const;

	void setMaxNumberOfGivenReceipts(int maxNumberOfGivenReceipts);

	int getCurNumberOfGivenReceipts() const;

	void setCurNumberOfGivenReceipts(int curNumberOfGivenReceipts);

private:
	int maxNumberOfGivenReceipts;
	int curNumberOfGivenReceipts;
};

#endif //CV2_UT_18_20_CHECKOUT_H
