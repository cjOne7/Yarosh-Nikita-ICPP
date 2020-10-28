#ifndef CV4_UT_18_20_TIME_H
#define CV4_UT_18_20_TIME_H

#include <sstream>
#include "IComparable.h"

class Time : public IComparable {
public:
	Time(int hours, int minutes, int seconds);

	int compareTo(IComparable *obj) const override;

	string toString() const override;

private:
	int hours, minutes, seconds;
};


#endif //CV4_UT_18_20_TIME_H
