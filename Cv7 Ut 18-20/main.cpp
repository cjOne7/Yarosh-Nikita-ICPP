#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include "Person.h"

using namespace std;

vector<Person> loadBinary(const string &fileName) {
	if (fileName.empty()) {
		throw invalid_argument("Filename is empty!");
	}
	ifstream in(fileName, ios_base::binary);
	vector<Person> persons{};
//	in.seekg(0, ios::beg);
	Person person;
	if (in.is_open()) {
		for (int i = 0; i < 10; ++i) {
			in >> person;
			persons.push_back(person);
		}
		in.close();
	} else {
		cerr << "The file cannot be opened...";
	}
	return persons;
}

void writeBinary(const vector<Person> &persons, const string &filename) {
	if (persons.empty() || filename.empty()) {
		return;
	}
	ofstream out(filename, ios_base::binary);
	if (out.is_open()) {
		for (auto &person : persons) {
			out << person << "\n";
		}
		out.close();
	} else {
		cerr << "The file cannot be opened...";
	}
}

int main() {
	srand(time(NULL));
	const string filename = "test.bin";
	vector<Person> persons;
	for (size_t i = 0; i < 10; i++) {
		int year = rand() % 20 + 2000;
		int month = rand() % 12 + 1;
		int day = rand() % 30 + 1;
		Date date{day, month, year};
		Address address{"Studentska", "Pardubice", 53009};
		Person person{address, date, "Nikita", "Yarosh"};
		persons.push_back(person);
	}
	writeBinary(persons, filename);
	persons.clear();
	persons = loadBinary(filename);
	for (int i = 0; i < 10; ++i) {
		cout << persons.at(i) << endl;
	}
	return 0;

}
