#ifndef CASHIER_H
#define CASHIER_H
#include "baseClass.h"
#include "Date.h"
#include "inventory.h"
#include "Cart.h"

class Cashier : public baseClass
{
private:
	const double salesTaxRate = 0.0825;

public:
	Cashier();
	Cashier(Cart(&takeOut)[50]);

	void addToCart(Cart (&t)[50]);
	void removeFromCart(Cart(&t)[50]);
	void viewCart(Cart(&t)[50]);

	int findBook(int serial);

};


#endif
