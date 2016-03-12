#pragma once
#include "displayClass.h"
#include <time.h>

class inventory :public display
{
public:
	inventory();
    ~inventory();
   
    string add();
    string modify();
};

