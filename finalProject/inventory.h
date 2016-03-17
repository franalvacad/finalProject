#pragma once
#include "displayClass.h"
#include "Date.h"
#include <time.h>

class inventory :public display
{
	string titleHold, publisherHold, authorHold, isbnHold, typeHold, dateHold;
	double costHold, msrpHold;
	int qtyHold, serialHold;
	int NumOfdeletedBooks;
	int ArrOfdelBooks[1000];
	int max;
public:
	inventory();
    ~inventory();
	void setNumOfdeletedBooks(int);
	void setDate(int);
	void setArrOfdelBooks(int,int);
	int getNumOfdeletedBooks();
	int getArrOfdelBooks(int);
    void add();
	int search2(int);
    void modify(char,int);
	void del(int);
	int search(string);
	void shift();
};

