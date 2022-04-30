#pragma once
#ifndef CV2_UT_18_20_CHECKOUT_H
#define CV2_UT_18_20_CHECKOUT_H
#define INIT_DEFAULT_MAX_SIZE_OF_RECEIPTS 10

#include "../receipt/Receipt.h"

using namespace std;

class Checkout {
public:
	Checkout();

	explicit Checkout(int maxNumberOfGivenReceipts);

	virtual ~Checkout();

	Receipt &createReceipt(double cost, double dph);

	Receipt &getReceipt(int receiptId);

	double getAmountsSum() const;

	double getAmountsSumWithDph() const;

private:
	int maxNumberOfGivenReceipts = INIT_DEFAULT_MAX_SIZE_OF_RECEIPTS;
	int curNumberOfGivenReceipts = 0;
	Receipt *receipts;
};

#endif //CV2_UT_18_20_CHECKOUT_H