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