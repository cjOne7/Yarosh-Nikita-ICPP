#ifndef CV7_UT_18_20_DATE_H
#define CV7_UT_18_20_DATE_H


#include <iostream>
using namespace std;

class Date {
private:
	int day;
	int month;
	int year;
public:
	Date() = default;

	Date(int day, int month, int year);

	friend ostream &operator<<(ostream &os, const Date &date);

	friend istream &operator>>(istream &is, Date &date);

};


#endif //CV7_UT_18_20_DATE_H
