#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>

class Date
{
public:
	Date();
	bool setDate(const std::string & str);
	~Date() = default;

	friend std::ostream & operator<<(std::ostream & out, const Date & date);

	// move to private: : : : : : :  : : : :   : : : : : : :
	int countTotal(int d, int m, int y);
	bool yearIsLeap(int year) const;
	std::string countDate();

	static bool setFormat(const std::string & format);

	static const int days_in_month[13];	// for not leap year
	static const int days_in_month_leap[13];	// for leap year
	static std::string format;

private:
	int day;
	int month;
	int year;
	int total;

};

#endif // DATE_H
