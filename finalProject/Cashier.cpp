// Cashier Class Implementation
#include "Cashier.h"
#include <string>
#include <iomanip>

Cashier::Cashier()
{
}

void Cashier::addToCart(Cart (&takeOut)[50])
{
	int serial, bookNum, bookQty;
	char finish;

	for (int i = 0; i < 50; i++)
	{
		cout << "\nWhat book would you like to add? (Item Code): " << endl;

		cin >> serial; 
		bookNum = serial - 1000000;

		if (findBook(serial) == -1)
			cout << "The item code " << serial << " cannot be found." << endl;
		else
		{
			cout << "We have " << getQty(bookNum) << " books of \"" << getTitle(bookNum) << "\"\n" << endl;
			cout << "How many books would you like to add to the cart?: " << endl;
			cin >> bookQty;

			if (bookQty < 0)
				cout << "Invalid Quantity" << endl;
			else if (bookQty > getQty(bookNum))
				cout << "Not enough books in inventory" << endl;
			else
			{
				cout << "Adding " << bookQty << " books of " << getTitle(bookNum) << endl;
				takeOut[i].setItemCode(serial);
				takeOut[i].setQty(bookQty);
			}

		}

		cout << "Would you like to finish adding to the cart? (Y/N)" << endl;
		cin >> finish;

		if (finish == 'Y' || finish == 'y')
			i = 51;
	}
}

void Cashier::viewCart(Cart(&takeOut)[50])
{
	Date todaysDate;

	cout << "Date: " << todaysDate.getComputerDate() << endl;
	cout << setw(11) << left << "Item Code" << setw(35) << left << "Title" << setw(15) << left << "ISBN" << setw(10) << left << "Price($)" << setw(8) << left << "Qty" << setw(8) << left << "Total($)" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	cout << getTitle(takeOut[0].getItemCode()) << endl;

	int i = 0;
	while (takeOut[i].getItemCode() != 0)
	{
		cout << setw(11) << left << takeOut[i].getItemCode()
			<< setw(35) << left << getTitle(takeOut[i].getItemCode())
			<< setw(15) << left << getISBN(takeOut[i].getItemCode())
			<< setw(10) << left << getMSRP(takeOut[i].getItemCode())
			<< setw(8) << left << takeOut[i].getQty()
			<< setw(8) << left << takeOut[i].getQty() * getMSRP(takeOut[i].getItemCode()) << endl;
		i++;
	}
}

void Cashier::removeFromCart(Cart(&takeOut)[50])
{
	int serial, bookNum, bookQty;
	char finish = 'N';


	do
	{


	} while (finish != 'Y');


}


int Cashier::findBook(int s)
{
	int first = 0,						// First array element
		last = getSizeLine() - 1,			// Last array element
		middle,							// Midpoint of search
		position = -1;					// Position of search value
	bool found = false;					// Flag

	while (!found && first <= last)
	{
		middle = (first + last) / 2;	// Calculate midpoint
		if (getSerial(middle) == s)		// If value is found at mid
		{
			found = true;
			position = middle;
		}
		else if (getSerial(middle) > s)	// If value is in lower half
			last = middle - 1;
		else
			first = middle + 1;			// If value is in upper half

	}

	return position;
}