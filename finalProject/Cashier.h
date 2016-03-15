#ifndef CASHIER_H
#define CASHIER_H
#include "baseClass.h"
#include "Date.h"
#include "inventory.h"

class Cashier : public baseClass
{
private:
	const double salesTaxRate = 0.0825;

public:
	Cashier();

	double totalPrice();

	double subtotal();

	double finalSale();
};


#endif
