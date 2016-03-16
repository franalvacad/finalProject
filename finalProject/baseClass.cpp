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
	return (bool)(getline(inFile, x));
}

baseClass::baseClass()
{
	string holder;
	string temps;
	mainData.open("serial.txt"); //master file
	if (mainData.is_open() == false)
		throw "Error, can't open the serial file";

	while (countFile(mainData)) //counts the number of lines
		numOfLines++;

	mainData.clear();
	mainData.seekg(0);

	cout << numOfLines << endl;
	mainData.clear();
	for (int i = 0; i < numOfLines/10; i + 10){
		getline(mainData, temps); 
		serial[i] = stoi(temps);
			getline(mainData, title[i]);
			getline(mainData, publisher[i]);
			getline(mainData, author[i]);
			mainData >> isbn[i];
			mainData >> cost[i];
			mainData >> msrp[i];
			mainData >> qty[i];
			mainData >> type[i];
			mainData >> date[i];
		}
	}



baseClass::~baseClass()
{
	mainData.close();
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

void baseClass::fileMod() //Essentially copies whatever is in array[x] to the end of file
{
	mainData.clear();
	mainData.seekg(0);

	for (int c = 0; c < SIZE; c++)
	{
		if (getSerial(c) == '\0')
			break;
		
		
	}
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
	return bookNum;
}