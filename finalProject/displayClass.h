#ifndef DISPLAYCLASS_H
#define DISPLAYCLASS_H
#include "baseClass.h"
#include "iostream"
#include "Date.h"
#include "string"
using namespace std;

class display : public baseClass //display class is child class of baseclass
{
private:
	string tempstr;
	string outstr;
	
public:
	 //Default Constructor
	display();

	//Default Destructor
	~display();

    //Accsessors 
	void getList();
	void getListCustom(int);
	void getShortListCustom(int);
	void getWholelist();
	void getRetaillist();
	void getQTYlist();
	void getCostlist();
	void getAgelist();
	int getMAuthorlength();
	int getMPublisherlength();
	int getMTitlelength();
};
#endif