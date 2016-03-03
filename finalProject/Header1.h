#include "baseClass.h"
#include "iostream"
#include "string"
using namespace std;
class display : public baseClass{
private:
	string tempstr;
public:
	display();

	accsessors
	string Getline(){
		tempstr = base::getTitle() + " " + base::getPublisher() + " " + base::getAuthor() +
		" " + base::getISBN() + " " + to_string(base::getCost()) + " " + to_string(base::getMSRP()) + " " + to_string(base::getQty()) +
		" " + to_string(base::Serial()) + " " + to_string(base::getYear());
		return tempstring;
		string Getlist()
		}
};