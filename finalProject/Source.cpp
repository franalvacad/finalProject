#include <iostream>
#include <iomanip>
#include "Cashier.h"
#include <time.h>
using namespace std;

void inventTest()
{
	inventory changes;
	int ser;
	string term;
	char res;
	bool test = 0;

	while (!test)
	{
		cout << "(A)dd, (M)odify, (D)elete: ";
		cin >> res;
		if (islower(res))
			res = toupper(res);

		switch (res)
		{
		default:
			cout << "Try again please!" << endl;
			break;
		case 'A':
			test = true;
			changes.add();
			break;
		case 'M' || 'D':
			test = true;
			cout << "Please enter a search term: ";
			getline(cin, term);
			changes.search(term);

			cout << endl;

			cout << "Enter ayy";
			break;
		}
	}

	cout << endl;

		

}





int main()
{
	Cashier cash;
	Cart takeOut[50];
	int choice = 0, type = 0;

	try{
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
				int inp = 0;
				cout << "***********************************************************************************************************" << endl;
				cout << "*                                            CASHIER MODULE                                               *" << endl;
				cout << "***********************************************************************************************************" << endl << endl;

				cash.addToCart(takeOut);
				cash.viewCart(takeOut);
				cash.removeFromCart(takeOut);
				cash.viewCart(takeOut);

				/*
				cout << "Enter Item Code: ";
				cin >> inp;

				int i = cash.findBook(inp);
				int qty = 0;

				//cout system date over here
				cout << setw(9) << left << "Item Code" << setw(35) << left << "Title" << setw(15) << left << "ISBN" << setw(8)
					<< left << "MSRP($)" << setw(8) << left << "Qty" << setw(8) << left << "Total($)" << endl;
				cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;
				cash.getListCustom(i);
				cin >> qty;

				*/
			}
			else if (choice == 2)
			{
				cout << "***********************************************************************************************************" << endl;
				cout << "*                                     INVENTORY DATABASE MODULE                                           *" << endl;
				cout << "***********************************************************************************************************" << endl << endl;
			}
			else if (choice == 3)
			{

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
					cash.getList();
				else if (type == 2)
					cash.getWholelist();
				else if (type == 3)
					cash.getRetaillist();
				else if (type == 4)
					cash.getQTYlist();
				else if (type == 5)
					cash.getCostlist();
				else if (type == 6)
					cash.getAgelist();
				else if (type == 9);
				//return to main
				else cout << "Invalid Input." << endl;

				cout << "-----------------------------------------------------------------------------------------------------------" << endl;
				choice = 0;
				type = 0;
			}
			
		} while (choice != 9); //loop to make sure program does not terminate unless user exits

		}
		catch (char *extstr){ cout << extstr; }
		system("pause>nul");
		return 0;
}