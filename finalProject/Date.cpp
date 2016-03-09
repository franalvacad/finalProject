// Date Class Implementation

#include "Date.h"
#include <string>

using namespace std;

// Constructors
Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}

Date::Date(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}

// Mutators
void Date::setDay(int x)
{
	day = x;
}

void Date::setMonth(int x)
{
	month = x;
}

void Date::setYear(int x)
{
	year = x;
}

// Accesors

int Date::getDay() const
{
	return day;
}

int Date::getMonth() const
{
	return month;
}

int Date::getYear() const
{
	return year;
}

string Date::getDate() const
{
	return to_string(day) + "-" + to_string(month) + "-" + to_string(year);
}