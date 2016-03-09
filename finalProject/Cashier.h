// Casher Class Specification

#include "baseClass.h"

class Cashier : public baseClass
{
private:
	double const salesTaxRate = 0.0825;

public:
	Cashier() : baseClass()
	{
	}
	int booksPurchased;
	double subtotal;
	double finalSale;
};


