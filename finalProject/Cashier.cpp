// Cashier Class Implementation
#include "Cashier.h"
#include <string>
#include <iomanip>

Cashier::Cashier()
{
}

void Cashier::addToCart()
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
				takeOut[i].itemCode = serial;
				takeOut[i].qty = bookQty;
			}

		}

		cout << "Would you like to finish adding to the cart? (Y/N)" << endl;
		cin >> finish;

		if (finish == 'Y' || finish == 'y')
			i = 51;
	}
}

void Cashier::viewCart()
{
	Date todaysDate;

	cout << takeOut[0].itemCode << endl;

	cout << getTitle(takeOut[0].itemCode);

	cout << "Date: " << todaysDate.getComputerDate() << endl;
	cout << setw(11) << left << "Item Code" << setw(35) << left << "Title" << setw(15) << left << "ISBN" << setw(10) << left << "Price($)" << setw(8) << left << "Qty" << setw(8) << left << "Total($)" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;



	int i = 0;
	while (takeOut[i].itemCode != 0)
	{
		cout << setw(11) << left << takeOut[i].itemCode
			<< setw(35) << left << getTitle(takeOut[i].itemCode)
			<< setw(15) << left << getISBN(takeOut[i].itemCode)
			<< setw(10) << left << getMSRP(takeOut[i].itemCode)
			<< setw(8) << left << takeOut[i].qty
			<< setw(8) << left << takeOut[i].qty * getMSRP(takeOut[i].itemCode) << endl;
		i++;
	}
}

void Cashier::removeFromCart()
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