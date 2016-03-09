#include"displayClass.h"
#include <string>
#include <iostream>
using namespace std;


inline void display::Getlist()
{


		cout << getSerial() << " " << getTitle() << " " << getPublisher() << " " << getAuthor() << " " << " " 
			 << getISBN() << " " << getType() << " " << getCost(i) << " " << getMSRP(i) << " " << getQty(i) << endl;


}














inline string display::GetWholelist()
{// this is not final function, we have to change it a lot
	double totPrice = 0;
	int size = 25; //testing purposes
	
	for (int i = 0; i < size - 1; i++) /* depends from base class (if size = 0 and then ++ : size ? size - 1) */
	{
		tempstr = to_string(baseClass::getSerial()) + " " + baseClass::getTitle() + " " + baseClass::getPublisher() + " " + baseClass::getAuthor() + " " + to_string(baseClass::getYear()) +
			" " + baseClass::getISBN()/*  + " " + to_string(baseClass::getCost())*/ + " " + to_string(baseClass::getMSRP()) + " " + to_string(baseClass::getQty()) + " " /*+ baseClass::getTyped()*/
			+ '\n';
		outstr += tempstr;
		totPrice += baseClass::getMSRP();
		outstr += "Total MSRP is: " + to_string(totPrice) + '\n';
	}
	return outstr;
}


inline string display::GetRetaillist()
{// this is not final function, we have to change it a lot
	double totPrice = 0;
	int size = 25; //testing purposes

	for (int i = 0; i < size - 1; i++) /* depends from base class (if size = 0 and then ++ : size ? size - 1) */
	{
		tempstr = to_string(baseClass::getSerial()) + " " + baseClass::getTitle() + " " + baseClass::getPublisher() + " " + baseClass::getAuthor() + " " + to_string(baseClass::getYear()) +
			" " + baseClass::getISBN() + " " + to_string(baseClass::getCost())/* + " " + to_string(baseClass::getMSRP()) */ + " " + to_string(baseClass::getQty()) + " "/* + baseClass::getTyped()*/
			+ '\n';
		outstr += tempstr;
		totPrice += baseClass::getCost();
		outstr += "Total retail price is: " + to_string(totPrice) + '\n';
	}
	return outstr;
}


inline string display::GetQTYlist()
{


	return outstr;
}

