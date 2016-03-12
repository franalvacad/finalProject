#include <iostream>
#include "inventory.cpp"
using namespace std;

int main()
{
	inventory test;
	display test2;
	int size = test.getSizeLine(), srch;
	string results;

	//cout << "term: ";

	Date newDate;
	//cout << newDate.getComputerDate();

	results = test.getTitle(4);

	test2.getCostlist();


	system("pause>nul");
	return 0;
}
