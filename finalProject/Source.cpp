#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "baseClass.cpp";
using namespace std;




bool countFile(fstream &inFile, string &asdf)
{
	return (bool)(getline(inFile,asdf));
}

int main()
{
	fstream serial, title, author, pub, isbn, msrp, cost, qty, type;
	int lineNumb = 0;
	string holder;

	string titleHold, publisherHold, authorHold, isbnHold, typeHold;
	double costHold, msrpHold;
	int qtyHold, serialHold = 0 , yearHold;
	
	serial.open("serial.txt"); //master file
	title.open("title.txt");
	author.open("author.txt");
	pub.open("pub.txt");
	isbn.open("isbn.txt");
	msrp.open("msrp.txt");
	cost.open("cost.txt");
	qty.open("qty.txt");
	type.open("type.txt");

	while (countFile(serial, holder)) //counts the number of lines
		lineNumb++;

	cout << lineNumb;

	baseClass *all = new baseClass[lineNumb]; //array with everything basically

	serial.clear();
	serial.seekg(0);
	title.clear();
	title.seekg(0);
	author.clear();
	author.seekg(0);
	pub.clear();
	pub.seekg(0);
	isbn.clear();
	isbn.seekg(0);
	msrp.clear();
	msrp.seekg(0);
	cost.clear();
	cost.seekg(0);
	qty.clear();
	qty.seekg(0);
	type.clear();
	type.seekg(0);

	serial << serialHold;
	cout << serialHold;

	system("pause>nul");
	return 0;
}
