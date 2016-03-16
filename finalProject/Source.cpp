#include <iostream>
#include "inventory.h"
#include <time.h>
using namespace std;

//void inventTest()
//{
//	inventory changes;
////	int ser;
//	string term;
//	char res;
//	bool test = 0;
//
//	while (!test)
//	{
//		cout << "(A)dd, (M)odify, (D)elete: ";
//		cin >> res;
//		if (islower(res))
//			res = toupper(res);
//
//		switch (res)
//		{
//		default:
//			cout << "Try again please!" << endl;
//			break;
//		case 'A':
//			test = true;
//			changes.add();
//			break;
//		case 'M' || 'D':
//			test = true;
//			cout << "Please enter a search term: ";
//			getline(cin, term);
//			changes.search(term);
//
//			cout << endl;
//
//			cout << "Enter ayy";
//			break;
//		}
//	}
//
//	cout << endl;
//
//		
//
//}


int main()
{
	baseClass test;

	try{
		inventory test;
		////display test2;
		//int size = test.getSizeLine(), srch;
		//string results;

		////cout << "term: ";

		//Date newDate;
		////cout << newDate.getComputerDate();

		//results = test.getTitle(4);

		test.getList();

		//time_t c = time(NULL);
		//char *h = ctime(&c);

		//cout << endl << endl;
		//test.search("serendipity");

		//inventTest();
		


//		cout << h;
	}
	catch (char *extstr){ cout << extstr; }
	system("pause>nul");
	return 0;
}

//Menu Display NOT Complete (can have switch)
/*
int choice = 0, type = 0;
do
{
//Menu displayed for user to make a choice

cout << "***********************************************************************************************************" << endl;
cout << "*                                    SERENDIPITY BOOKSELLERS                                              *" << endl;
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
cout << "***********************************************************************************************************" << endl;
cout << "*                                            CASHIER MODULE                                               *" << endl;
cout << "***********************************************************************************************************" << endl << endl;

//get cashier screen

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
{
test2.getList();
}
else if (type == 2)
{
test2.getWholelist();
}
else if (type == 3)
{
test2.getRetaillist();
}
else if (type == 4)
{
test2.getQTYlist();
}
else if (type == 5)
{
test2.getCostlist();
}
else if (type == 6)
{
test2.getAgelist();
}
else if (type == 9)
{
//return to main
}
else
{
cout << "Invalid Input." << endl;
}
else
{
cout << "Invalid Input." << endl; //if choice is neither one from the menu
}

cout << "-----------------------------------------------------------------------------------------------------------" << endl;
choice = 0;
type = 0;

} while (choice != 9); //loop to make sure program does not terminate unless user exits
return 0;
*/