#include "baseClass.cpp"
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
	inline string getList();
	inline string getWholelist();
	inline string getRetaillist();
	inline string getQTYlist();

};