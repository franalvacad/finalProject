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

	cout << setw(4) << "No." << setw(35) << left << "Title" << setw(35) << left << "Publisher" << setw(25) << left << "Author" << setw(15) 
		<< left << "ISBN" << setw(8) << left << "Cost ($)" << setw(8) << left << "MSRP ($)" << setw(5) << left << "Qty" << setw(10) << left << "Type" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < size - 1; i++) 
	{
		cout << setw(4) << left << baseClass::getSerial(i) << setw(35) << left << baseClass::getTitle(i) << setw(35) << left << baseClass::getPublisher(i) << setw(25) 
			<< left << baseClass::getAuthor(i) << setw(15) << left << baseClass::getISBN(i) << setw(8) << left << baseClass::getCost(i) << setw(8) << left << baseClass::getMSRP(i) 
			<< setw(5) << left << baseClass::getQty(i) << setw(10) << left << baseClass::getType(i) << endl;
	}
}


void display::getWholelist() //Complete
{
	double totPrice = 0;
	int size = baseClass::getSizeLine();
	
	cout << setw(4) << "No." << setw(35) << left << "Title" << setw(35) << left << "Publisher" << setw(25) << left << "Author" << setw(15)
		<< left << "ISBN" << setw(10) << left << "Type" << setw(8) << left << "Cost($) " << setw(5) << left << "Qty" << setw(8) << left << "Total($) " << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < size - 1; i++) 
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

	cout << setw(4) << "No." << setw(35) << left << "Title" << setw(35) << left << "Publisher" << setw(25) << left << "Author" << setw(15)
		<< left << "ISBN" << setw(10) << left << "Type" << setw(8) << left << "MSRP($) " << setw(5) << left << "Qty" << setw(8) << left << "Total($) " << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < size - 1; i++)
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

/*
void display::getQTYlist()
{
	int j = 0;
	int max = 0; // depeds from list (qty,cost,age) sort displaylistis
	int maxpos = 0;
	int x = baseClass::getSizeLine();
	bool *chk = new bool[x];
	for (int i = 0; i < x; i++){
		chk[i] = 0;
	}
	int tempQTY = 0;
	cout << setw(4) << "No." << setw(35) << left << "Title" << setw(35) << left << "Publisher" << setw(25) << left << "Author" << setw(15)
		<< left << "ISBN" << setw(8) << left << "Cost ($)" << setw(8) << left << "MSRP ($)" << setw(5) << left << "Qty" << setw(10) << left << "Type" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < x; i++){
		for (j = 0; j < x; j++){
			tempQTY = baseClass::getQty(j);
			if (max <= tempQTY && chk[j] == false){
				max = getQty(j);
				maxpos = j;
			}
		}
			chk[j] = true;
			
			cout << setw(4) << left << baseClass::getSerial(j) << setw(35) << left << baseClass::getTitle(j) << setw(35) << left << baseClass::getPublisher(j) << setw(25)
				<< left << baseClass::getAuthor(j) << setw(15) << left << baseClass::getISBN(j) << setw(8) << left << baseClass::getCost(j) << setw(8) << left << baseClass::getMSRP(j)
				<< setw(5) << left << baseClass::getQty(j) << setw(10) << left << baseClass::getType(j) << endl;
			
			max = 0;
			j = 0;

	}
	//return "test";
}

void display::getCostlist()
{
	int j = 0;
	double max = 0; // depeds from list (qty,cost,age) sort displaylistis
	int maxpos = 0;
	int x = baseClass::getSizeLine();
	bool *chk = new bool[x];

	for (int i = 0; i < x; i++){
		for (j = 0; j < x; j++){
			if (max <= baseClass::getCost(j) && chk[j] == false){
				max = getCost(j);
				maxpos = j;
			}
		}

		chk[j] = true;
		cout << "(T__T)";
		max = 0;
		j = 0;
	}
}
void display::getAgelist()
{
	int j = 0;
	int  maxy = 0; // depeds from list (qty,cost,age) sort displaylistis
	int  maxm = 0;
	int  maxd = 0;
	int maxpos = 0;
	int x = baseClass::getSizeLine();
	bool *chk = new bool[x];

	for (int i = 0; i < x; i++){
		for ( j = 0; j < x; j++){
			if (maxy <= dateAdded[j].getYear() && maxm <= dateAdded[j].getMonth() && maxd <= dateAdded[j].getDay() && chk[j] == false){
				maxy = dateAdded[j].getYear();
				maxm = dateAdded[j].getMonth();
				maxd = dateAdded[j].getDay();
				maxpos = j;

			}
		}
		chk[j] = true;
		cout << "(T__T)";
		maxy = 0;
		maxm = 0;
		maxd = 0;	
	}
}
*/