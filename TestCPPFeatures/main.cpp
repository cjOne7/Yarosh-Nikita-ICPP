#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

namespace A {
	void a() {
		cout << "a" << endl;
	}

	class Animal {
	public:
		static int a;
		int numberOfAnimals;

		Animal() {}

		Animal(int number) {
			numberOfAnimals = number;
		}

		virtual void voice() {
			cout << "Animal's voice" << endl;
		}
	};

	class Dog final : public Animal {
	public:
		Dog(int number) : Animal(number) {
		}

		class Head {

		};

		class Body {

		};

		class Tail {

		};

		void voice() override {
			cout << "Dog's voice" << endl;
		}

		Dog &fun() {
			Dog *dog = new Dog(5);
			return *dog;
		}

	};

	struct Cat : Animal {
		Cat(int number) : Animal(number) {}

		void voice() {
			cout << "Cat's voice" << endl;
		}
	} dymok{4};
}

using namespace A;

template<typename Typ>
void vypis(const Typ &vystup) {
	cout << vystup;
}

int main() {
	int a = 5;
	int *ui = &a;
	int *&refui = ui;
	cout << a << endl;
	Dog::Body b;

	Animal animal{5};
	animal.voice();

	Dog dog{5};
	dog.voice();

	Animal *dog1 = new Dog(5);
	dog1->voice();

	Animal *animal1 = new Animal{5};
	animal1->voice();
	vypis<int>(10);
	vypis(10.02);
	dymok.voice();

	Cat *cat1 = new Cat(5);

	cout << setw(3) << 77 << endl;
	cout << setfill('!') << 5 << endl;
	int c = 7;
	cout << setw(4) << setfill('@') << hex << c << endl;
	cout << setprecision(2) << 87.4521 << endl;
	cout << setbase(1) << 2 << endl;

	ofstream fileWriter{"test.bin", ios::binary};
	Animal animals[3];
	for (int i = 0; i < 3; ++i) {
		animals->numberOfAnimals = i;
	}
	if (fileWriter.is_open()) {
		for (int i = 0; i < 3; ++i) {
			fileWriter.write((char *) &animals[i], sizeof(Animal));
		}
	}

	ifstream fileReader{"test.bin", ios::binary};
	Animal animals2[3];
	if (fileReader.is_open()) {
		for (int i = 0; i < 3; ++i) {
			fileReader.read((char *) &animals2[i], sizeof(Animal));
		}
	}
	for (int i = 0; i < 3; ++i) {
//		cout << animals2[i].numberOfAnimals << endl;
	}
	return 0;
}
