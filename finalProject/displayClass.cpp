// Display Class Implementation
#include"displayClass.h"
#include "Date.h"
#include <iostream>
#include <iomanip>
using namespace std;

//Default Constructor
display::display()
{
}

//Default Destructor
display::~display()
{
}

int display::getMAuthorlength() //Gets length of longest Author name for display purposes
{
	int max = 0;
	int size = baseClass::getSizeLine();
	for (int i = 0; i < size; i++){
		if (max < baseClass::getAuthor(i).length()){ max = baseClass::getAuthor(i).length(); }
	}
	return max;
}
int display::getMPublisherlength() //Gets length of longest Publisher name for display purposes
{
	int max = 0;
	int size = baseClass::getSizeLine();
	for (int i = 0; i < size; i++){
		if (max < baseClass::getPublisher(i).length()){ max = baseClass::getPublisher(i).length(); }
	}
	return max;
}
int display::getMTitlelength() //Gets length of longest Book Title for display purposes
{
	int max = 0;
	int size = baseClass::getSizeLine();
	for (int i = 0; i < size; i++){
		if (max < baseClass::getTitle(i).length()){ max = baseClass::getTitle(i).length(); }
	}
	return max; 
}


void display::getList() //Displays all books and there information in table form
{
	system("cls");
	
	int size = baseClass::getSizeLine();

	cout << "****************************************************************************************************************************************************" << endl;
	cout << "*                                                               INVENTORY LIST REPORT                                                              *" << endl;
	cout << "****************************************************************************************************************************************************" << endl << endl;

	cout << setw(10) << left << "Item Code" << setw(display::getMTitlelength() + 2) << left << "Title" << setw(display::getMPublisherlength() + 2) << left << "Publisher" << setw(display::getMAuthorlength() + 2) << left << "Author" << setw(15)
		<< left << "ISBN" << setw(8) << left << "Cost($) " << setw(8) << left << "MSRP($) " << setw(5) << left << "Qty" << setw(10) << left
		<< "Type" << setw(8) << left << "Date Added" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < size; i++)
	{
		cout << setprecision(2) << fixed;
		cout << setw(7) << right << baseClass::getSerial(i) << "   " << setw(display::getMTitlelength() + 2) << left << baseClass::getTitle(i) << setw(display::getMPublisherlength() + 2) << left << baseClass::getPublisher(i) << setw(display::getMAuthorlength() + 2)
			<< left << baseClass::getAuthor(i) << setw(15) << left << baseClass::getISBN(i) << setw(8) << left << baseClass::getCost(i) << setw(8) << left << baseClass::getMSRP(i)
			<< setw(5) << left << baseClass::getQty(i) << setw(10) << left << baseClass::getType(i) << setw(8) << left << baseClass::getDate(i) << endl;
	}

	cout << endl << "Press ENTER to continue..." << endl;
}

void display::getListCustom(int i) //Displays selective book information for inventory module
{
	cout << setprecision(2) << fixed;
	cout << setw(4) << left << baseClass::getSerial(i) << setw(display::getMTitlelength() + 2) << left << baseClass::getTitle(i) << setw(35) << left << baseClass::getPublisher(i) << setw(25)
			<< left << baseClass::getAuthor(i) << setw(15) << left << baseClass::getISBN(i) << setw(8) << left << baseClass::getCost(i) << setw(8) << left << baseClass::getMSRP(i)
			<< setw(5) << left << baseClass::getQty(i) << setw(10) << left << baseClass::getType(i) << setw(8) << left << baseClass::getDate(i) << endl;
}

void display::getWholelist() //Displays all books and product of there quantity and cost under the total
{
	system("cls");
	
	double totPrice = 0;
	int size = baseClass::getSizeLine();

	cout << "*************************************************************************************************************************************************" << endl;
	cout << "*                                                        INVENTORY WHOLESALE VALUE REPORT                                                       *" << endl;
	cout << "*************************************************************************************************************************************************" << endl << endl;

	cout << setw(10) << left << "Item Code" << setw(display::getMTitlelength() + 2) << left << "Title" << setw(display::getMPublisherlength() + 2) << left << "Publisher" << setw(25) << left << "Author" << setw(15)
		<< left << "ISBN" << setw(10) << left << "Type" << setw(8) << left << "Cost($) " << setw(5) << left << "Qty" << setw(8) << left << "Total($) " << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < size; i++)
	{
		double price = 0;
		price = baseClass::getCost(i) * baseClass::getQty(i);

		cout << setprecision(2) << fixed;
		cout << setw(7) << right << baseClass::getSerial(i) << "   " << setw(display::getMTitlelength() + 2) << left << baseClass::getTitle(i) << setw(display::getMPublisherlength() + 2) << left << baseClass::getPublisher(i) << setw(25)
			<< left << baseClass::getAuthor(i) << setw(15) << left << baseClass::getISBN(i) << setw(10) << left << baseClass::getType(i) << setw(8) << left << baseClass::getCost(i) << setw(5) << left << baseClass::getQty(i)
			<< setw(8) << left << price << endl;

		totPrice += price;
	}
	cout << endl << "Total Wholesale Value: $ " << totPrice << endl;
	cout << endl << "Press ENTER to continue..." << endl;
}

void display::getRetaillist() //Displays all books and product of there quantity and retail price under the total
{
	system("cls");
	
	double totPrice = 0;
	int size = baseClass::getSizeLine();

	cout << "*************************************************************************************************************************************************" << endl;
	cout << "*                                                        INVENTORY RETAIL VALUE REPORT                                                          *" << endl;
	cout << "*************************************************************************************************************************************************" << endl << endl;

	cout << setw(10) << left << "Item Code" << setw(display::getMTitlelength() + 2) << left << "Title" << setw(display::getMPublisherlength() + 2) << left << "Publisher" << setw(25) << left << "Author" << setw(15)
		<< left << "ISBN" << setw(10) << left << "Type" << setw(8) << left << "MSRP($) " << setw(5) << left << "Qty" << setw(8) << left << "Total($) " << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < size; i++)
	{
		double price = 0;
		price = baseClass::getMSRP(i) * baseClass::getQty(i);

		cout << setprecision(2) << fixed;
		cout << setw(7) << right << baseClass::getSerial(i) << "   " << setw(display::getMTitlelength() + 2) << left << baseClass::getTitle(i) << setw(display::getMPublisherlength() + 2) << left << baseClass::getPublisher(i) << setw(25)
			<< left << baseClass::getAuthor(i) << setw(15) << left << baseClass::getISBN(i) << setw(10) << left << baseClass::getType(i) << setw(8) << left << baseClass::getMSRP(i) << setw(5) << left << baseClass::getQty(i)
			<< setw(8) << left << price << endl;

		totPrice += price;
	}
	cout << endl << "Total Retail Value: $ " << totPrice << endl;
	cout << endl << "Press ENTER to continue..." << endl;
}

void display::getQTYlist() //Displays all books sorted by quantity
{
	system("cls");
	
	int max = 0;
	int maxpos = 0;
	int x = baseClass::getSizeLine();
	int *chk = NULL;
	chk = new int[25];
	for (int i = 0; i < x; i++)
	{
		chk[i] = 0;
	}

	cout << "*************************************************************************************************************************************************" << endl;
	cout << "*                                                           LIST BY QUANTITY REPORT                                                             *" << endl;
	cout << "*************************************************************************************************************************************************" << endl << endl;

	cout << setw(10) << left << "Item Code" << setw(display::getMTitlelength() + 2) << left << "Title" << setw(display::getMPublisherlength() + 2) << left << "Publisher" << setw(25) << left << "Author" << setw(15)
		<< left << "ISBN" << setw(8) << left << "Cost($) " << setw(8) << left << "MSRP($) " << setw(5) << left << "Qty" << setw(10) << left
		<< "Type" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < x; i++){
		for (int j = 0; j < x; j++){
			if (max <= baseClass::getQty(j) && chk[j] == 0){
				max = getQty(j);
				maxpos = j;
			}
		}
		chk[maxpos] = 1;
		cout << setprecision(2) << fixed;
		cout << setw(7) << right << baseClass::getSerial(maxpos) << "   " << setw(display::getMTitlelength() + 2) << left << baseClass::getTitle(maxpos) << setw(display::getMPublisherlength() + 2) << left << baseClass::getPublisher(maxpos) << setw(25)
			<< left << baseClass::getAuthor(maxpos) << setw(15) << left << baseClass::getISBN(maxpos) << setw(8) << left << baseClass::getCost(maxpos) << setw(8) << left << baseClass::getMSRP(maxpos)
			<< setw(5) << left << baseClass::getQty(maxpos) << setw(10) << left << baseClass::getType(maxpos) << endl;
		max = 0;
	}
	delete[] chk;
	cout << endl << "Press ENTER to continue..." << endl;
}

void display::getCostlist() //Displays all books sorted by cost price
{
	system("cls");
	
	double max = 0;
	int maxpos = 0;
	int x = baseClass::getSizeLine();
	int *chk = NULL;
	chk = new int[25];
	for (int i = 0; i < x; i++){
		chk[i] = 0;
	}

	cout << "*************************************************************************************************************************************************" << endl;
	cout << "*                                                              LIST BY COST REPORT                                                              *" << endl;
	cout << "*************************************************************************************************************************************************" << endl << endl;

	cout << setw(10) << left << "Item Code" << setw(display::getMTitlelength() + 2) << left << "Title" << setw(display::getMPublisherlength() + 2) << left << "Publisher" << setw(25) << left << "Author" << setw(15)
		<< left << "ISBN" << setw(8) << left << "Cost($) " << setw(8) << left << "MSRP($) " << setw(5) << left << "Qty" << setw(10) << left
		<< "Type" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < x; i++){
		for (int j = 0; j < x; j++){
			if (max <= baseClass::getCost(j) && chk[j] == 0){
				max = getCost(j);
				maxpos = j;
			}
		}

		chk[maxpos] = 1;
		cout << setprecision(2) << fixed;
		cout << setw(7) << right << baseClass::getSerial(maxpos) << "   " << setw(display::getMTitlelength() + 2) << left << baseClass::getTitle(maxpos) << setw(display::getMPublisherlength() + 2) << left << baseClass::getPublisher(maxpos) << setw(25)
			<< left << baseClass::getAuthor(maxpos) << setw(15) << left << baseClass::getISBN(maxpos) << setw(8) << left << baseClass::getCost(maxpos) << setw(8) << left << baseClass::getMSRP(maxpos)
			<< setw(5) << left << baseClass::getQty(maxpos) << setw(10) << left << baseClass::getType(maxpos) << endl;
		max = 0;
	}
	cout << endl << "Press ENTER to continue..." << endl;
}

void display::getAgelist() //Displays all books sorted by date added
{
	system("cls");
	
	int  miny = 10000; 
	int  minm = 10000;
	int  mind = 10000;
	int minpos = 0;
	int x = baseClass::getSizeLine(); 
	int *chk = NULL;
	chk = new int[25];
	for (int i = 0; i < x; i++){
		chk[i] = 0;
	}
	int tempy;
	int tempm;
	int tempd;
	
	cout << "***********************************************************************************************************************************************************" << endl;
	cout << "*                                                                     LIST BY AGE REPORT                                                                  *" << endl;
	cout << "***********************************************************************************************************************************************************" << endl << endl;
	cout << setw(10) << left << "Item Code" << setw(display::getMTitlelength() + 2) << left << "Title" << setw(display::getMPublisherlength() + 2) << left << "Publisher" << setw(25) << left << "Author" << setw(15)
		<< left << "ISBN" << setw(8) << left << "Cost($) " << setw(8) << left << "MSRP($) " << setw(5) << left << "Qty" << setw(10) << left
		<< "Type" << setw(8) << left << "Date Added" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < x; i++){
		for (int j = 0; j < x; j++){
			tempy = dateAdded[j].getYear();
			tempm = dateAdded[j].getMonth();
			tempd = dateAdded[j].getDay();
			if (miny > tempy  && chk[j] == 0){
				miny = dateAdded[j].getYear();
				minm = dateAdded[j].getMonth();
				mind = dateAdded[j].getDay();
				minpos = j;
			}else if(miny == tempy  && chk[j] == 0){
				if (minm > tempm){
					miny = dateAdded[j].getYear();
					minm = dateAdded[j].getMonth();
					mind = dateAdded[j].getDay();
					minpos = j;
				}
				else if (minm == tempm){
					if (mind >= tempd){
						miny = dateAdded[j].getYear();
						minm = dateAdded[j].getMonth();
						mind = dateAdded[j].getDay();
						minpos = j;
					}
				}
			}
		}
		chk[minpos] = 1;
		cout << setprecision(2) << fixed;
		cout << setw(7) << right << baseClass::getSerial(minpos) << "   " << setw(display::getMTitlelength() + 2) << left << baseClass::getTitle(minpos) << setw(display::getMPublisherlength() + 2) << left << baseClass::getPublisher(minpos) << setw(25)
			<< left << baseClass::getAuthor(minpos) << setw(15) << left << baseClass::getISBN(minpos) << setw(8) << left << baseClass::getCost(minpos) << setw(8) << left << baseClass::getMSRP(minpos)
			<< setw(5) << left << baseClass::getQty(minpos) << setw(10) << left << baseClass::getType(minpos) << setw(8) << left << baseClass::getDate(minpos) << endl;
		miny = 10000;
		minm = 10000;
		mind = 10000;
	}
	cout << endl << "Press ENTER to continue..." << endl;
}

void display::getShortListCustom(int i) // Displays selective book information for cashier module
{
	cout << setprecision(2) << fixed;
	cout << setw(4) << left << baseClass::getSerial(i) << setw(35) << left << baseClass::getTitle(i) << setw(15) << left << baseClass::getISBN(i) << setw(8) << left << baseClass::getMSRP(i) << endl;
}