#ifndef CV6_UT_18_20_GROWINGCONTAINER_H
#define CV6_UT_18_20_GROWINGCONTAINER_H
#define START_SIZE 5

using namespace std;

template<typename T>
class GrowingContainer {
private:
	int growingCoefficient = 2;
	T *array;
	int capacity = START_SIZE;
	int size = 0;

	void boostArray();

	void checkSize(int index) const;

public:

	GrowingContainer();

	virtual ~GrowingContainer();

	bool isEmpty() const;

	bool isFull() const;

	void add(const T &object);

	T &operator[](int index);

	T operator[](int index) const;

	void add(int index, const T &object);

	void remove(int index);

	void dump() const;

};


#endif //CV6_UT_18_20_GROWINGCONTAINER_H
