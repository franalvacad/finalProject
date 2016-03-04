#include "baseClass.h"

bool countFile(ifstream &inFile, int &asdf)
{
	return (bool)(inFile >> asdf);
}


baseClass::baseClass()
{

	inFile.open("c:/example.txt");
	int c = 0, i = 0;;

	while (countFile(inFile, asdf))
	{
		c++;
	}
	asdf = 0;

	int *array2 = new int[c];

	inFile.close();
	inFile.open("c:/example.txt");

	while (countFile(inFile, asdf))
	{
		*(array2 + i) = asdf;
		i++;
	}

	for (int p = 0; p < c; p++)
		cout << *(array2 + p) << endl;


	delete[] array2;
}

baseClass::baseClass(string, string, string, string, string, double, double, int, int)
{
}


baseClass::~baseClass()
{
}

void setTitle(string x);
void setPublisher(string x);
void setAuthor(string x);
void setISBN(string x);
void setCost(double x);
void setMSRP(double x);
void setQty(int x);
void setSerial(int x);
void setYear(int x);

string getTitle();
string getPublisher();
string getAuthor();
string getISBN();
double getCost();
double getMSRP();
int getQty();
int getSerial();
int getYear();