#include "Date.h"
#include <string>

using namespace std;

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {
	if (day <= 0 || month <= 0 || month > 12 || year <= 0 || year > 9999) {
		throw out_of_range("Wrong date parameters");
	}
	int dayCheckValue;
	switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: dayCheckValue = 31;
			break;
		case 2: dayCheckValue = year % 4 == 0 ? 29 : 28;
			break;
		default: dayCheckValue = 30;
	}
	if (day > dayCheckValue) {
		throw out_of_range("Wrong date parameters");
	}
}

std::ostream &operator<<(std::ostream &os, const Date &date) {
	os << (date.day < 10 ? "0" + to_string(date.day) : to_string(date.day)) << "-"
	   << (date.month < 10 ? "0" + to_string(date.month) : to_string(date.month)) << "-"
	   << date.year;
	return os;
}

std::istream &operator>>(std::istream &is, Date &date) {
	char c;
	is >> date.day >> c >> date.month >> c >> date.year;
	return is;
}