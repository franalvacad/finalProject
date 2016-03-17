// CIS 22B - Group Project
// Serendipity Bookstore - This program simulates a cash register, iventory, and report system for a bookstore
//		
//		Authors
// Antonio Bares Jr
// Francisco Alvarez
// Haroon Hayat
// Andrei Konovalov
// Juan Ramirez

#include <iostream>
#include <iomanip>
#include "Cashier.h"
#include <time.h>
using namespace std;


void cashMod()
{
	Cashier alpha;
	Cart takeOut;
	bool valid = false;
	int choice = 0;
	int inp = 0;
	cout << "********************************************************************" << endl;
	cout << "*                          CASHIER MODULE                          *" << endl;
	cout << "********************************************************************" << endl << endl;


	do {
		valid = false;

		cout << "		Code   Inventory Options" << endl;
		cout << "		------------------------------" << endl;
		cout << "		 1.     Add to Cart" << endl;
		cout << "		 2.     Remove from Cart" << endl;
		cout << "		 3.     View Cart" << endl;
		cout << "		 4.     Complete Checkout" << endl;
		cout << "		 5.     EXIT" << endl << endl;
		cout << "		 Input Option Code: ";

		cin >> choice;
		cin.ignore();

		system("cls");
		// Validate user input
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(500, '\n');
			cout << "\n\t**Invalid input.**\n" << endl;
		}
		else if (choice <= 0 || choice > 5)
		{
			cout << "\n\t**Please choose between 1 - 5**\n" << endl;
		}
		else





	if (choice == 1)
		alpha.addToCart(takeOut);
	else if (choice == 2)
		alpha.removeFromCart(takeOut);
	else if (choice == 3)
		alpha.viewCart(takeOut);
	else if (choice == 4)
		alpha.finishCheckout(takeOut);
	else
		valid = true;

	} while (!valid);
}

void invMod()
{
	cout << "********************************************************************" << endl;
	cout << "*                  INVENTORY DATABASE MODULE                       *" << endl;
	cout << "********************************************************************" << endl << endl;

	inventory changes;
	string query;
	int ser, term, choice;
	char modPic;
	bool test = 0, modBool = 0;
	bool valid = false;

	while (!test)
	{


		do {
			valid = false;

			cout << "		Code   Inventory Options" << endl;
			cout << "		------------------------------" << endl;
			cout << "		 1.     Add Book" << endl;
			cout << "		 2.     Modify Book" << endl;
			cout << "		 3.     Delete Book" << endl;
			cout << "		 4.     EXIT" << endl << endl;
			cout << "		 Input Option Code: ";

			cin >> choice;
			cin.ignore(500, '\n');

			system("cls");
			// Validate user input
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(500, '\n');
				cout << "\n\t**Invalid input.**\n" << endl;
			}
			else if (choice <= 0 || choice > 4)
			{
				cout << "\n\t**Please choose between 1 - 4**\n" << endl;
			}
			else
				valid = true;


		} while (!valid);

		if (choice == 1)
		{
			test = true;
			changes.add();
		}

		else if (choice == 2)
		{
			system("cls");
			cout << "********************************************************************" << endl;
			cout << "*                 INVENTORY DATABASE MODIFY BOOK                   *" << endl;
			cout << "********************************************************************" << endl << endl;


			test = true;
			cout << "Search for title: ";
			getline(cin, query);
			cin.ignore();
			cout << endl;
			changes.search(query);



			do {
				valid = false;

				cout << "Pick an item code: ";
				cin >> term;

				cin.ignore(500, '\n');

				// Validate user input
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(500, '\n');
					cout << "\n\t**Invalid input.**\n" << endl;
				}
				else if (term <= 0)
					cout << "\n\t**Please enter a valid item code**\n";
				else if (term > changes.getSizeLine())
					cout << "\n\t**Item code does not exist**\n" << endl;
				else
					valid = true;

			} while (!valid);

			cout << endl;

			while (!modBool)
			{
				cout << "Change: (T)itle, (P)ublisher, (A)uthor, (I)SBN, (C)ost, (M)SRP, (Q)ty, typ(E), e(X)it: ";
				cin >> modPic;
				cin.ignore();
				if (islower(modPic))
					modPic = toupper(modPic);

				if (modPic != 'X')
					changes.modify(modPic, term);

				else modBool = 1;
			}
			cout << endl;

			changes.fileClear();
			changes.fileMod(changes.getSizeLine() + 1);

			break;
		}

		else if (choice == 3)
		{
			system("cls");
			cout << "********************************************************************" << endl;
			cout << "*                 INVENTORY DATABASE DELETE BOOK                   *" << endl;
			cout << "********************************************************************" << endl << endl;
			
			test = true;
			cout << "Search for title: ";
			cin.ignore();
			getline(cin, query);
			cout << endl;
			changes.search(query);


			do {
				valid = false;

				cout << "Pick an item code: ";
				cin >> term;

				cin.ignore(500, '\n');

				// Validate user input
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(500, '\n');
					cout << "\n\t**Invalid input.**\n" << endl;
				}
				else if (term <= 0)
					cout << "\n\t**Please enter a valid item code**\n" << endl;
				else if (term > changes.getSizeLine())
					cout << "\n\t**Item code does not exist**\n" << endl;
				else
					valid = true;

			} while (!valid);

			changes.del(changes.search2(term));

			cout << endl;

			break;
		}

		else if (choice == 4)
			test = true;
		
	}

	cout << endl;
	system("cls");
}

void repMod()
{
	bool valid = false;
	display alpha;
	int choice = 0;



	do {
		valid = false;

		cout << "********************************************************************" << endl;
		cout << "*                          REPORT MODULE                           *" << endl;
		cout << "********************************************************************" << endl << endl;

		cout << "		No. Report Name" << endl;
		cout << "		------------------------------" << endl;
		cout << "		1: Inventory List" << endl;
		cout << "		2: Inventory Wholesale Value" << endl;
		cout << "		3: Inventory Retail Value" << endl;
		cout << "		4: List by Quantity" << endl;
		cout << "		5: List by Cost" << endl;
		cout << "		6: List by Age" << endl;
		cout << "		7: RETURN" << endl << endl;
		cout << "		Input choice: ";

		cin >> choice;
		cin.ignore(500, '\n');

		system("cls");
		// Validate user input
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(500, '\n');
			cout << "\n\t**Invalid input.**\n" << endl;
		}
		else if (choice <= 0 || choice > 7)
		{
			cout << "\n\t**Please choose between 1 - 7**\n" << endl;
		}
		else
			valid = true;


	} while (!valid);

	if (choice == 1)
		alpha.getList();
	else if (choice == 2)
		alpha.getWholelist();
	else if (choice == 3)
		alpha.getRetaillist();
	else if (choice == 4)
		alpha.getQTYlist();
	else if (choice == 5)
		alpha.getCostlist();
	else if (choice == 6)
		alpha.getAgelist();
	else if (choice == 7);
	//return to main
	else cout << "Invalid Input." << endl;

	system("pause>nul");
	system("cls");
	choice = 0;
}

int main()
{
	//inventory test;
	int choice;
	bool menu = 0;
	bool valid = false;
	
	try 
	{
		while (!menu)
		{
			//Menu displayed for user to make a choice
	
			do {
				valid = false;
				system("cls");

				cout << "********************************************************************" << endl;
				cout << "*                     SERENDIPITY BOOKSELLERS                      *" << endl;
				cout << "********************************************************************" << endl << endl;
				cout << "		No. CHOICE" << endl;
				cout << "		----------------------------" << endl;
				cout << "		1: Cashier Module" << endl;
				cout << "		2: Inventory Database Module" << endl;
				cout << "		3: Report Module" << endl;
				cout << "		4: EXIT" << endl << endl;
				cout << "		Input choice number: ";

				cin >> choice;
				cin.ignore(500, '\n');

				// Validate user input
				if (cin.fail())
				{
					system("cls");
					cin.clear();
					cin.ignore(500, '\n');
					cout << "\n\t**Invalid input.**\n\n" << endl;
				}
				else if (choice <= 0 || choice > 4)
				{
					system("cls");
					cout << "\n\t**Please enter a choice between 1 and 4**\n\n";
				}
				else
					valid = true;

			} while (!valid);


			if (choice == 1)
			{
				system("cls");
				cashMod();
			}
			else if (choice == 2)
			{
				system("cls");
				invMod();
			}
			else if (choice == 3)
			{
				system("cls");
				repMod();
			}
			else if (choice == 4)
				menu = true;
			
		} //loop to make sure program does not terminate unless user exits

	}
	catch (char *extstr){ cout << extstr; }
	
	system("pause>nul");
	return 0;
}