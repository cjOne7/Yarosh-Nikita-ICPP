#pragma once
#ifndef CV2_UT_18_20_CHECKOUT_H
#define CV2_UT_18_20_CHECKOUT_H
#define INIT_DEFAULT_MAX_SIZE_OF_RECEIPTS 10

#include "../receipt/Receipt.h"
#include<vector>

using namespace std;

class Checkout {
public:

	Checkout();

	Checkout(int maxNumberOfGivenReceipts);

	virtual ~Checkout();

	Receipt &createReceipt(double cost, double dph);

	Receipt &getReceipt(int receiptId);

	double getAmountsSum() const;

	double getAmountsSumWithDph() const;

	int getMaxNumberOfGivenReceipts() const;

	void setMaxNumberOfGivenReceipts(int maxNumberOfGivenReceipts);

	int getCurNumberOfGivenReceipts() const;

	Receipt *getReceipts() const;

private:
	static int idCounter;
	int maxNumberOfGivenReceipts = INIT_DEFAULT_MAX_SIZE_OF_RECEIPTS;
	int curNumberOfGivenReceipts = 0;
	Receipt *receipts;
	vector<Receipt> vectorReceipts;

};

#endif //CV2_UT_18_20_CHECKOUT_H
