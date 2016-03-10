#pragma once
#include "displayClass.h"
class inventory :
	public display
{
public:
	inventory();
	~inventory();

	int binSearch(inventory, int);
	int modify;
	int add;
};

