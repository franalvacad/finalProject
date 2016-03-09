#include <iostream>
#include "displayClass.cpp"
using namespace std;

void invent()
{
	display inventory;
	cout << inventory.getList();
}

int searchList(int id[], int c, int search)
{
	int index = 0;   // Used as a subscript to search id
	int pos = -1;  // To record position of search value: -1 means not found

	while (index < c && pos == -1)
	{
		if (id[index] == search) // If the value is found
		{
			pos = index; // Record the value's subscript
		}
		index++; // Go to the next element
	}
	return pos; // Return the position, or -1
}

int main()
{
	invent();

	system("pause>nul");
	return 0;
}
