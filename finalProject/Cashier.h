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

	void addToCart(Cart (&takeOut)[50]);
	void removeFromCart(Cart(&takeOut)[50]);
	void viewCart(Cart(&takeOut)[50]);

	int findBook(int serial);

};


#endif
