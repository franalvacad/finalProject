// Casher Class Specification
#pragma once
#include "baseClass.h"

class Cashier: public baseClass
{
private:
	const double salesTaxRate=0.0825;
	int	booksPurchased;
	double totalPrice;

};

