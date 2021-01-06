#include <iostream>
#include <fstream>
#include <sstream>
#include "Measurement.h"

#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC
#include <vector>

using namespace std;

string* split(string& line) {
	auto* parsedCSVRow = new string[4];
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

void parseCSVFile() {
	vector<Measurement> measurements{};
	ifstream fr{ "data.csv" };
	if (fr.is_open()) {
		string line;
		getline(fr, line);
		while (getline(fr, line)) {
			string* csvRow = split(line);
			Measurement measurement{ stoi(csvRow[0]), stoi(csvRow[1]), csvRow[2], stod(csvRow[3]) };
			measurements.push_back(measurement);
			delete[] csvRow;
		}
	}
}

int main() {
	parseCSVFile();
	if (_CrtDumpMemoryLeaks() == 0) {
		cout << "\nMemory leaks have not been found." << endl;
	}
	else {
		cout << "\nMemory leaks have been found." << endl;
	}
	return 0;
}
