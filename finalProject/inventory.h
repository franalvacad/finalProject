#pragma once
#include "displayClass.h"
#include <time.h>

class inventory :public display
{
	string titleHold, publisherHold, authorHold, isbnHold, typeHold;
	double costHold, msrpHold;
	int qtyHold, serialHold;

public:
	inventory();
    ~inventory();
   
    void add();
    void modify(int);
	void del(int);
	int search(string);
};

