#include "Cart.h"

// Constructor
Cart::Cart()
{}

// Accessors

int Cart::getItemCode() const
{
	return itemCode;
}

int Cart::getQty() const
{
	return qty;
}

// Mutators

void Cart::setItemCode(int x)
{
	itemCode = x;
}

void Cart::setQty(int x)
{
	qty = x;
}