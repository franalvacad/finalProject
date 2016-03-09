// Date Class Implementation

#include "Date.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

// Constructors
Date::Date()
{
	day = 1;
	month = 1;
	year = 2000;
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

void Date::importDate(stringstream &iss)
{
	int token;

	int i = 0;

	// Import date into array
	while (iss >> token)
	{
		cout << token << endl;
		dateArray[i++] = token;
	}


	// Import dateArray into date variables
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
			day = dateArray[i];
		else if (i == 1)
			day = dateArray[i];
		else
			day = dateArray[i];
	}

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