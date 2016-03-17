// Inventory Class Implementation
#include "inventory.h"
#include <iomanip>
using namespace std;

//Default Constructor
inventory::inventory()
{
}

//Default Destructor
inventory::~inventory()
{
}

void inventory::setDate(int i) //Used to add current date from the machine
{
	Date todaysDate;
	string temp, tempd, d, y, x;
	temp = todaysDate.getComputerDate();
	tempd = temp.substr(temp.find("-") + 1, temp.length());
	d = temp.substr(0, temp.find("-"));
	y = tempd.substr(0, temp.find("-") + 1);
	x = tempd.substr(tempd.find("-") + 1, tempd.length());
	dateAdded[i] = { stoi(d), stoi(y), stoi(x) };
}

void inventory::add() //Used to add new book to inventory
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
		cout << "Press 1 to confirm changes. Else, press 0.\n";//change later
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
	inventory::setDate(max - 1);
	baseClass::fileClear();
	baseClass::fileMod(max + 1);
}

void inventory::modify(char y, int x) //Used to make changes to book in inventory
{
	string name = "";
	int number = 0;
	int d, m, ya;
	double price = 0;

	//Switch statemnet allow accesses to users choice of field to modify
	switch (y)
	{
	default:
		cout << "Let's try again" << endl;
		break;
	case 'T':
		cout << "Enter the new title: "; //Program ignores first field (item code) which is permanent
		cin.ignore();
		getline(cin, name);
		baseClass::setTitle(name, x - 1);
		break;
	case 'P':
		cout << "Enter the new publisher: ";
		cin.ignore();
		getline(cin, name);
		baseClass::setPublisher(name, x - 1);
		break;
	case 'A':
		cout << "Enter the new author: ";
		cin.ignore();
		getline(cin, name);
		baseClass::setAuthor(name, x - 1);
		break;
	case 'I':
		cout << "Enter the new ISBN: ";
		cin.ignore();
		getline(cin, name);
		baseClass::setISBN(name, x - 1);
		break;
	case 'C':
		cout << "Enter the new cost: ";
		cin >> price;
		baseClass::setCost(price, x - 1);
		break;
	case 'M':
		cout << "Enter the new MSRP: ";
		cin >> price;
		baseClass::setMSRP(price, x - 1);
		break;
	case 'Q':
		cout << "Enter the new quantity: ";
		cin >> number;
		baseClass::setQty(number, x - 1);
		break;
	case 'E':
		cout << "Enter the new type: ";
		cin.ignore();
		getline(cin, name);
		baseClass::setType(name, x - 1);
		break;
	}
}

void inventory::del(int x) //Used to make remove a book from inventory
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
void inventory::shift() //Removes empty spaces in the array after item has been removed
{
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
int inventory::search2(int s) //Searches through serial numbers and returns position in array
{
	int first = 0,						// First array element
		last = getSizeLine() - 1,		// Last array element
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
int inventory::search(string term) //Searches through book titles and returns position in array
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

//Mutators
void inventory::setNumOfdeletedBooks(int n){ NumOfdeletedBooks = n; }
void inventory::setArrOfdelBooks(int i, int el){ ArrOfdelBooks[i] = el; }

//Accessors
int inventory::getNumOfdeletedBooks(){ return NumOfdeletedBooks; }
int inventory::getArrOfdelBooks(int i){ return ArrOfdelBooks[i]; }
