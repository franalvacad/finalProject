#include "baseClass.h"
#include "iostream"
#include "string"
using namespace std;
class display : public baseClass{
private:
	string tempstr;
	string outstr;
public:
	display();

//	accsessors afsdadg
	inline void Getlist();
	inline string GetWholelist();
	inline string GetRetaillist();
	inline string GetQTYlist();


};