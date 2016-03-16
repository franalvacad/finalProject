#include "inventory.h"
#include <iostream>
#include <iomanip>
using namespace std;


inventory::inventory()
{
}


inventory::~inventory()
{
	baseClass::fileMod();
}

void inventory::add()
{
	int nowSize = baseClass::getSizeLine() + 1;

	cout << "Serial: ";
	cin >> serialHold;
	cout << endl << "Title: ";
	cin.ignore();
	getline(cin, titleHold);
	cout << endl << "Publisher: ";
	cin.ignore();
	getline(cin, publisherHold);
	cout << endl << "Author: ";
	cin.ignore();
	getline(cin, authorHold);
	cout << endl << "ISBN: ";
	cin >> isbnHold;
	cout << endl << "Cost: ";
	cin >> costHold;
	cout << endl << "MSRP: ";
	cin >> msrpHold;
	cout << endl << "Quantity: ";
	cin >> qtyHold;
	cout << endl << "Hardcover or Paperback: ";
	cin >> typeHold;
	
	baseClass::setSerial(serialHold, nowSize);
	baseClass::setTitle(titleHold, nowSize); 
	baseClass::setPublisher(publisherHold, nowSize); 
	baseClass::setAuthor(authorHold, nowSize); 
	baseClass::setISBN(isbnHold, nowSize); 
	baseClass::setCost(costHold, nowSize); 
	baseClass::setMSRP(msrpHold, nowSize);
	baseClass::setQty(qtyHold, nowSize); 
	baseClass::setType(typeHold, nowSize);

}

void inventory::modify(int x)
{
}

void inventory::del(int x)
{
}
void inventory::shift(){
	for (int j = 0; j < inventory::getNumOfdeletedBooks(); j++){
		for (int i = inventory::getArrOfdelBooks(j); i < 1000; i++){
			baseClass::setTitle(baseClass::getTitle(i + 1), i);
			baseClass::setPublisher(baseClass::getPublisher(i + 1), i);
			baseClass::setAuthor(baseClass::getAuthor(i + 1), i);
			baseClass::setISBN(baseClass::getISBN(i + 1), i);
			baseClass::setCost(baseClass::getCost(i + 1), i);
			baseClass::setMSRP(baseClass::getMSRP(i + 1), i);
			baseClass::setQty(baseClass::getQty(i + 1), i);
			baseClass::setSerial(baseClass::getSerial(i + 1), i);
			baseClass::setType(baseClass::getType(i + 1), i);
		}
	}


}
int inventory::search(string term)
{
	string hold;
	bool found, vty = true;

	for (int c = 0; c < baseClass::getSizeLine(); c++)
	{
		hold = baseClass::getTitle(c);
		found = hold.find(term) != string::npos;
		
		if (found)
		{
			display::getListCustom(c);
			vty = false;
		}
	}
	
	if (!vty)
	{
		cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << setw(4) << "No." << setw(35) << left << "Title" << setw(35) << left << "Publisher" << setw(25) << left << "Author" << setw(15)
			<< left << "ISBN" << setw(8) << left << "Cost($) " << setw(8) << left << "MSRP($) " << setw(5) << left << "Qty" << setw(10) << left
			<< "Type" << setw(8) << left << "Date Added" << endl;
	}
	return 0;

}
void inventory::setNumOfdeletedBooks(int n){ NumOfdeletedBooks = n; }
void inventory::setArrOfdelBooks(int i, int el){ ArrOfdelBooks[i] = el; }
int inventory::getNumOfdeletedBooks(){ return NumOfdeletedBooks; }
int inventory::getArrOfdelBooks(int i){ return ArrOfdelBooks[i]; }
