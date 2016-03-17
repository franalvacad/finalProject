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
	cout << "***********************************************************************************************************" << endl;
	cout << "*                                            CASHIER MODULE                                               *" << endl;
	cout << "***********************************************************************************************************" << endl << endl;



	alpha.addToCart(takeOut);
	alpha.viewCart(takeOut);
	//alpha.finishCheckout(takeOut);

}

void invMod()
{
	cout << "***********************************************************************************************************" << endl;
	cout << "*                                     INVENTORY DATABASE MODULE                                           *" << endl;
	cout << "***********************************************************************************************************" << endl << endl;

	inventory changes;
	int ser;
	int term;
	char res;
	bool test = 0;

	while (!test)
	{
		cout << "(A)dd, (M)odify, (D)elete: ";
		cin >> res;
		if (islower(res))
			res = toupper(res);

		if (res == 'A')
		{
			test = true;
			changes.add();
		}
		else if (res == 'M' || res == 'D')
		{
			test = true;
			cout << "Search for isbn of book: ";
			cin >> term;

			changes.del(changes.search2(term));

			cout << endl;

			cout << "Enter ayy";
			break;
		}

		else cout << "Try again please!" << endl;
	}

	cout << endl;
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
	int choice;
	
	try 
	{
		do
		{
			//Menu displayed for user to make a choice
	
			cout << "***********************************************************************************************************" << endl;
			cout << "*                                          SERENDIPITY BOOKSELLERS                                        *" << endl;
			cout << "***********************************************************************************************************" << endl << endl;
			cout << "No. CHOICE" << endl;
			cout << "----------------------------" << endl;
			cout << " 1: Cashier Module" << endl;
			cout << " 2: Inventory Database Module" << endl;
			cout << " 3: Report Module" << endl;
			cout << " 9: Exit" << endl << endl;
			cout << "Input choice number: ";
			cin >> choice;
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
			
		} while (choice != 9); //loop to make sure program does not terminate unless user exits

	}
	catch (char *extstr){ cout << extstr; }
	
	system("pause>nul");
	return 0;
}