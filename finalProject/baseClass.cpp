#include "baseClass.h"

inline baseClass::baseClass()
{
}

inline baseClass::baseClass(string, string, string, string, string, double, double, int, int)
{
}


inline baseClass::~baseClass()
{
}

inline void baseClass::setTitle(string x)
{
	title = x;
}
inline void baseClass::setPublisher(string x)
{
	publisher = x;
}
inline void baseClass::setAuthor(string x)
{
	author = x;
}
inline void baseClass::setISBN(string x)
{
	isbn = x;
}
inline void baseClass::setCost(double x)
{
	cost = x;
}
inline void baseClass::setMSRP(double x)
{
	msrp = x;
}
inline void baseClass::setQty(int x)
{
	qty = x;;
}
inline void baseClass::setSerial(int x)
{
	serial = x;
}

inline void baseClass::setType(string x)
{
	type = x;
}

inline string baseClass::getType()
{
	return type;
}

inline string baseClass::getTitle()
{
	return title;
}
inline string baseClass::getPublisher()
{
	return publisher;
}
inline string baseClass::getAuthor()
{
	return author;
}
inline string baseClass::getISBN()
{
	return isbn;
}
inline double baseClass::getCost()
{
	return cost;
}
inline double baseClass::getMSRP()
{
	return msrp;
}
inline int baseClass::getQty()
{
	return qty;
}
inline int baseClass::getSerial()
{
	return serial;
}
