#include"displayClass.h"
#include "Date.h"
#include <iomanip>
using namespace std;

display::display()
{
}

void display::getList() //Complete
{
	int size = baseClass::getSizeLine();

	cout << "**********************************************************************************************************************************************************" << endl;
	cout << "*                                                                  INVENTORY LIST REPORT                                                                 *" << endl;
	cout << "**********************************************************************************************************************************************************" << endl << endl;

	cout << setw(4) << "No." << setw(35) << left << "Title" << setw(35) << left << "Publisher" << setw(25) << left << "Author" << setw(15)
		<< left << "ISBN" << setw(8) << left << "Cost($) " << setw(8) << left << "MSRP($) " << setw(5) << left << "Qty" << setw(10) << left
		<< "Type" << setw(8) << left << "Date Added" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < size; i++)
	{
		cout << setw(4) << left << baseClass::getSerial(i) << setw(35) << left << baseClass::getTitle(i) << setw(35) << left << baseClass::getPublisher(i) << setw(25)
			<< left << baseClass::getAuthor(i) << setw(15) << left << baseClass::getISBN(i) << setw(8) << left << baseClass::getCost(i) << setw(8) << left << baseClass::getMSRP(i)
			<< setw(5) << left << baseClass::getQty(i) << setw(10) << left << baseClass::getType(i) << setw(8) << left << baseClass::getDate(i) << endl;
	}
}

void display::getListCustom(int i) //Complete
{
		cout << setw(4) << left << baseClass::getSerial(i) << setw(35) << left << baseClass::getTitle(i) << setw(35) << left << baseClass::getPublisher(i) << setw(25)
			<< left << baseClass::getAuthor(i) << setw(15) << left << baseClass::getISBN(i) << setw(8) << left << baseClass::getCost(i) << setw(8) << left << baseClass::getMSRP(i)
			<< setw(5) << left << baseClass::getQty(i) << setw(10) << left << baseClass::getType(i) << setw(8) << left << baseClass::getDate(i) << endl;
}

void display::getWholelist() //Complete
{
	double totPrice = 0;
	int size = baseClass::getSizeLine();

	cout << "*************************************************************************************************************************************************" << endl;
	cout << "*                                                        INVENTORY WHOLESALE VALUE REPORT                                                       *" << endl;
	cout << "*************************************************************************************************************************************************" << endl << endl;

	cout << setw(4) << "No." << setw(35) << left << "Title" << setw(35) << left << "Publisher" << setw(25) << left << "Author" << setw(15)
		<< left << "ISBN" << setw(10) << left << "Type" << setw(8) << left << "Cost($) " << setw(5) << left << "Qty" << setw(8) << left << "Total($) " << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < size; i++)
	{
		double price = 0;
		price = baseClass::getCost(i) * baseClass::getQty(i);

		cout << setw(4) << left << baseClass::getSerial(i) << setw(35) << left << baseClass::getTitle(i) << setw(35) << left << baseClass::getPublisher(i) << setw(25)
			<< left << baseClass::getAuthor(i) << setw(15) << left << baseClass::getISBN(i) << setw(10) << left << baseClass::getType(i) << setw(8) << left << baseClass::getCost(i) << setw(5) << left << baseClass::getQty(i)
			<< setw(8) << left << price << endl;

		totPrice += price;
	}
	cout << endl << "Total Wholesale Value: $ " << totPrice << endl;
}

void display::getRetaillist() //Complete
{
	double totPrice = 0;
	int size = baseClass::getSizeLine();

	cout << "*************************************************************************************************************************************************" << endl;
	cout << "*                                                        INVENTORY RETAIL VALUE REPORT                                                          *" << endl;
	cout << "*************************************************************************************************************************************************" << endl << endl;

	cout << setw(4) << "No." << setw(35) << left << "Title" << setw(35) << left << "Publisher" << setw(25) << left << "Author" << setw(15)
		<< left << "ISBN" << setw(10) << left << "Type" << setw(8) << left << "MSRP($) " << setw(5) << left << "Qty" << setw(8) << left << "Total($) " << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < size; i++)
	{
		double price = 0;
		price = baseClass::getMSRP(i) * baseClass::getQty(i);

		cout << setw(4) << left << baseClass::getSerial(i) << setw(35) << left << baseClass::getTitle(i) << setw(35) << left << baseClass::getPublisher(i) << setw(25)
			<< left << baseClass::getAuthor(i) << setw(15) << left << baseClass::getISBN(i) << setw(10) << left << baseClass::getType(i) << setw(8) << left << baseClass::getMSRP(i) << setw(5) << left << baseClass::getQty(i)
			<< setw(8) << left << price << endl;

		totPrice += price;
	}
	cout << endl << "Total Retail Value: $ " << totPrice << endl;
}

void display::getQTYlist() //complete
{
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

	cout << setw(4) << "No." << setw(35) << left << "Title" << setw(35) << left << "Publisher" << setw(25) << left << "Author" << setw(15)
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
		cout << setw(4) << left << baseClass::getSerial(maxpos) << setw(35) << left << baseClass::getTitle(maxpos) << setw(35) << left << baseClass::getPublisher(maxpos) << setw(25)
			<< left << baseClass::getAuthor(maxpos) << setw(15) << left << baseClass::getISBN(maxpos) << setw(8) << left << baseClass::getCost(maxpos) << setw(8) << left << baseClass::getMSRP(maxpos)
			<< setw(5) << left << baseClass::getQty(maxpos) << setw(10) << left << baseClass::getType(maxpos) << endl;
		max = 0;
	}
	delete[] chk;
}

void display::getCostlist() //complete
{
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

	cout << setw(4) << "No." << setw(35) << left << "Title" << setw(35) << left << "Publisher" << setw(25) << left << "Author" << setw(15)
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
		cout << setw(4) << left << baseClass::getSerial(maxpos) << setw(35) << left << baseClass::getTitle(maxpos) << setw(35) << left << baseClass::getPublisher(maxpos) << setw(25)
			<< left << baseClass::getAuthor(maxpos) << setw(15) << left << baseClass::getISBN(maxpos) << setw(8) << left << baseClass::getCost(maxpos) << setw(8) << left << baseClass::getMSRP(maxpos)
			<< setw(5) << left << baseClass::getQty(maxpos) << setw(10) << left << baseClass::getType(maxpos) << endl;
		max = 0;
	}
}

void display::getAgelist()
{
	int  miny = 10000; // depeds from list (qty,cost,age) sort displaylistis
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
	cout << setw(4) << "No." << setw(35) << left << "Title" << setw(35) << left << "Publisher" << setw(25) << left << "Author" << setw(15)
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
		cout << setw(4) << left << baseClass::getSerial(minpos) << setw(35) << left << baseClass::getTitle(minpos) << setw(35) << left << baseClass::getPublisher(minpos) << setw(25)
			<< left << baseClass::getAuthor(minpos) << setw(15) << left << baseClass::getISBN(minpos) << setw(8) << left << baseClass::getCost(minpos) << setw(8) << left << baseClass::getMSRP(minpos)
			<< setw(5) << left << baseClass::getQty(minpos) << setw(10) << left << baseClass::getType(minpos) << setw(8) << left << baseClass::getDate(minpos) << endl;
		miny = 10000;
		minm = 10000;
		mind = 10000;
	}
}