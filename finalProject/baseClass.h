#pragma once
#include <string>
#include <fstream>

using namespace std;

const int SIZE = 1000;

class baseClass
{
private:
	string title[SIZE], publisher[SIZE], author[SIZE], isbn[SIZE], type[SIZE];
	double cost[SIZE], msrp[SIZE];
	int qty[SIZE], serial[SIZE], numOfLines = 0;
public:
	inline baseClass();
	inline ~baseClass();

	inline bool countFile(fstream&);

	inline void setTitle(string x, int c);
	inline void setPublisher(string x, int c);
	inline void setAuthor(string x, int c);
	inline void setISBN(string x, int c);
	inline void setCost(double x, int c);
	inline void setMSRP(double x, int c);
	inline void setQty(int x, int c);
	inline void setSerial(int x, int c);
	inline void setType(string x, int c);

	inline string getTitle(int c);
	inline string getAuthor(int c);
	inline string getISBN(int c);
	inline double getCost(int c);
	inline double getMSRP(int c);
	inline int getQty(int c);
	inline int getSerial(int c);
	inline string getType(int c);
	inline string getPublisher(int c);
	inline int getSizeLine();

};

