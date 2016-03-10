#include <iostream>
#include "baseClass.cpp"
#in
using namespace std;


int main()
{
	baseClass mains;
	int size = mains.getSizeLine();
	
	for (int c = 0; c < size; c++)
	{
		cout << mains.getSerial(c) << endl;
	}

	system("pause>nul");
	return 0;
}
