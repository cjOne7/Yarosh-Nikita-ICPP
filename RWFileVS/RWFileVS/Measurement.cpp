#include "Measurement.h"

int Measurement::getId() const {
	return id;
}

int Measurement::getSensorId() const {
	return sensorId;
}

const std::string& Measurement::getTime() const {
	return date;
}

double Measurement::getM3() const {
	return m3;
}

Measurement::Measurement(int id, int sensorId, const std::string& time, double m3)
	: id(id), sensorId(sensorId), date(time), m3(m3) {}

std::ostream& operator<<(std::ostream& os, const Measurement& measurement) {
	os << measurement.id
		<< ";" << measurement.sensorId
		<< ";" << measurement.date
		<< ";" << measurement.m3 << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Measurement& measurement) {
	char c;
	is >> measurement.id >> c >> measurement.sensorId >> c >> measurement.date >> c >> measurement.m3;
	return is;
}
