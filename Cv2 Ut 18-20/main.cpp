#include <iostream>
#include "checkout/Checkout.h"

using namespace std;

int main() {
	Checkout checkout{2};
	try {
		checkout.createReceipt(10, .10);
		checkout.createReceipt(20, .10);
		checkout.createReceipt(30, .10);
	}
	catch (const length_error &er) {
		cerr << er.what() << endl;
	}

	try {
		cout << checkout.getReceipt(0) << endl;
		cout << checkout.getReceipt(1) << endl;
		cout << checkout.getReceipt(2) << endl;
	}
	catch (const out_of_range& ex) {
		cerr << ex.what() << endl;
	}

	cout << "Sum: " << checkout.getAmountsSum() << endl;
	cout << "Sum with DPH: " << checkout.getAmountsSumWithDph() << endl;
	return 0;
}
