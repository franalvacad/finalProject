#include"displayClass.h"
#include "Date.h"
using namespace std;
//string and iostream were included already in the baseClass <---------

display::display()
{
}

string display::getList()
{// this is not final function, we have to change it a lot

	int size = baseClass::getSizeLine(); //here, use the official one :D <--------


	//outstr = " sadf";
	for (int i = 0; i < size - 1; i++) /* depends from base class (if size = 0 and then ++ : size ? size - 1) */
	{
		tempstr = to_string(baseClass::getSerial(i)) + " " + baseClass::getTitle(i) + " " + baseClass::getPublisher(i) + " " + baseClass::getAuthor(i) + " " +
			" " + baseClass::getISBN(i)/* + " " + to_string(baseClass::getCost(i)) + " " + to_string(baseClass::getMSRP(i)) */ + " " + to_string(baseClass::getQty(i)) + " " /*+ baseClass::getType(i)*/
		  +  '\n';
		outstr += tempstr;
	}
	return outstr;
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
	int max = 0; // depeds from list (qty,cost,age) sort displaylistis
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
			if (maxy <= newDate[j].getYear() && maxm <= newDate[j].getMonth() && maxd <= newDate[j].getDay() && chk[j] == false){
				maxy = newDate[j].getYear();
				maxm = newDate[j].getMonth();
				maxd <= newDate[j].getDay();
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
