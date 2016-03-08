#pragma once
#include <string>
using namespace std;

class baseClass
{
	string title, publisher, author, isbn, type;
	double cost, msrp;
	int qty, serial, year;
public:
	inline baseClass();
	inline baseClass(string, string, string, string, string, double, double, int, int);
	inline ~baseClass();

	bool countFile(ifstream &inFile, int &asdf);

	inline void setTitle(string x);
	inline void setPublisher(string x);
	inline void setAuthor(string x);
	inline void setISBN(string x);
	inline void setCost(double x);
	inline void setMSRP(double x);
	inline void setQty(int x);
	inline void setSerial(int x);
	inline void setYear(int x);
	inline void setType(string x);

	inline string getTitle();
	inline string getPublisher();
	inline string getAuthor();
	inline string getISBN();
	inline double getCost();
	inline double getMSRP();
	inline int getQty();
	inline int getSerial();
	inline int getYear();
	inline string getType();
};

