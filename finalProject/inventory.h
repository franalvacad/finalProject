#ifndef INVENTORY_H
#define INVENTORY_H
#include "displayClass.h"
#include "Date.h"
#include <time.h>

class inventory :public display //inventory class is child class of display
{
	//Variables ending with hold are temporarily holding data 
	string titleHold, publisherHold, authorHold, isbnHold, typeHold, dateHold;
	double costHold, msrpHold;
	int qtyHold, serialHold;
	int NumOfdeletedBooks;
	int ArrOfdelBooks[1000];
	int max;
public:
	//Default Constructor
	inventory();
    
	//Default Destructor
	~inventory();

	//Mutators
	void setNumOfdeletedBooks(int);
	void setDate(int);
	void setArrOfdelBooks(int,int);

	//Accessors
	int getNumOfdeletedBooks();
	int getArrOfdelBooks(int);
    void add();

	//Public Functions
	int search2(int);
    void modify(char,int);
	void del(int);
	int search(string);
	void shift();
};
#endif
