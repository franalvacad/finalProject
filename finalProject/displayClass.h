#include "baseClass.h"
#include "iostream"
#include "string"
using namespace std;

class display : public baseClass
{
private:
	string tempstr;
	string outstr;
	
public:
	display();

//	accsessors afsdadg
	void getList();
	string getWholelist();
	string getRetaillist();
	string getQTYlist();

};