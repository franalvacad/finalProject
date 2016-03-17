#include "inventory.h"
#include <iomanip>
using namespace std;


inventory::inventory()
{
}


inventory::~inventory()
{
//	baseClass::fileMod(max - 1);
}

void inventory::add()
{
	int c = 0;
	max = baseClass::getSizeLine() + 1;
	while (c == 0){
		serialHold = max;
		cin.ignore();
		cout << endl << "Title: ";
		getline(cin, titleHold);
		cout << endl << "Publisher: ";
		getline(cin, publisherHold);
		cout << endl << "Author: ";
		getline(cin, authorHold);
		cout << endl << "ISBN: ";
		cin.ignore();
		cin >> isbnHold;
		cout << endl << "Cost: ";
		cin.ignore();
		cin >> costHold;
		cout << endl << "MSRP: ";
		cin.ignore();
		cin >> msrpHold;
		cout << endl << "Quantity: ";
		cin.ignore();
		cin >> qtyHold;
		cout << endl << "Hardcover or Paperback: ";
		cin.ignore();
		cin >> typeHold;
		cout << "If you want to change anythingpress 0 or 1 if you don't.\n";//change later
		cin.ignore();
			cin >> c;
			if (c == 0){ cout << "You can rewrite your input now\n"; }
	}

	baseClass::setSerial(serialHold, max - 1);
	baseClass::setTitle(titleHold, max - 1);
	baseClass::setPublisher(publisherHold, max - 1);
	baseClass::setAuthor(authorHold, max - 1);
	baseClass::setISBN(isbnHold, max - 1);
	baseClass::setCost(costHold, max - 1);
	baseClass::setMSRP(msrpHold, max - 1);
	baseClass::setQty(qtyHold, max - 1);
	baseClass::setType(typeHold, max - 1);
	baseClass::fileClear();
	baseClass::fileMod(max + 1);
}

void inventory::modify(int x)
{
	cin.ignore();
	cout << endl << "Title: ";
	getline(cin, titleHold);
	cout << endl << "Publisher: ";
	getline(cin, publisherHold);
	cout << endl << "Author: ";
	getline(cin, authorHold);
	cout << endl << "ISBN: ";
	cin.ignore();
	cin >> isbnHold;
	cout << endl << "Cost: ";
	cin.ignore();
	cin >> costHold;
	cout << endl << "MSRP: ";
	cin.ignore();
	cin >> msrpHold;
	cout << endl << "Quantity: ";
	cin.ignore();
	cin >> qtyHold;
	cout << endl << "Hardcover or Paperback: ";
	cin.ignore();
	cin >> typeHold;
	cout << "If you want to change anythingpress 0 or 1 if you don't.\n";//change later
	cin.ignore();
	baseClass::setSerial(serialHold, x);
	baseClass::setTitle(titleHold, x);
	baseClass::setPublisher(publisherHold, x);
	baseClass::setAuthor(authorHold, x);
	baseClass::setISBN(isbnHold, x);
	baseClass::setCost(costHold, x);
	baseClass::setMSRP(msrpHold, x);
	baseClass::setQty(qtyHold, x);
	baseClass::setType(typeHold, x);
	baseClass::fileClear();
	baseClass::fileMod(x);
}

void inventory::del(int x)
{
	baseClass::setTitle("", x);
	baseClass::setPublisher("", x);
	baseClass::setAuthor("", x);
	baseClass::setISBN("", x);
	baseClass::setCost(0, x);
	baseClass::setMSRP(0, x);
	baseClass::setQty(0, x);
	baseClass::setType("", x);
	inventory::setNumOfdeletedBooks(1);							 
	for (int i = baseClass::getSizeLine() - inventory::getNumOfdeletedBooks(); i < baseClass::getSizeLine(); i++){
		baseClass::setSerial(0, i);
	}
	for (int i = 0; i < inventory::getNumOfdeletedBooks(); i++){  
		inventory::setArrOfdelBooks(0, x);                        
	}								                              
	inventory::shift();                                           
	for (int i = 0; i < inventory::getNumOfdeletedBooks(); i++){  
		inventory::setArrOfdelBooks(i, 0);                        
	}                                                             
	inventory::setNumOfdeletedBooks(0);  
	baseClass::fileClear();
	baseClass::fileMod(baseClass::getSizeLine());
}
void inventory::shift(){
	for (int j = 0; j < inventory::getNumOfdeletedBooks(); j++){
		for (int i = inventory::getArrOfdelBooks(j); i < baseClass::getSizeLine(); i++){
			baseClass::setTitle(baseClass::getTitle(i + 1), i);
			baseClass::setPublisher(baseClass::getPublisher(i + 1), i);
			baseClass::setAuthor(baseClass::getAuthor(i + 1), i);
			baseClass::setISBN(baseClass::getISBN(i + 1), i);
			baseClass::setCost(baseClass::getCost(i + 1), i);
			baseClass::setMSRP(baseClass::getMSRP(i + 1), i);
			baseClass::setQty(baseClass::getQty(i + 1), i);
			baseClass::setType(baseClass::getType(i + 1), i);
		}
	}


}
int inventory::search2(int s)
{
	int first = 0,						// First array element
		last = getSizeLine() - 1,			// Last array element
		middle,							// Midpoint of search
		position = -1;					// Position of search value
	bool found = false;					// Flag

	while (!found && first <= last)
	{
		middle = (first + last) / 2;	// Calculate midpoint
		if (getSerial(middle) == s)		// If value is found at mid
		{
			found = true;
			position = middle;
		}
		else if (getSerial(middle) > s)	// If value is in lower half
			last = middle - 1;
		else
			first = middle + 1;			// If value is in upper half

	}

	return position;
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
		cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;// what is it (Andrei)?
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
