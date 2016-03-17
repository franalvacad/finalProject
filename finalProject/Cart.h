#ifndef CART_H
#define CART_H

class Cart
{
private:
	// Structure for list
	struct ListNode
	{
		int value[2];
		struct ListNode *next;
	};

	ListNode *head;
	
public:
	Cart() { head = nullptr; }
	~Cart();

	void addItem(int, int);
	void removeItem(int);
	void displayList() const;
	int Cart::countCart() const;
	void addQty(int, int);
	void removeQty(int, int);
	int getSerial(int) const;
	int getQty(int) const;
	bool itemExist(int) const;
};

/*
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

*/

#endif