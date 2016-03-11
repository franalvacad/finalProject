// Date Class Specification

#ifndef DATE_H
#define DATE_H

#include <string>
#include <fstream>
#include <ctime>

class Date
{
private:
	int day, month, year;

public:
	Date();
	Date(int, int, int);

	// Mutators
	void setDay(int);
	void setMonth(int);
	void setYear(int);

	// Accesors
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	std::string getDate() const;
	std::string getComputerDate() const;

	// Friend Operator Overloaders
	friend std::fstream& operator>>(std::fstream& in, Date& d);
	friend std::ostream& operator<<(std::ostream& out, Date& d);
};


#endif