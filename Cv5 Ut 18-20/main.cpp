#include "PhoneList.h"
#include <iostream>

using namespace Entity;
using namespace Model;
using namespace std;

int main() {
	Person person1{1, "Nikita", "+420773123123"};
	Person person2{2, "Aaron", "+380931232323"};
	Person person3{3, "Ark", "+123456789123"};

	auto *phoneList = new PhoneList();
	phoneList->addPerson(person1);
	phoneList->addPerson(person2);
	phoneList->addPerson(person3);

	cout << phoneList->findPhoneNumber(3) << endl;

	delete phoneList;
	return 0;
}
