#ifndef DATE_H
#define DATE_H
#include <string>
#include <fstream>
#include <ctime>

class Date //Date class is independant
{
private:
	int day, month, year;

public:
	//Default Costructor
	Date();
	//Costructor #2
	Date(int, int, int);

	//Mutators
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	void setDate(int, int, int);

	//Accessors
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