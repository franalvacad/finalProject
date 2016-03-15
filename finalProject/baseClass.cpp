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
		if (serialFile.is_open() == false){ throw "Error, can't open the serial file"; }
		if (titleFile.is_open() == false){ throw "Error, can't open the title file"; }
		if (authorFile.is_open() == false){ throw "Error, can't open the author file"; }
		if (pubFile.is_open() == false){ throw "Error, can't open the publisher file"; }
		if (isbnFile.is_open() == false){ throw "Error, can't open the isbn file"; }
		if (msrpFile.is_open() == false){ throw "Error, can't open the msrp file"; }
		if (costFile.is_open() == false){ throw "Error, can't open the cost file"; }
		if (qtyFile.is_open() == false){ throw "Error, can't open the qty file"; }
		if (typeFile.is_open() == false){ throw "Error, can't open the type file"; }
		if (dateFile.is_open() == false){ throw "Error, can't open the date file"; }
	
	
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

		dateFile >> dateAdded[c];
	}
}


baseClass::~baseClass()
{
	serialFile.close();
	titleFile.close();
	authorFile.close();
	pubFile.close();
	isbnFile.close();
	msrpFile.close();
	costFile.close();
	qtyFile.close();
	typeFile.close();
	dateFile.close();
}

//sets
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

void baseClass::fileMod(int x) //used for add() function. Essentially copies whatever is in array[x] to the end of file
{
	serialFile << getSerial(x);
	titleFile << getTitle(x);
	pubFile << getPublisher(x);
	authorFile << getAuthor(x);
	isbnFile << getISBN(x);
	costFile << getCost(x);
	msrpFile << getMSRP(x);
	qtyFile << getQty(x);
	typeFile << getType(x);

}

//gets
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
	return dateAdded[c].getDate();
}

int baseClass::getSizeLine()
{
	return numOfLines;
}