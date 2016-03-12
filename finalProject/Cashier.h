#pragma once
#include "baseClass.h"
#include "Date.h"

class Cashier : public baseClass
{
private:
	const double salesTaxRate = 0.0825;
	int	booksPurchased;
	double	totalPrice, Total;

public:
	Cashier();
	
	double totalPrice(double price)
	{
		price = price*(1.0 + salesTaxRate);
	}

	int subtract(int booksPurchased)
	{
		booksPurchased = booksPurchased - 1;
	}

	double totalSale(double Sale, double price)
	{
		Sale = Sale + price;
	}

	double totalValue(double Total, double Sale)
	{
		Total = Total - Sale;
	}

};

/*
//The code here is to add later
cout << "Serendipity Book Sellers" << endl << endl;
cout << "Date" << endl << endl;
cout << "Qty     ISBN          Title                  Price      Total" << endl;
______________________________________________________________________________
// while loop here to process the books bought
cout << endl;
cout << "          Subtotal " << price << endl;
cout << "          Tax      " << (price*salesTaxRate) << endl;
cout << "                   " << price*(1.0 + salesTaxRate) << endl << endl;
cout << "Thank You for Shopping at Serendipity!"
*/
