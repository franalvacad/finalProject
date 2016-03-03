#include "baseClass.h"
#include "iostream"
#include "string"
using namespace std;
class display : public baseClass{
private:
	string tempstr;
public:
	display();

//	accsessors
	string Getline()
	{
		tempstr = baseClass::getTitle() + " " + baseClass::getPublisher() + " " + baseClass::getAuthor() +
		" " + baseClass::getISBN() + " " + to_string(baseClass::getCost()) + " " + to_string(baseClass::getMSRP()) + " " + to_string(baseClass::getQty()) +
		" " + to_string(baseClass::Serial()) + " " + to_string(baseClass::getYear());
		return tempstr;
		string Getlist()
	}
};