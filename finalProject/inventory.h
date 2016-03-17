#pragma once
#include "displayClass.h"
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
	void setArrOfdelBooks(int,int);
	int getNumOfdeletedBooks();
	int getArrOfdelBooks(int);
    void add();
	int search2(int);
    void modify(int);
	void del(int);
	//int search(string);
	void shift();
};

