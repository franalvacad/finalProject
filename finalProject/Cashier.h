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
	~Cashier();

	void addToCart(Cart (&takeOut)[50]);
	void removeFromCart(Cart(&takeOut)[50]);
	void viewCart(Cart(&takeOut)[50]);

	int findBook(int serial);

};


#endif
