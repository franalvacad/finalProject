#ifndef CART_H
#define CART_H

class Cart
{
private:
	int itemCode = 0;
	int qty;
	
public:
	Cart();

	// Accessors
	int getItemCode() const;
	int getQty() const;

	// Mutators
	void setItemCode(int);
	void setQty(int);
};

#endif