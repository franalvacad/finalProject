#include <iostream>
#include "inventory.cpp"
using namespace std;

int main()
{
	inventory test;
	int size = test.getSizeLine(), srch;
	string results;

	cout << "term: ";

	results = test.getTitle(4);

	system("pause>nul");
	return 0;
}
