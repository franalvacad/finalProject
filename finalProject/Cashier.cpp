// Cashier Class Implementation
#include "Cashier.h"
#include <string>
#include <iomanip>
#include "Cart.h"

void Cashier::addToCart(Cart &t)
{
	int serial,				// Inputted book's item code
		bookQty;			// Inputted desired qty
	char choice;			// User choice to exit or not
	bool exit = false;		// Flag for exit
	bool valid = false;

	cout << "********************************************************************" << endl;
	cout << "*                          CASHIER MODULE                          *" << endl;
	cout << "********************************************************************" << endl << endl;

	do
	{

		do {
			valid = false;

			cout << "\nInsert Item Code for Book: " << endl;
			cin >> serial;

			// Validate user input
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(500, '\n');
				cout << "\n\t**Invalid input.**\n" << endl;
			}
			else if (serial <= 0)
				cout << "\n\t**Please enter a valid Item Code**\n";
			else
				valid = true;

		} while (!valid);
		
	

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
				remQty = getQty(serial - 1) - t.getQty(serial);
			}
			else
				remQty = getQty(serial - 1);

			do {
				valid = false;

				cout << "We have " << remQty << " books of \"" << getTitle(serial - 1) << "\"\n" << endl;
				cout << "Insert quantity to purchase: " << endl;
				cin >> bookQty;

				// Validate user input
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(500, '\n');
					cout << "\n\t**Invalid input.**\n" << endl;
				}
				else if (bookQty <= 0)
					cout << "\n\t**Please enter a valid quantity**\n" << endl;
				else if (bookQty > remQty)
					cout << "\n\t**Not enough books in inventory**\n" << endl;
				else
					valid = true;

			} while (!valid);

				// If item doesn't already exist in cart then add
				if (!t.itemExist(serial))
					t.addItem(serial, bookQty);
				// If it does exist then add to the existing quantity
				else
					t.addQty(serial, bookQty);
				cout << "Added " << bookQty << " titles of \"" << getTitle(serial -1) << "\"" << endl;

		}

		do {
			valid = false;

			cout << "\n" << endl
				<< "	To exit Cart(Y)\n"
				<< "	To Continue Adding to Cart (N)\n"
				<< "	Choice: ";
			cin >> choice;

			// Validate user input
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(500, '\n');
				cout << "\n\t**Invalid input.**\n" << endl;
			}
			else if (!(choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n'))
				cout << "\n\t**Please enter either Y/N**\n" << endl;
			else
				valid = true;

		} while (!valid);

		if (choice == 'Y' || choice == 'y')
			exit = true;

	} while (!exit);

	system("cls");
}

void Cashier::viewCart(Cart &t)
{
	Date todaysDate;	// Date object for today's date

	system("cls");

	cout << "********************************************************************" << endl;
	cout << "*                          CASHIER MODULE                          *" << endl;
	cout << "********************************************************************" << endl << endl;


	cout << "Date: " << todaysDate.getComputerDate() << "\n" << endl;
	cout << setw(11) << left << "Item Code" << setw(35) << left << "Title" << setw(15) << left << "ISBN" << setw(10) << left << "Price($)" << setw(8) << left << "Qty" << setw(8) << left << "Total($)" << endl;
	cout << "-------------------------------------------------------------------------------------------------------" << endl;

	int i = 0;

	int itemCount = t.countCart();

	while (i < itemCount)
	{
		cout << setw(11) << left << t.getSerial(i)
			<< setw(35) << left << getTitle(t.getSerial(i) - 1)
			<< setw(15) << left << getISBN(t.getSerial(i) - 1)
			<< fixed << setprecision(2)
			<< setw(10) << left << getCost(t.getSerial(i) -1)
			<< setw(8) << left << t.getQty(t.getSerial(i))
			<< fixed << setprecision(2)
			<< setw(8) << left << t.getQty(t.getSerial(i)) * getCost(t.getSerial(i) - 1) << endl;
		i++;
	}
	cout << endl;
	system("pause");
}

void Cashier::removeFromCart(Cart &t)
{

	int serial, bookNum, bookQty;
	char finish = 'N';
	bool valid = false;

	system("cls");

	cout << "********************************************************************" << endl;
	cout << "*                          CASHIER MODULE                          *" << endl;
	cout << "********************************************************************" << endl << endl;

	viewCart(t);

	do {
		valid = false;

		cout << "What book do you wish to remove from the cart? (Item Code): " << endl;
		cin >> serial;

		// Validate user input
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(500, '\n');
			cout << "\n\t**Invalid input.**\n" << endl;
		}
		else if (serial <= 0)
			cout << "\n\t**Please enter a valid Item Code**\n";
		else
			valid = true;

	} while (!valid);



	if (!t.itemExist(serial))
		cout << "Book not found in cart." << endl;
	else
	{
		// If theres only 1 book then remove the entry
		if (t.getQty(serial) == 1)
		{
			cout << "Removed \"" << getTitle(serial - 1) << "\"" << endl;
			t.removeItem(serial);
		}
		else
		{


			do
			{
				valid = false;

				cout << "How many titles of \"" << getTitle(serial - 1) << "\" do you wish to remove?" << endl;
				cin >> bookQty;

				// Validate user input
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(500, '\n');
					cout << "\n\t**Invalid input.**\n" << endl;
				}
				else if (bookQty <= 0)
					cout << "\n\t**Please enter a valid quantity**\n" << endl;
				else if (bookQty > getQty(serial - 1))
					cout << "\n\t**Not enough books in cart to remove**\n" << endl;
				else
					valid = true;

			} while (!valid);

			if (bookQty == getQty(serial - 1))
			{
				cout << "Removed \"" << getTitle(serial - 1) << "\"" << endl;
				t.removeItem(serial);

			}
			else
			{
				cout << "Removed " << bookQty << " titles of \"" << getTitle(serial - 1) << "\"" << endl;
				t.removeQty(serial, bookQty);
			}
		}
	}
	system("cls");
}

void Cashier::finishCheckout(Cart &t)
{
	viewCart(t);
	cout << "\n\n\n" << endl;
	cout << setw(10) << "        \t\tSubtotal" << setw(3) << fixed << setprecision(2) << right << "$"<< subtotal(t) << "\n";
	cout << setw(20) << "\t\tTax  " << setw(6) << fixed << setprecision(2) << right << "$" << tax(subtotal(t)) << "\n";
	cout << setw(20) << "\t\tTotal" << setw(6) << fixed << setprecision(2) << right << "$" << total(subtotal(t), tax(subtotal(t))) << "\n"
		<< endl;

	cout << "\t\t**Thank you for shopping at Serendipity BookSellers!**\n" << endl;

	// Change inventory

	int items;
	items = t.countCart();

	int i = 0;
	// Iterate through entire cart
	while (i < items)
	{
		// Check if	item's qty in cart is equal to that in inventory
		if (t.getQty(t.getSerial(i)) == getQty(t.getSerial(i) - 1))
			del(t.getSerial(i) - 1);
		else  // If not equal then decrement qty in inventory
		{
			int newQty;
			newQty = getQty(t.getSerial(i) - 1) - t.getQty(t.getSerial(i));
			setQty(newQty, t.getSerial(i) - 1);
			fileClear();
			fileMod(getSizeLine() + 1);
		}
		i++;
	}
	system("pause");
	system("cls");
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

double Cashier::subtotal(Cart &t) 
{
	int items;
	double subTotal;
	subTotal = 0;
	items = t.countCart();


	int i = 0;
	while (i < items)
	{  
		subTotal += t.getQty(t.getSerial(i)) * getCost(t.getSerial(i) - 1);
		i++;
	}
	return subTotal;
}

double Cashier::tax(double sub)
{
	return salesTaxRate * sub;
}

double Cashier::total(double sub, double tax)
{
	return sub + tax;
}