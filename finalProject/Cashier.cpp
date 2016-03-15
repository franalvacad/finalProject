// Cashier Class Implementation
#include "Cashier.h"
#include <string>

Cashier::Cashier()
{
	
}

void Cashier::addToCart()
{
	int serial;
	cout << "\nWhat book would you like to add? (Serial): " << endl;

	cin >> serial; 

	if (findBook(serial) == -1)
	{
		cout << "The serial " << serial << " cannot be found." << endl;
	}


}

int Cashier::findBook(int s)
{
	int first = 0,						// First array element
		last = numElems - 1,			// Last array element
		middle,							// Midpoint of search
		position = -1;					// Position of search value
	bool found = false;					// Flag

	while (!found && first <= last)
	{
		middle = (first + last) / 2;	// Calculate midpoint
		if (array[middle] == value)		// If value is found at mid
		{
			found = true;
			position = middle;
		}
		else if (array[middle] > value)	// If value is in lower half
			last = middle - 1;
		else
			first = middle + 1;			// If value is in upper half

	}

	return position;
}