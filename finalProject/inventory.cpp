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
	 return "chjhjaca";
}

string inventory::modify()
{
	 return "caca";
}

int inventory::search(string term)
{
	string hold;
	for (int c = 0; c < baseClass::getSizeLine(); c++)
	{
		hold = baseClass::getTitle(c);
		cout << hold;
		
		if (hold.find(term))
			cout << "y";

		cout << endl;
	}

	return 0;

}