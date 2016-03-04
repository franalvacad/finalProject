#include"displayClass.h"
#include <string>
#include <iostream>
using namespace std;


inline string display::Getlist()
{



	tempstr = baseClass::getTitle() + " " + baseClass::getPublisher() + " " + baseClass::getAuthor() +
		" " + baseClass::getISBN() + " " + to_string(baseClass::getCost()) + " " + to_string(baseClass::getMSRP()) + " " + to_string(baseClass::getQty()) +
		" " + to_string(baseClass::getSerial()) + " " + to_string(baseClass::getYear());
	return tempstr; }