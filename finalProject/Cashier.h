#ifndef CASHIER_H
#define CASHIER_H
#include "Date.h"
#include "inventory.h"
#include "Cart.h"
#include "template.h"

class Cashier : public inventory
{
private:
	const double salesTaxRate = 0.0825;

public:

	void addToCart(Cart &t);
	void removeFromCart(Cart &t);
	void viewCart(Cart &t);

	int findBook(int);
	//int searchCart(const Cart(&t), int);

};


#endif
