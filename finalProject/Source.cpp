#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "baseClass.cpp";
using namespace std;

//yuiyui


bool countFile(fstream &inFile, string &asdf)
{
	return (bool)(getline(inFile,asdf));
}

int main()
{
	fstream serial, title, author, pub, isbn, msrp, cost, qty, type;
	int lineNumb = 0;
	string holder;
	
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

	baseClass 


	system("pause>nul");
	return 0;
}
