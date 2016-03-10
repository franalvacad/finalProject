//Base Class Implementation

#include "baseClass.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

bool baseClass::countFile(fstream &inFile)
{
	string x;
	return (bool)(inFile>>x);
}

baseClass::baseClass()
{
	fstream serialFile, titleFile, authorFile, pubFile, isbnFile, msrpFile, costFile, qtyFile, typeFile, dateFile;
	string holder;

	serialFile.open("serial.txt"); //master file
	titleFile.open("title.txt");
	authorFile.open("author.txt");
	pubFile.open("pub.txt");
	isbnFile.open("isbn.txt");
	msrpFile.open("msrp.txt");
	costFile.open("cost.txt");
	qtyFile.open("qty.txt");
	typeFile.open("type.txt");
	dateFile.open("date.txt");

	while (countFile(serialFile)) //counts the number of lines
		numOfLines++;

	serialFile.clear();
	serialFile.seekg(0);
	titleFile.clear();
	titleFile.seekg(0);
	authorFile.clear();
	authorFile.seekg(0);
	pubFile.clear();
	pubFile.seekg(0);
	isbnFile.clear();
	isbnFile.seekg(0);
	msrpFile.clear();
	msrpFile.seekg(0);
	costFile.clear();
	costFile.seekg(0);
	qtyFile.clear();
	qtyFile.seekg(0);
	typeFile.clear();
	typeFile.seekg(0);
	dateFile.clear();
	dateFile.seekg(0);

	for (int c = 0; c < numOfLines; c++)
	{
		serialFile >> this->serial[c];

		getline(titleFile, this->title[c]);

		getline(authorFile, this->author[c]);

		getline(pubFile, this->publisher[c]);

		getline(isbnFile, this->isbn[c]);

		msrpFile >> this->msrp[c];

		costFile >> this->cost[c];

		qtyFile >> this->qty[c];

		getline(typeFile, this->type[c]);

		dateFile >> newDate[c];
	}
}


baseClass::~baseClass()
{
}

void baseClass::setTitle(string x, int c)
{
	title[c] = x;
}
void baseClass::setPublisher(string x, int c)
{
	publisher[c] = x;
}
void baseClass::setAuthor(string x, int c)
{
	author[c] = x;
}
void baseClass::setISBN(string x, int c)
{
	isbn[c] = x;
}
void baseClass::setCost(double x, int c)
{
	cost[c] = x;
}
void baseClass::setMSRP(double x, int c)
{
	msrp[c] = x;
}
void baseClass::setQty(int x, int c)
{
	qty[c] = x;;
}
void baseClass::setSerial(int x, int c)
{
	serial[c] = x;
}

void baseClass::setType(string x, int c)
{
	type[c] = x;
}

string baseClass::getType(int c)
{
	return type[c];
}

string baseClass::getTitle(int c)
{
	return title[c];
}
string baseClass::getPublisher(int c)
{
	return publisher[c];
}
string baseClass::getAuthor(int c)
{
	return author[c];
}
string baseClass::getISBN(int c)
{
	return isbn[c];
}
double baseClass::getCost(int c)
{
	return cost[c];
}
double baseClass::getMSRP(int c)
{
	return msrp[c];
}
int baseClass::getQty(int c)
{
	return qty[c];
}
int baseClass::getSerial(int c)
{
	return serial[c];
}

string baseClass::getDate(int c)
{
	return newDate[c].getDate();
}

int baseClass::getSizeLine()
{
	return numOfLines;
}