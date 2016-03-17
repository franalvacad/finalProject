#include <iostream>
#include <iomanip>
#include "Cashier.h"
#include <time.h>
using namespace std;


void cashMod()
{
	Cashier alpha;
	Cart takeOut;
	int inp = 0;
	cout << "********************************************************************" << endl;
	cout << "*                          CASHIER MODULE                          *" << endl;
	cout << "********************************************************************" << endl << endl;



	alpha.addToCart(takeOut);
	alpha.viewCart(takeOut);
	alpha.removeFromCart(takeOut);
	alpha.finishCheckout(takeOut);

}

void invMod()
{
	cout << "***********************************************************************************************************" << endl;
	cout << "*                                     INVENTORY DATABASE MODULE                                           *" << endl;
	cout << "***********************************************************************************************************" << endl << endl;

	inventory changes;
	string query;
	int ser;
	int term;
	char res,modPic;
	bool test = 0, modBool = 0;

	while (!test)
	{
		cout << "Inventory" << endl;
		cout << "------------------------------" << endl;
		cout << " A: Add" << endl;
		cout << " M: Modify" << endl;
		cout << " D: Delete" << endl;
		cout << " 9: RETURN" << endl << endl;
		cout << "Input choice: ";
		cin >> res;
		if (islower(res))
			res = toupper(res);

		if (res == 'A')
		{
			test = true;
			changes.add();
		}
		else if (res == 'D')
		{
			test = true;
			cout << "Search for title: ";
			cin.ignore();
			getline(cin, query);
			cout << endl;
			changes.search(query);

			cout << "Pick a serial: ";
			cin >> term;

			changes.del(changes.search2(term));

			cout << endl;

			break;
		}

		else if (res == 'M')
		{
			test = true;
			cout << "Search for title: ";
			cin.ignore();
			getline(cin, query);
			cout << endl;
			changes.search(query);

			cout << "Pick a serial: ";
			cin >> term;

			cout << endl;

			while (!modBool)
			{
				cout << "Change: (T)itle, (P)ublisher, (A)uthor, (I)SBN, (C)ost, (M)SRP, (Q)ty, typ(E), e(X)it: ";
				cin >> modPic;
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

		else if (res == '9')
			test = true;
		
		else cout << "Try again please!" << endl;
	}

	cout << endl;
	system("cls");
}

void repMod()
{
	display alpha;
	int choice = 0, type = 0;

	cout << "***********************************************************************************************************" << endl;
	cout << "*                                           REPORT MODULE                                                 *" << endl;
	cout << "***********************************************************************************************************" << endl << endl;

	cout << "No. Report Name" << endl;
	cout << "------------------------------" << endl;
	cout << " 1: Inventory List" << endl;
	cout << " 2: Inventory Wholesale Value" << endl;
	cout << " 3: Inventory Retail Value" << endl;
	cout << " 4: List by Quantity" << endl;
	cout << " 5: List by Cost" << endl;
	cout << " 6: List by Age" << endl;
	cout << " 9: RETURN" << endl << endl;
	cout << "Input choice: ";


	cin >> type;

	if (type == 1)
		alpha.getList();
	else if (type == 2)
		alpha.getWholelist();
	else if (type == 3)
		alpha.getRetaillist();
	else if (type == 4)
		alpha.getQTYlist();
	else if (type == 5)
		alpha.getCostlist();
	else if (type == 6)
		alpha.getAgelist();
	else if (type == 9);
	//return to main
	else cout << "Invalid Input." << endl;

	system("pause>nul");
	system("cls");
	choice = 0;
	type = 0;
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