#ifndef CASHIER_H
#define CASHIER_H
#include "Date.h"
#include "inventory.h"
#include "Cart.h"

class Cashier : public inventory
{
private:
	const double salesTaxRate = 0.0825;

public:
	Cashier();

	void addToCart(Cart (&t)[50]);
	void removeFromCart(Cart(&t)[50]);
	void viewCart(Cart(&t)[50]);

	int findBook(int serial);

};


#endif
