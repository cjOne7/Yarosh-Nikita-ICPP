#include "Date.h"

int Date::getDay() const {
	return day;
}

int Date::getMonth() const {
	return month;
}

int Date::getYear() const {
	return year;
}

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

std::ostream &operator<<(std::ostream &os, const Date &date) {
	os << date.day << "-" << date.month << "-" << date.year;
	return os;
}

std::istream &operator>>(std::istream &is, Date &date) {
	is >> date.day >> date.month >> date.year;
	return is;
}



