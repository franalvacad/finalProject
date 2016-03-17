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

	void addToCart(Cart &t);
	void removeFromCart(Cart &t);
	void viewCart(Cart &t);
	void finishCheckout(Cart &t);

	double subtotal(Cart &t);
	double tax(double);
	double total(double, double);

	int findBook(int);
};


#endif
