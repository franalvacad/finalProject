#include <iostream>
#include "inventory.h"
#include <time.h>
using namespace std;

void inventTest()
{
	inventory changes;
	int ser;
	string term;
	char result;
	bool test = 0;

	while (!test)
	{
		cout << "(S)earch or (L)ist items? ";
		cin >> result;

		if (result == 's' || result == 'S')
		{
			cout << endl << "Enter your search term: ";
			cin.ignore();
			getline(cin, term);
			changes.search(term);
			test = true;
		}

		else if (result == 'l' || result == 'L')
		{
			changes.getList();
			test = true;
		}
			
		else cout << "Try again please!" << endl;

	}
	cout << endl;
	while (test)
	{
		cout << "(A)dd or (P)ick by Serial: ";

		if (result == 'a' || result == 'A')
		{
			changes.add();
			test = false;
		}

		cin >> ser;
	}
	while (test)
	{
		cout << "(M)odify/(D)elete: ";
		cin >> result;
		if (result == 'm' || result == 'M')
		{
			changes.modify(ser);
			test = false;
		}
		else if (result == 'd' || result == 'D')
		{
			changes.del(ser);
			test = false;
		}
		else cout << "Try again please!" << endl;

	}


}


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

	time_t c = time(NULL);
	char *h = ctime(&c);

	cout << endl;
	string searchTerm;

	inventTest();

	cout << h;

	system("pause>nul");
	return 0;
}