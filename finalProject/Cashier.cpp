// Cashier Class Implementation
#include "Cashier.h"
#include <string>
#include <iomanip>
#include "Cart.h"

/*
template <class T>
int findBook1(T bookArr, int s)
{
	int first = 0,						// First array element
		last = getSizeLine() - 1,			// Last array element
		middle,							// Midpoint of search
		position = -1;					// Position of search value
	bool found = false;					// Flag

	while (!found && first <= last)
	{
		middle = (first + last) / 2;	// Calculate midpoint
		if (bookArr[middle] == s)		// If value is found at mid
		{
			found = true;
			position = middle;
		}
		else if (bookArr[middle] > s)	// If value is in lower half
			last = middle - 1;
		else
			first = middle + 1;			// If value is in upper half

	}

	return position;
}
*/
Cashier::Cashier()
{
}
Cashier::~Cashier()
{
}

void Cashier::addToCart(Cart (&t)[50])
{
	int serial, bookNum, bookQty;
	char finish;

	for (int i = 0; i < 50; i++)
	{
		cout << "\nWhat book would you like to add? (Item Code): " << endl;

		cin >> serial; 

		if (findBook(serial) == -1)
			cout << "The item code " << serial << " cannot be found." << endl;
		else
		{
			cout << "We have " << getQty(serial) << " books of \"" << getTitle(serial) << "\"\n" << endl;
			cout << "How many books would you like to add to the cart?: " << endl;
			cin >> bookQty;

			if (bookQty < 0)
				cout << "Invalid Quantity" << endl;
			else if (bookQty > getQty(serial))
				cout << "Not enough books in inventory" << endl;
			else
			{
				cout << "Adding " << bookQty << " books of " << getTitle(serial) << endl;
				t[i].setItemCode(serial);
				t[i].setQty(bookQty);
			}

		}

		cout << "Would you like to finish adding to the cart? (Y/N)" << endl;
		cin >> finish;

		if (finish == 'Y' || finish == 'y')
			i = 51;
	}
}

void Cashier::viewCart(Cart(&t)[50])
{
	Date todaysDate;

	system("cls");

	cout << "Date: " << todaysDate.getComputerDate() << "\n" << endl;
	cout << setw(11) << left << "Item Code" << setw(35) << left << "Title" << setw(15) << left << "ISBN" << setw(10) << left << "Price($)" << setw(8) << left << "Qty" << setw(8) << left << "Total($)" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	int i = 0;
	while (t[i].getItemCode() != 0)
	{
		cout << setw(11) << left << t[i].getItemCode()
			<< setw(35) << left << getTitle(t[i].getItemCode())
			<< setw(15) << left << getISBN(t[i].getItemCode())
			<< setw(10) << left << getMSRP(t[i].getItemCode())
			<< setw(8) << left << t[i].getQty()
			<< setw(8) << left << t[i].getQty() * getMSRP(t[i].getItemCode()) << endl;
		i++;
	}
}

void Cashier::removeFromCart(Cart(&t)[50])
{
	int serial, bookNum, bookQty;
	char finish = 'N';

	system("cls");


	do
	{
		viewCart(t);
		
		cout << "What book do you wish to remove from the cart? (Item Code): " << endl;
		cin >> serial;
		/*
		if (findBook1(t, serial) == -1)
			cout << "Not found" << endl;
		else
			cout << "Found" << endl;

		system("pause");
		*/
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

