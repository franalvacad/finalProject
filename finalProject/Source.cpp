#include <iostream>
#include "inventory.cpp"
#include <time.h>
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

	test2.getRetaillist();

	time_t c = time(NULL);
	char *h = ctime(&c);

	cout << h;

	system("pause>nul");
	return 0;
}
