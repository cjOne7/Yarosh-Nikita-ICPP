#include "PhoneList.h"
#include <iostream>

using namespace Entity;
using namespace Model;
using namespace std;

int main() {
	try {
		Person person1{1, "Nikita", "+420773123123"};
		Person person2{2, "Aaron", "+380931232323"};
		Person person3{3, "Ark", "+123456789123"};

		auto phoneList = new PhoneList();
		phoneList->addPerson(person1);
		phoneList->addPerson(person2);
		phoneList->addPerson(person3);

		cout << phoneList->findPhoneNumber(3) << endl;
		cout << phoneList->findPhoneNumber("Nikita") << endl;
		delete phoneList;
	}
	catch (invalid_argument &ex) {
		cout << ex.what() << endl;
	}
	return 0;
}
