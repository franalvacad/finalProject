#include <iostream>
#include "displayClass.cpp"
using namespace std;

//fyu

int main()
{
	baseClass mains;
	int count = mains.getSizeLine();

	for (int c = 0; c < count; c++)
	{
		cout << mains.getTitle(c) << " by " << mains.getAuthor(c) << endl;
	}


	system("pause>nul");
	return 0;
}
