#include <iostream>
#include <vector>
#include <sstream>
#include <time.h>
#include "IComparable.h"

using namespace std;

struct Time : public IComparable {
public:
	~Time() override;

	Time(int hours, int minutes, int seconds);

	int compareTo(IComparable *obj) const override;

	string toString() const override;

private:
	int hours, minutes, seconds;
};

Time::~Time() = default;

Time::Time(int hours, int minutes, int seconds) {
	if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59 || seconds < 0 || seconds > 59) {
		throw out_of_range("Wrong time parameters");
	}

	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;
}

int Time::compareTo(IComparable *obj) const {
	if (obj == nullptr) {
		throw invalid_argument("NullPointerException");
	}
	auto timeObj = dynamic_cast<Time *>(obj);
	int timeLeft = this->hours * 3600 + this->minutes * 60 + this->seconds;
	int timeRight = timeObj->hours * 3600 + timeObj->minutes * 60 + timeObj->seconds;
	return timeLeft == timeRight ? 0 : timeLeft > timeRight ? 1 : -1;
}

string Time::toString() const {
	stringstream ss;
	ss << "Time: "
	   << (hours < 10 ? "0" + to_string(hours) : to_string(hours)) << ":"
	   << (minutes < 10 ? "0" + to_string(minutes) : to_string(minutes)) << ":"
	   << (seconds < 10 ? "0" + to_string(seconds) : to_string(seconds));
	return ss.str();
}

vector<IComparable *> sort(vector<IComparable *> vector) {
	for (int i = 0; i < vector.size() - 1; ++i) {
		for (int j = 0; j < vector.size() - i - 1; ++j) {
			if (vector.at(j)->compareTo(vector.at(j + 1)) == 1) {
				auto iComparable = vector.at(j);
				vector.at(j) = vector.at(j + 1);
				vector.at(j + 1) = iComparable;
			}
		}
	}
	return vector;
}

int main() {
	srand(time(nullptr));
	vector<IComparable *> timeVector;
	cout << "Unsorted list:" << endl;
	for (int i = 0; i < 10; ++i) {
		try {
			IComparable *iComparable = new Time(rand() % 24, rand() % 60, rand() % 60);
			cout << iComparable->toString() << endl;
			timeVector.push_back(iComparable);
		}
		catch (out_of_range &ex) {
			cout << ex.what() << endl;
			return 3;
		}
	}
	timeVector = sort(timeVector);
	cout << "\nSorted list:" << endl;
	for (auto &item : timeVector) {
		cout << item->toString() << endl;
	}
	return 0;
}
