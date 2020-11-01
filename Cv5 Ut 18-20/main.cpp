#include <iostream>
#include "MyLinkedList.h"
#include "Person.h"

using namespace std;
using namespace Entity;

int main() {
	Person person1{1, "Nikita", "+420773089030"};
	Person person2{2, "Aaron", "+420773089030"};
	Person person3{3, "Ark", "+420773089030"};
	auto *list = new MyLinkedList<Person>();
	list->addAsLast(person1);
	list->addAsLast(person2);
	list->addAsLast(person3);
	cout << list->getFirst().name << endl;
	delete list;
	return 0;
}
