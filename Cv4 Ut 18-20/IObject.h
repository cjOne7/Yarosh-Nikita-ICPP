#ifndef CV4_UT_18_20_IOBJECT_H
#define CV4_UT_18_20_IOBJECT_H
#include <string>

using namespace std;

class IObject {
public:
	virtual ~IObject() = default;

	virtual string toString() const = 0;
};


#endif //CV4_UT_18_20_IOBJECT_H
