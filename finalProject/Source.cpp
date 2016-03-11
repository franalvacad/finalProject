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

	results = test.getTitle(4);

	test2.getList();


	system("pause>nul");
	return 0;
}
