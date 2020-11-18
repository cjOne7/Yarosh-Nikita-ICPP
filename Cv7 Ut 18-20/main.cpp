#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include "Person.h"

using namespace std;

Person* loadBinary(const string &fileName) {
	if (fileName.empty()) {
		throw invalid_argument("Filename is empty!");
	}
	ifstream in(fileName, ios_base::binary);

	in.seekg(0, ios::beg);
	Person *persons1= new Person[10];
	if (in.is_open()) {
		for (int i = 0; i < 10; ++i) {
			in >> persons1[i];
			cout << persons1[i] << endl;
		}
		in.close();
	} else {
		cerr << "The file cannot be opened...";
	}
	return persons1;
}

void writeBinary(const vector<Person> &persons) {
	if (persons.empty()) {
		return;
	}
	ofstream out("test.bin", ios_base::binary);
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
	writeBinary(persons);
	Person *persons1 = loadBinary("test.bin");
	return 0;

}
