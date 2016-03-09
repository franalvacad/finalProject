#include <iostream>
#include <string>
#include "baseClass.cpp"
#include "Cashier.h"

using namespace std;

int main()
{
	baseClass mains;
	int size = mains.getSizeLine();
	
	for (int c = 0; c < size; c++)
	{
		cout << mains.getTitle(c) << endl;
	}

	cout << "\t\tWhat book would you like to purchase?" << endl;
	cin >> 




	return 0;
}
