#include "baseClass.h"
using namespace std;

//counts lines. can also be used to see if file works
inline bool baseClass::countFile(fstream &inFile)
{
	string x;
	return (bool)(inFile>>x);
}

//constructors
inline baseClass::baseClass()
{
	serialFile.open("serial.txt"); //master file
	titleFile.open("title.txt");//titles here
	authorFile.open("author.txt");//authors here
	pubFile.open("pub.txt");//publishers here
	isbnFile.open("isbn.txt");//isbn here
	msrpFile.open("msrp.txt");//msrp here
	costFile.open("cost.txt");//cost here
	qtyFile.open("qty.txt");//quantity here
	typeFile.open("type.txt");//types here

	while (countFile(serialFile)) //counts the number of lines
		numOfLines++;

	serialFile.clear(); //clear error flags
	serialFile.seekg(0);//move seeker to begining of file
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

	for (int c = 0; c < numOfLines; c++) //copy file contents to variables array
	{
		serialFile >> baseClass::serial[c];

		getline(titleFile, baseClass::title[c]);

		getline(authorFile, baseClass::author[c]);

		getline(pubFile, baseClass::publisher[c]);

		getline(isbnFile, baseClass::isbn[c]);

		msrpFile >> baseClass::msrp[c];

		costFile >> baseClass::cost[c];

		qtyFile >> baseClass::qty[c];

		getline(typeFile, baseClass::type[c]);
	}
}


inline baseClass::~baseClass()
{
}


//sets
inline void baseClass::setTitle(string x, int c) //MAKE SURE TO ALWAYS PUT THE SERIAL NUMBER!!!!
{
	title[c] = x;
}
inline void baseClass::setPublisher(string x, int c)
{
	publisher[c] = x;
}
inline void baseClass::setAuthor(string x, int c)
{
	author[c] = x;
}
inline void baseClass::setISBN(string x, int c)
{
	isbn[c] = x;
}
inline void baseClass::setCost(double x, int c)
{
	cost[c] = x;
}
inline void baseClass::setMSRP(double x, int c)
{
	msrp[c] = x;
}
inline void baseClass::setQty(int x, int c)
{
	qty[c] = x;;
}
inline void baseClass::setSerial(int x, int c)
{
	serial[c] = x;
}

inline void baseClass::setType(string x, int c)
{
	type[c] = x;
}


//gets
inline string baseClass::getType(int c)
{
	return type[c];
}

inline string baseClass::getTitle(int c)
{
	return title[c];
}
inline string baseClass::getPublisher(int c)
{
	return publisher[c];
}
inline string baseClass::getAuthor(int c)
{
	return author[c];
}
inline string baseClass::getISBN(int c)
{
	return isbn[c];
}
inline double baseClass::getCost(int c)
{
	return cost[c];
}
inline double baseClass::getMSRP(int c)
{
	return msrp[c];
}
inline int baseClass::getQty(int c)
{
	return qty[c];
}
inline int baseClass::getSerial(int c)
{
	return serial[c];
}

inline int baseClass::getSizeLine() //returns size of file
{
	return numOfLines;
}
