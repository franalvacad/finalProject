//Base Class Implementation

#include "baseClass.h"

baseClass::baseClass()
{
}

baseClass::baseClass(string, string, string, string, string, double, double, int, int)
{
}


baseClass::~baseClass()
{
}

void baseClass::setTitle(string x)
{
	title = x;
}
void baseClass::setPublisher(string x)
{
	publisher = x;
}
void baseClass::setAuthor(string x)
{
	author = x;
}
void baseClass::setISBN(string x)
{
	isbn = x;
}
void baseClass::setCost(double x)
{
	cost = x;
}
void baseClass::setMSRP(double x)
{
	msrp = x;
}
void baseClass::setQty(int x)
{
	qty = x;;
}
void baseClass::setSerial(int x)
{
	serial = x;
}
void baseClass::setYear(int x)
{
	year = x;
}

void baseClass::setType(string x)
{
	type = x;
}

string baseClass::getTitle()
{
	return title;
}
string baseClass::getPublisher()
{
	return publisher;
}
string baseClass::getAuthor()
{
	return author;
}
string baseClass::getISBN()
{
	return isbn;
}
double baseClass::getCost()
{
	return cost;
}
double baseClass::getMSRP()
{
	return msrp;
}
int baseClass::getQty()
{
	return qty;
}
int baseClass::getSerial()
{
	return serial;
}
int baseClass::getYear()
{
	return year;
}