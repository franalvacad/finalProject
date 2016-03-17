// Cart Specification
#ifndef CART_H
#define CART_H

class Cart
{
private:
	// Structure for list
	struct ListNode
	{
		int value[2];			// holds item code and qty for each item in cart
		struct ListNode *next;
	};

	ListNode *head;
	
public:
	Cart() { head = nullptr; }
	~Cart();

	void addItem(int, int);			// Add item to cart
	void removeItem(int);			// Remove item from cart
	void addQty(int, int);			// Add quantity to existing item in cart
	void removeQty(int, int);		// Remove quantity to existing item in cart
	int getSerial(int) const;		// Return serial based on items position in list
	int getQty(int) const;			// Return quantity of item in cart
	int countCart() const;			// Count number of items in cart
	bool itemExist(int) const;		// Check if an item exists in cart
};

#endif