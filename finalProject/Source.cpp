#include <iostream>
#include "baseClass.cpp"
using namespace std;


int main()
{
	baseClass mains;
	int size = mains.getSizeLine();
	
	for (int c = 0; c < size; c++)
	{
		mains.getTitle(c);
	}

	system("pause>nul");
	return 0;
}
