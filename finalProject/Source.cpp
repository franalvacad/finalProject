#include <iostream>
#include <string>
#include "baseClass.h"
#include "Cashier.h"
#include "Date.h"

using namespace std;

int main()
{
	baseClass mains;
	int size = mains.getSizeLine();

	Date newDate(4,21,1996);

	// Output date
	//cout << newDate.getDate();
	
	
	for (int c = 0; c < size; c++)
	{
		cout << mains.getDate(c) << endl;
	}

	

	//cout << "\t\tWhat book would you like to purchase?" << endl;
	//cin >> 

	system("pause>nul");


	return 0;
}
