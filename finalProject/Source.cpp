#include <iostream>
#include <string>
#include "baseClass.h"
#include "Cashier.h"
#include "Date.h"
#include "displayClass.h"

using namespace std;

int main()
{
	string h;
	baseClass mains;
	int size = mains.getSizeLine();
	
	for (int c = 0; c < size; c++)
	{
		cout << mains.getTitle(c) 
			<< " | Date Added: " 
			<< mains.getDate(c) 
			<< endl;
	}


	//cout << "\t\tWhat book would you like to purchase?" << endl;
	//cin >> 

	system("pause>nul");


	return 0;
}
