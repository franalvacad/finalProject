// Date Class Specification

#ifndef DATE_H
#define DATE_H

#include <string>
#include <fstream>

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
	void importDate(std::fstream&);

	// Accesors
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	std::string getDate() const;
};


#endif