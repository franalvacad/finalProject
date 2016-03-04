#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

//yuiyui


bool countFile(ifstream &inFile, string &asdf)
{
	return (bool)(getline(inFile,asdf));
}

int main()
{
	ifstream inFile;
	inFile.open("c:/Books.csv");
	int c = 0, i = 0, l = 0, w = 0;
	string lines, holder;
	char wordHold[5000];

	while (countFile(inFile, lines))
	{
		c++;
	}
	lines = "";

	string *array2 = new string[c];

	inFile.close();
	inFile.open("c:/Books.csv");

	while (countFile(inFile, lines))
	{
		*(array2 + i) = lines;
		i++;
	}


	for (int t = 0; t < c; t++)
	{
		l = 0;
		holder = *(array2 + t);
		
		while (holder[l] != ',')
		{
			w++;
			l++;
		}
	}

	string *inHere = new string[w];

	for (int y = 0; y < c; y++)
	{
		l = 0;
		holder = *(array2 + y);

		while (holder[l] != ',')
		{
			wordHold[l] = holder[l];
			l++;
		}
		wordHold[l + 1] = '/0';


		holder.assign(wordHold);

		*(inHere + y) = holder;
	}

	//for (int o = 0; o < c; o++)
	//	cout << *(inHere + o) << endl;

	delete[] array2;
	system("pause>nul");
	return 0;
}
