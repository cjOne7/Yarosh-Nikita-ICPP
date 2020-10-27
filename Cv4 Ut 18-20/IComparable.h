#ifndef CV4_UT_18_20_ICOMPARABLE_H
#define CV4_UT_18_20_ICOMPARABLE_H


#include "IObject.h"

class IComparable : public IObject {
public:
	~IComparable() override {}

	virtual int compareTo(IComparable *obj) const = 0;
};


#endif //CV4_UT_18_20_ICOMPARABLE_H
