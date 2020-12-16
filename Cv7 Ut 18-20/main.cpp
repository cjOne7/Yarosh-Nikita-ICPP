#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include "Person.h"

using namespace std;

vector<Person> read(const string &fileName, ios_base::openmode mode = ios_base::in) {
	if (fileName.empty()) {
		throw invalid_argument("Filename is empty!");
	}
	ifstream in(fileName, mode);
	vector<Person> persons{};
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

void write(const vector<Person> &persons, const string &filename, ios_base::openmode mode = ios_base::out) {
	if (filename.empty()) {
		return;
	}
	ofstream out(filename, mode);
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
	try {
		vector<Person> persons;
		for (size_t i = 0; i < 10; i++) {
			int year = rand() % 20 + 2000;
			int month = rand() % 12 + 1;
			int highValue;
			switch (month) {
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12: highValue = 31;
					break;
				case 2: highValue = year % 4 == 0 ? 29 : 28;
					break;
				default: highValue = 30;
			}
			int day = rand() % highValue + 1;
			Date date{day, month, year};
			Address address{"Studentska", "Pardubice", 53009};
			Person person{address, date, "Nikita", "Yarosh"};
			persons.push_back(person);
		}
		write(persons, filename, ios_base::binary);
		persons.clear();
		persons = read(filename, ios_base::binary);
		for (int i = 0; i < 10; ++i) {
			cout << persons.at(i) << endl;
		}
	}
	catch (invalid_argument ex) {
		cerr << move(ex).what() << endl;
	}

	return 0;

}
