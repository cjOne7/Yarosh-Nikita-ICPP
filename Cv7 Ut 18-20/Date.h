#ifndef CV7_UT_18_20_DATE_H
#define CV7_UT_18_20_DATE_H


#include <iostream>

class Date {
private:
	int day;
	int month;
	int year;
public:
	Date(int day, int month, int year);

	int getDay() const;

	int getMonth() const;

	int getYear() const;

	friend std::ostream &operator<<(std::ostream &os, const Date &date);

	friend std::istream &operator>>(std::istream &is, Date &date);

};


#endif //CV7_UT_18_20_DATE_H
