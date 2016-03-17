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
	int countCart() const;
	void addQty(int, int);
	void removeQty(int, int);
	int getSerial(int) const;
	int getQty(int) const;

	bool itemExist(int) const;
};

#endif