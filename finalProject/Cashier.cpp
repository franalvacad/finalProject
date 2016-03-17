// Cashier Class Implementation
#include "Cashier.h"
#include <string>
#include <iomanip>
#include "Cart.h"

void Cashier::addToCart(Cart &t)
{
	int serial, bookNum, bookQty;
	char choice;
	bool exit = false;

	do
	{
		cout << "\nWhat book would you like to add? (Item Code): " << endl;

		cin >> serial;

		if (findBook(serial) == -1)
			cout << "The item code " << serial << " cannot be found." << endl;
		else if (t.itemExist(serial) && t.getQty(serial) == getQty(serial))
			cout << "All stock is in the cart" << endl;
		else
		{
			int remQty;		// Remaining quantity including inventory and any taken in cart

			// If the item is already in the cart then subtract it from avaible quantity
			if (t.itemExist(serial))
			{
				remQty = getQty(serial) - t.getQty(serial);
			}
			else
				remQty = getQty(serial);

			cout << "We have " << remQty << " books of \"" << getTitle(serial) << "\"\n" << endl;
			cout << "How many books would you like to add to the cart?: " << endl;
			cin >> bookQty;

			if (bookQty < 0)
				cout << "Invalid Quantity" << endl;
			else if (bookQty > remQty)
				cout << "Not enough books in inventory" << endl;
			else
			{
				// If item doesn't already exist in cart then add
				if (!t.itemExist(serial))
					t.addItem(serial, bookQty);
				// If it does exist then add to the existing quantity
				else
					t.addQty(serial, bookQty);
				cout << "Added " << bookQty << " titles of \"" << getTitle(serial) << "\"" << endl;

			}

		}

		cout << "Would you like to finish adding to the cart? (Y/N)" << endl;
		cin >> choice; 
		if (choice == 'Y' || choice == 'y')
			exit = true;

	} while (!exit);

	system("pause");
}

void Cashier::viewCart(Cart &t)
{
	Date todaysDate;

	system("cls");

	cout << "Date: " << todaysDate.getComputerDate() << "\n" << endl;
	cout << setw(11) << left << "Item Code" << setw(35) << left << "Title" << setw(15) << left << "ISBN" << setw(10) << left << "Price($)" << setw(8) << left << "Qty" << setw(8) << left << "Total($)" << endl;
	cout << "-------------------------------------------------------------------------------------------------------" << endl;

	int i = 0;

	int itemCount = t.countCart();
	cout << itemCount << endl;
	while (i < itemCount)
	{
		cout << setw(11) << left << t.getSerial(i)
			<< setw(35) << left << getTitle(t.getSerial(i))
			<< setw(15) << left << getISBN(t.getSerial(i))
			<< setw(10) << left << getMSRP(t.getSerial(i))
			<< setw(8) << left << t.getQty(t.getSerial(i))
			<< setw(8) << left << t.getQty(t.getSerial(i)) * getMSRP(t.getSerial(i)) << endl;
		i++;
	}
	system("pause");
}

void Cashier::removeFromCart(Cart &t)
{
	int serial, bookNum, bookQty;
	char finish = 'N';

	system("cls");


	viewCart(t);
		
	cout << "What book do you wish to remove from the cart? (Item Code): " << endl;
	cin >> serial;

	if (!t.itemExist(serial))
		cout << "Book not found in cart." << endl;
	else
	{
		// If theres only 1 book then remove the entry
		if (t.getQty(serial) == 1)
		{
			cout << "Removed \"" << getTitle(serial) << "\"" << endl;
			t.removeItem(serial);
		}
		else
		{
			cout << "How many titles of \"" << getTitle(serial) << "\" do you wish to remove?" << endl;
			cin >> bookQty;

			if (bookQty < 0)
				cout << "Invalid Quantity" << endl;
			else if (bookQty > getQty(serial))
				cout << "Not enough books in cart to remove" << endl;
			else if (bookQty == getQty(serial))
			{
				cout << "Removed \"" << getTitle(serial) << "\"" << endl;
				t.removeItem(serial);

			}
			else
			{
				cout << "Removed " << bookQty << " titles of \"" << getTitle(serial) << "\""<< endl;
				t.removeQty(serial, bookQty);
			}
		}
	}

	system("pause");
		


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

/*
int Cashier::searchCart(const Cart (&t)[50], int s)
{
	int index = 0;			// Used as a subscript to search array
	int position = -1;		// To record position of search value
	bool found = false;		// Flag to indicate if the value was found

	while (index < 50 && !found)
	{
		if (t[index].getItemCode() == s) // If value is found
		{
			found = true;				// Set the flag
			position = index;			// Record the value's subscript
		}
		index++;						// Go to the next element
	}

	return position;
}
*/