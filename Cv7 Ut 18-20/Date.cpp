#include "Date.h"
#include <string>

using namespace std;

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

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