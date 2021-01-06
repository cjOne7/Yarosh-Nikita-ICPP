#include "Measurement.h"

int Measurement::getId() const {
	return id;
}

int Measurement::getSensorId() const {
	return sensorId;
}

const std::string &Measurement::getTime() const {
	return date;
}

double Measurement::getM3() const {
	return m3;
}

Measurement::Measurement() {

}

Measurement::~Measurement() {

}

Measurement::Measurement(int id, int sensorId, const std::string &time, double m3)
		: id(id), sensorId(sensorId), date(time), m3(m3) {}
