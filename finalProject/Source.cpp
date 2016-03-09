#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "baseClass.cpp"
using namespace std;




bool countFile(fstream &inFile, string &asdf)
{
	return (bool)(getline(inFile,asdf));
}

int main()
{
	fstream serial, title, author, pub, isbn, msrp, cost, qty, type;
	int numOfLines = 0, pointLoc = 0;
	string holder;

	string titleData[1000], publisherData[1000], authorData[1000], isbnData[1000], typeData[1000];
	double costData[1000], msrpData[1000];
	int qtyData[1000], serialData[1000];

	baseClass mains[1000];
	
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
		numOfLines++;

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

	for (int c = 0; c < numOfLines; c++)
	{
		serial >> serialData[c];
		mains[c].setSerial(serialData[c]);
		
		getline(title, titleData[c]);
		mains[c].setTitle(titleData[c]);

		getline(author, authorData[c]);
		mains[c].setAuthor(authorData[c]);

		getline(pub, publisherData[c]);
		mains[c].setPublisher(publisherData[c]);

		getline(isbn, isbnData[c]);
		mains[c].setISBN(isbnData[c]);

		msrp >> msrpData[c];
		mains[c].setMSRP(msrpData[c]);

		cost >> costData[c];
		mains[c].setCost(costData[c]);

		qty >> qtyData[c];
		mains[c].setQty(qtyData[c]);

		getline(type, typeData[c]);
		mains[c].setType(typeData[c]);
	}

	for (int i = 0; i < numOfLines; i++)
	{
		cout << mains[i].getSerial() << " " << mains[i].getTitle() << " " << mains[i].getAuthor() << " " << mains[i].getMSRP() << " " << mains[i].getCost() << " " << mains[i].getISBN() << " " << mains[i].getPublisher() << " " << mains[i].getType() << " " << mains[i].getQty() << endl;
	}
	cout << endl;

	system("pause>nul");
	return 0;
}
