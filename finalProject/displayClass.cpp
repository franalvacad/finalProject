#include"displayClass.h"
#include <iomanip>
using namespace std;
//string and iostream were included already in the baseClass <---------

display::display()
{
}

void display::getList()
{

	int size = 25; //testing purposes


	cout << setw(4) << "No." << setw(35) << "Title" << setw(35) << "Publisher" << setw(25) << "Author" << setw(15) << "ISBN" << setw(8) << "Cost ($)"
		<< setw(8) << "MSRP ($)" << setw(5) << "Qty" << setw(10) << "Type" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < size - 1; i++) /* depends from base class (if size = 0 and then ++ : size ? size - 1) */
	{
		cout << setw(4) << baseClass::getSerial(i) << setw(35) << baseClass::getTitle(i) << setw(35) << baseClass::getPublisher(i) << setw(25) << baseClass::getAuthor(i) << setw(15) <<
			baseClass::getISBN(i) << setw(8) << baseClass::getCost(i) << setw(8) << baseClass::getMSRP(i) << setw(5) << baseClass::getQty(i) << setw(10) << baseClass::getType(i) << endl;
		outstr += tempstr;
	}
	//return outstr;
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


string display::getQTYlist()
{
	int max = 0; // depeds from list (qty,cost,age) sort displaylistis
	int x = baseClass::getSizeLine();
	bool *chk = new bool[x];

	for (int i = 0; i < x; i++){
		for (int j = 0; j < x; j++){
			if (max <= baseClass::getQty(j) && chk[j] == false){
				max = j;
				chk[j] = true;
				cout << "(T__T)";
				max = 0;

			}
		}
	}
	return "test";
}

string display::getCostlist()
{
	int max = 0; // depeds from list (qty,cost,age) sort displaylistis
	int x = baseClass::getSizeLine();
	bool *chk = new bool[x];

	for (int i = 0; i < x; i++){
		for (int j = 0; j < x; j++){
			if (max <= baseClass::getQty(j) && chk[j] == false){
				max = j;
				chk[j] = true;
				cout << "(T__T)";
				max = 0;

			}
		}
	}
	return "hs";
}
//string display::getQTYlist()
//{
//	int max = 0; // depeds from list (qty,cost,age) sort displaylistis
//	int x = baseClass::getSizeLine();
//	bool *chk = new bool[x];
//
//	for (int i = 0; i < x; i++){
//		for (int j = 0; j < x; j++){
//			if (max <= baseClass::getQty(j) && chk[j] == false){
//				max = j;
//				chk[j] = true;
//				cout << "(T__T)";
//				max = 0;
//
//			}
//		}
//	}
//}
