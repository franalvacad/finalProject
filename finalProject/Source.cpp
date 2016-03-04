#include <iostream>
#include <fstream>
using namespace std;

//yuiyui

bool countFile(ifstream &inFile, int &asdf)
{
	return (bool)(inFile >> asdf);
}

int main()
{
	ifstream inFile;
	inFile.open("example.txt");
	int asdf, c = 0, i = 0;;
	
	while (countFile(inFile, asdf))
	{
		c++;
	}	
	asdf = 0;

	int *array2 = new int[c];

	inFile.close();
	inFile.open("example.txt");

	while (countFile(inFile, asdf))
	{
		*(array2+i) = asdf;
		i++;
	}

	for (int p = 0; p < c; p++)
		cout << *(array2 + p) << endl;


	delete[] array2;
	system("pause>nul");
	return 0;
}
