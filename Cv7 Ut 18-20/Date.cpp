#include "Date.h"

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

std::ostream &operator<<(std::ostream &os, const Date &date) {
	os << date.day << "." << date.month << "." << date.year;
	return os;
}

std::istream &operator>>(std::istream &is, Date &date) {
	char c;
	is >> date.day >> c >> date.month >> c >> date.year;
	return is;
}