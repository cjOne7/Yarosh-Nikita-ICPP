#ifndef RWFILE_MEASUREMENT_H
#define RWFILE_MEASUREMENT_H

#include <string>

class Measurement {
private:
	int id;
	int sensorId;
	std::string date;
	double m3;
public:
	Measurement();

	Measurement(int id, int sensorId, const std::string &time, double m3);

	~Measurement();

	int getId() const;

	int getSensorId() const;

	const std::string &getTime() const;

	double getM3() const;
};


#endif //RWFILE_MEASUREMENT_H
