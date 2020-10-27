#include "Time.h"

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
	if (timeObj == nullptr) {
		return 100;
	} else {
		int timeLeft = this->hours * 3600 + this->minutes * 60 + this->seconds;
		int timeRight = timeObj->hours * 3600 + timeObj->minutes * 60 + timeObj->seconds;
		return timeLeft == timeRight ? 0 : timeLeft > timeRight ? 1 : -1;
	}
}

string Time::toString() const {
	stringstream ss;
	ss << "Time: "
	   << (hours < 10 ? "0" + to_string(hours) : to_string(hours)) << ":"
	   << (minutes < 10 ? "0" + to_string(minutes) : to_string(minutes)) << ":"
	   << (seconds < 10 ? "0" + to_string(seconds) : to_string(seconds));
	return ss.str();
}