#include "Time.h"
#include <iostream>

using namespace std;

vector<IComparable *> sort(vector<IComparable *> vector) {
	for (int i = 0; i < vector.size() - 1; ++i) {
		for (int j = 0; j < vector.size() - i - 1; ++j) {
			int compare = vector.at(j)->compareTo(vector.at(j + 1));
			if (compare == 1) {
				auto iComparable = vector.at(j);
				vector.at(j) = vector.at(j + 1);
				vector.at(j + 1) = iComparable;
			}
		}
	}
	return vector;
}

int main() {
	srand(time(nullptr));
	vector<IComparable *> timeVector;
	cout << "Unsorted list:" << endl;
	for (int i = 0; i < 10; ++i) {
		try {
			IComparable *iComparable = new Time(rand() % 24, rand() % 60, rand() % 60);
			cout << iComparable->toString() << endl;
			timeVector.push_back(iComparable);
		}
		catch (out_of_range &ex) {
			cout << ex.what() << endl;
			return 3;
		}
	}
	timeVector = sort(timeVector);
	cout << "\nSorted list:" << endl;
	for (auto &item : timeVector) {
		cout << item->toString() << endl;
	}
	return 0;
}
