// Date Class Implementation

#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
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

string Date::getComputerDate() const
{
	time_t now = time(0);
	tm *tPtr = localtime(&now);
	return to_string(tPtr->tm_mday) + "-" + to_string(tPtr->tm_mon) + "-" + to_string(tPtr->tm_year);
}

// Operator >> overloader for inserting date
fstream& operator>>(fstream& in, Date& d)
{
	int dayPart,			// Placeholder for parts of date
		dateArray[3];		// Holds parts of date
	int x = 0;				// Steps through dateArray

	stringstream iss;		// Placeholder for getline data
	string line;

	// Insert line into iss
	getline(in, line);
	iss << line;

	// Extract iss for date into array
	while (iss >> dayPart)
	{
		dateArray[x++] = dayPart;
	}

	// Import dateArray into date variables
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
			d.day = dateArray[i];
		else if (i == 1)
			d.month = dateArray[i];
		else
			d.year = dateArray[i];
	}

	return in;
}

// Operator << overloader for cout date
ostream& operator<<(ostream& out, Date& d)
{
	out << to_string(d.day) + "-" + to_string(d.month) + "-" + to_string(d.year);
	return out;
}