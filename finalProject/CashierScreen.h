#ifndef CASHIERSCREEN_H
#define CASHIERSCREEN_H

#include "Cashier.h"

class CashierScreen : public Cashier
{
private:

public:
	CashierScreen();
	
	// Various screens for cashier
	void addItem();
	void removeItem();
	void checkOut();
};



#endif