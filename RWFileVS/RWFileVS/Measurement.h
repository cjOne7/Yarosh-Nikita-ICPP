#pragma once

#include <string>
#include <iostream>

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

	friend std::ostream& operator<<(std::ostream& os, const Measurement& measurement);

	friend std::istream& operator>>(std::istream& is, Measurement& measurement);
};
