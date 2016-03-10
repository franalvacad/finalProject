#ifndef BASECLASS_H
#define BASECLASS_H

#include "Date.h"
#include <string>
#include <fstream>

using namespace std;

const int SIZE = 1000;

class baseClass : public Date
{
private:
	string title[SIZE], publisher[SIZE], author[SIZE], isbn[SIZE], type[SIZE];
	fstream serialFile, titleFile, authorFile, pubFile, isbnFile, msrpFile, costFile, qtyFile, typeFile; //make file variables
	double cost[SIZE], msrp[SIZE];
	int qty[SIZE], serial[SIZE], numOfLines = 0;
	protected:
	Date newDate[SIZE];
public:
	baseClass();
	~baseClass();

	bool countFile(fstream&);

	void setTitle(string x, int c);
	void setPublisher(string x, int c);
	void setAuthor(string x, int c);
	void setISBN(string x, int c);
	void setCost(double x, int c);
	void setMSRP(double x, int c);
	void setQty(int x, int c);
	void setSerial(int x, int c);
	void setType(string x, int c);

	string getTitle(int c);
	string getAuthor(int c);
	string getISBN(int c);
	double getCost(int c);
	double getMSRP(int c);
	int getQty(int c);
	int getSerial(int c);
	string getType(int c);
	string getPublisher(int c);
	string getDate(int c);
	int getSizeLine();


};

#endif
