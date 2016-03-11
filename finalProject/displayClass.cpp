#include"displayClass.h"
#include "Date.h"
#include <iomanip>
using namespace std;
//string and iostream were included already in the baseClass <---------

display::display()
{
}

void display::getList()
{

	int size = 25; 


	cout << setw(4) << "No." << setw(35) << left << "Title" << setw(35) << left << "Publisher" << setw(25) << left << "Author" << setw(15) 
		<< left << "ISBN" << setw(8) << left << "Cost ($)" << setw(8) << left << "MSRP ($)" << setw(5) << left << "Qty" << setw(10) << left << "Type" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < size - 1; i++) 
	{
		cout << setw(4) << left << baseClass::getSerial(i) << setw(35) << left << baseClass::getTitle(i) << setw(35) << left << baseClass::getPublisher(i) << setw(25) 
			<< left << baseClass::getAuthor(i) << setw(15) << left << baseClass::getISBN(i) << setw(8) << left << baseClass::getCost(i) << setw(8) << left << baseClass::getMSRP(i) 
			<< setw(5) << left << baseClass::getQty(i) << setw(10) << left << baseClass::getType(i) << endl;
	}
}


string display::getWholelist() //changed variables to match c++ grammar rules <---------
{// this is not final function, we have to change it a lot
	double totPrice = 0;
	int size = 25; //testing purposes
	
	for (int i = 0; i < size - 1; i++) /* depends from base class (if size = 0 and then ++ : size ? size - 1) */
	{
		tempstr = to_string(baseClass::getSerial(i)) + " " + baseClass::getTitle(i) + " " + baseClass::getPublisher(i) + " " + baseClass::getAuthor(i) + " " +
			" " + baseClass::getISBN(i)/*  + " " + to_string(baseClass::getCost())*/ + " " + to_string(baseClass::getMSRP(i)) + " " + to_string(baseClass::getQty(i)) + " " /*+ baseClass::getTyped()*/
			+ '\n';
		outstr += tempstr;
		totPrice += baseClass::getMSRP(i);
		outstr += "Total MSRP is: " + to_string(totPrice) + '\n';
	}
	return outstr;
}


string display::getRetaillist()
{// this is not final function, we have to change it a lot
	double totPrice = 0;
	int size = 25; //testing purposes

	for (int i = 0; i < size - 1; i++) /* depends from base class (if size = 0 and then ++ : size ? size - 1) */
	{
		tempstr = to_string(baseClass::getSerial(i)) + " " + baseClass::getTitle(i) + " " + baseClass::getPublisher(i) + " " + baseClass::getAuthor(i) + " " +
			" " + baseClass::getISBN(i) + " " + to_string(baseClass::getCost(i))/* + " " + to_string(baseClass::getMSRP()) */ + " " + to_string(baseClass::getQty(i)) + " "/* + baseClass::getTyped()*/
			+ '\n';
		outstr += tempstr;
		totPrice += baseClass::getCost(i);
		outstr += "Total retail price is: " + to_string(totPrice) + '\n';
	}
	return outstr;
}

void display::getQTYlist()
{
	int j = 0;
	int max = 0; // depeds from list (qty,cost,age) sort displaylistis
	int maxpos = 0;
	int x = baseClass::getSizeLine();
	bool *chk = new bool[x];

	for (int i = 0; i < x; i++){
		for (j = 0; j < x; j++){
			if (max <= baseClass::getQty(j) && chk[j] == false){
				max = getQty(j);
				maxpos = j;
			}
		}
			chk[j] = true;
			cout << "(T__T)";
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
