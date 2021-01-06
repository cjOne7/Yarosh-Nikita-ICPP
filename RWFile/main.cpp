#include <iostream>
#include <fstream>
#include <sstream>
#include "Measurement.h"

#include <crtdbg.h>

#define _CRTDBG_MAP_ALLOC

#include <vector>

using namespace std;

string *split(string &line) {
	auto *parsedCSVRow = new string[4];
	int counter = 0;
	while (line.find(';') != string::npos) {
		int pos = line.find(';');
		string value = line.substr(0, pos);
		line = line.substr(pos + 1);
		parsedCSVRow[counter++] = value;
	}
	parsedCSVRow[counter] = line;
	return parsedCSVRow;
}

vector<Measurement> parseCSVFile(string fileName) {
	vector<Measurement> measurements{};
	ifstream fr{fileName};
	if (fr.is_open()) {
		string line;
		getline(fr, line);
		while (getline(fr, line)) {
			string *csvRow = split(line);
			Measurement measurement{stoi(csvRow[0]), stoi(csvRow[1]), csvRow[2], stod(csvRow[3])};
			measurements.push_back(measurement);
			delete[] csvRow;
		}
	}
	fr.close();
	return measurements;
}

int main() {
	vector<Measurement> measurements = parseCSVFile("data.csv");

	ofstream fw{"newData.csv", ios::out};
	fw << "id;sensor_id;time;m3\n";
	if (fw.is_open()) {
		for (int i = 0; i < measurements.size(); i++) {
//			fw.write((const char *) &measurements.at(i), sizeof(Measurement));
			fw << measurements.at(i) << "\n";
		}
	}
	fw.close();

	measurements = parseCSVFile("newData.csv");

//	ifstream fr{"newData.csv", ios::in};
//	if (fr.is_open()) {
//		string line;
//		getline(fr, line);
//		for (int i = 0; i < measurements.size(); i++) {
//			Measurement measurement{};
//			fr.read((char *) &measurement, sizeof(Measurement));
//			cout << measurement << endl;
////			fr >> measurements.at(i);
//		}
//	}
//	fr.close();

	for (int i = 0; i < measurements.size(); i++) {
		cout << measurements.at(i) << endl;
	}
	if (_CrtDumpMemoryLeaks() == 0) {
		cout << "\nMemory leaks have not been found." << endl;
	} else {
		cout << "\nMemory leaks have been found." << endl;
	}
	return 0;
}
