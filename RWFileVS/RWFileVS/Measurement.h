#pragma once

#include <string>x

class Measurement {
private:
	int id;
	int sensorId;
	std::string date;
	double m3;
public:
	Measurement() = default;

	Measurement(int id, int sensorId, const std::string& time, double m3);

	~Measurement() = default;

	int getId() const;

	int getSensorId() const;

	const std::string& getTime() const;

	double getM3() const;
};
