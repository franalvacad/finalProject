#include"displayClass.h"
#include <string>
#include <iostream>
using namespace std;


inline string display::Getlist()
{// this is not final function, we have to change it a lot

	int size = 25; //testing purposes


	//outstr = " sadf";
	for (int i = 0; i < size - 1; i++) /* depends from base class (if size = 0 and then ++ : size ? size - 1) */
	{
		tempstr = to_string(baseClass::getSerial(i)) + " " + baseClass::getTitle() + " " + baseClass::getPublisher() + " " + baseClass::getAuthor() + " " +
			" " + baseClass::getISBN()/* + " " + to_string(baseClass::getCost(i)) + " " + to_string(baseClass::getMSRP(i)) */ + " " + to_string(baseClass::getQty()) + " " /*+ baseClass::getType(i)*/
		  +  '\n';
		outstr += tempstr;
	}
	return outstr;
}


inline string display::GetWholelist()
{// this is not final function, we have to change it a lot
	double totPrice = 0;
	int size = 25; //testing purposes
	
	for (int i = 0; i < size - 1; i++) /* depends from base class (if size = 0 and then ++ : size ? size - 1) */
	{
		tempstr = to_string(baseClass::getSerial()) + " " + baseClass::getTitle() + " " + baseClass::getPublisher() + " " + baseClass::getAuthor() + " " +
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
		tempstr = to_string(baseClass::getSerial()) + " " + baseClass::getTitle() + " " + baseClass::getPublisher() + " " + baseClass::getAuthor() + " " +
			" " + baseClass::getISBN() + " " + to_string(baseClass::getCost())/* + " " + to_string(baseClass::getMSRP()) */ + " " + to_string(baseClass::getQty()) + " "/* + baseClass::getTyped()*/
			+ '\n';
		outstr += tempstr;
		totPrice += baseClass::getCost();
		outstr += "Total retail price is: " + to_string(totPrice) + '\n';
	}
	return outstr;
}

//int max = 0; // depeds from list (qty,cost,age) sort displaylistis
//bool *chk = new bool[linenum];
//for(int i = 0; i < lnenum; i++){
//	for (int j = 0; j < lnenum; j++){
//		if (max = < qty[j] && chk[j] == false){
//			max = j;
//			chk[j] = true;
//			cout << "(T__T)";
//			max = 0;
//
//		}
//	}
//}

inline string display::GetQTYlist()
{


	return outstr;
}

