// Cart Implementation
#include <iostream>
#include "Cart.h"

using namespace std;

Cart::~Cart()
{
	ListNode *nodePtr;			// To traverse the list
	ListNode *nextNode;		// To point to the next node

	// Position nodePtr at the head
	nodePtr = head;

	// While nodePtr is not at the end of the list
	while (nodePtr != nullptr)
	{
		// Save a pointer to the next node
		nextNode = nodePtr->next;

		// Delete the current node
		delete nodePtr;

		// Position nodePtr at the next node
		nodePtr = nextNode;
	}
}

void Cart::addItem(int s, int qty)
{
	ListNode *newNode;		// To point to new node
	ListNode *nodePtr;		// To move through the list

	// Allocate a new node and store num there
	newNode = new ListNode;
	newNode->value[0] = s;		// Item code
	newNode->value[1] = qty;	// Item quantity
	newNode->next = nullptr;

	// If there are no nodes in the list
	// Make newNode the first node
	if (!head)
		head = newNode;
	else
	{
		// Initialize nodePtr to head of list
		nodePtr = head;

		// Find the last node in the list.
		while (nodePtr->next)
			nodePtr = nodePtr->next;

		// Insert newNode as the last node
		nodePtr->next = newNode;
	}
}

void Cart::removeItem(int s)
{
	ListNode *nodePtr;						// To traverse the list
	ListNode *previousNode = nullptr;		// To point to the previous node
	
	// If list is empty, do nothing
	if (!head)
		return;

	// Determine if the first node is the one
	if (head->value[0] == s)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		// Initialize nodePtr to head of list
		nodePtr = head;

		// Skip all nodes whose value member is not equal to num
		while (nodePtr != nullptr && nodePtr->value[0] != s)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If nodePtr is not at the end of the list
		// Link previous node to the node after nodePtr,
		// Then delete nodePtr
		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}

}

void Cart::addQty(int s, int qty)
{
	ListNode *nodePtr;	// To move through the list

	// Position nodePtr at the head of the list
	nodePtr = head;

	// While nodePtr points to a node, traverse the list
	while (nodePtr)
	{
		// If node's serial is equal to input serial
		if (nodePtr->value[0] == s)
			nodePtr->value[1] += qty;

		nodePtr = nodePtr->next;
	}
}

void Cart::removeQty(int s, int qty)
{
	ListNode *nodePtr;	// To move through the list

	// Position nodePtr at the head of the list
	nodePtr = head;

	// While nodePtr points to a node, traverse the list
	while (nodePtr)
	{
		// If node's serial is equal to input serial
		if (nodePtr->value[0] == s)
			nodePtr->value[1] -= qty;

		nodePtr = nodePtr->next;
	}
}

int Cart::getSerial(int position) const
{
	ListNode *nodePtr;	// To move through the list

	// Position nodePtr at the head of the list
	nodePtr = head;

	int counter = 0;

	// While nodePtr points to a node, traverse the list
	while (nodePtr && counter <= position)
	{
		// If conuter is equal to position
		if (counter == position)
			return nodePtr->value[0];

		nodePtr = nodePtr->next;
		counter++;
	}

	// If serial isn't found
	return -1;
}

int Cart::getQty(int s) const
{
	ListNode *nodePtr;	// To move through the list

	// Position nodePtr at the head of the list
	nodePtr = head;

	// While nodePtr points to a node, traverse the list
	while (nodePtr)
	{
		// If node's serial is equal to input serial
		if (nodePtr->value[0] == s)
			return nodePtr->value[1];

		nodePtr = nodePtr->next;
	}

	// If serial isn't found
	return -1;
}

int Cart::countCart() const
{
	ListNode *nodePtr;	// To move through the list

	// Position nodePtr at the head of the list
	nodePtr = head;

	int counter = 0;

	// While nodePtr points to a node, traverse the list
	while (nodePtr)
	{
		counter++;
		nodePtr = nodePtr->next;
	}
	return counter;
}

bool Cart::itemExist(int s) const
{
	ListNode *nodePtr;	// To move through the list

	// Position nodePtr at the head of the list
	nodePtr = head;

	// While nodePtr points to a node, traverse the list
	while (nodePtr)
	{
		// If node's serial is equal to input serial
		if (nodePtr->value[0] == s)
			return true;

		nodePtr = nodePtr->next;
	}

	// If serial isn't found
	return false;
}
