#include <iostream>
#include <fstream>
using namespace std;

bool countFile(ifstream &inFile, int &asdf)
{
	return (bool)(inFile >> asdf);
}

int main()
{
	ifstream inFile;
	inFile.open("H:\example.txt");
	int asdf, c = 0, i = 0;;
	
	while (countFile(inFile, asdf))
		c++;

	cout << c;
	
	int *ptrAsdf = new int[c];

	while (countFile(inFile, asdf))



	system("pause>nul");
	return 0;
}
