#include "inventory.h"
#include <iostream>
using namespace std;


inventory::inventory()
{
	//display::getList();
}


inventory::~inventory()
{
}

string inventory::add()
{
	 return "caca";
}

string inventory::modify()
{
	 return "caca";
}

int inventory::search(string term)
{
	string hold;
	bool found;
	for (int c = 0; c < baseClass::getSizeLine(); c++)
	{
		hold = baseClass::getTitle(c);
		cout << hold;
		found = hold.find(term) != string::npos;
		
		if (found)
			cout << "y";
		else if (!found)
			cout << "n";

		cout << endl;
	}

	return 0;

}