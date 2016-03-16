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
	string temp;
	mainData.open("serial.txt"); //master file
	if (mainData.is_open() == false)
		throw "Error, can't open the serial file";

	while (countFile(mainData)) //counts the number of lines
		numOfLines++;

	mainData.clear();
	mainData.seekg(0);

	mainData.clear();
	for (int i = 0; i < numOfLines/10; i++){
		getline(mainData, temp); 
		serial[i] = stoi(temp);
		getline(mainData, title[i]);
		getline(mainData, publisher[i]);
		getline(mainData, author[i]);
		getline(mainData, isbn[i]);
		getline(mainData, temp);
		cost[i] = stod(temp);
		getline(mainData, temp);
		msrp[i] = stod(temp);
		getline(mainData, temp);
		qty[i] = stoi(temp);
		getline(mainData, type[i]);
		mainData >> dateAdded[i];
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

void baseClass::fileMod(int x) //Essentially copies whatever is in array to the end of file. Var x is max value
{
	Date time;
	mainData.close();
	mainData.open("serial.txt", fstream::trunc);
	mainData.clear();
	mainData.seekg(0);
	for (int c = 0; c < x; c++)
	{	
		mainData << getSerial(c) << endl
			<< getTitle(c) << endl
			<< getPublisher(c) << endl
			<< getAuthor(c) << endl
			<< getISBN(c) << endl
			<< getCost(c) << endl
			<< getMSRP(c) << endl
			<< getQty(c) << endl
			<< getType(c) << endl
			<< getDate(c) << endl;
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
	return 1 + numOfLines/10;
}