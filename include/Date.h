#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>

class Date
{
public:
	Date();
	~Date() = default;

	bool setDate(const std::string & str);
	std::string getDate() const;

	bool modify(int days);

	int operator-(const Date & r) const;

	friend std::ostream & operator<<(std::ostream & out, const Date & date);
	friend std::istream & operator>>(std::istream & in, Date & date);

	static bool setFormat(const std::string & format);
	static std::string getFormat();

private:
	void countTotal();
	void countDate();
	bool yearIsLeap(int year) const;

	int day;
	int month;
	int year;
	// number of days from 01/01/0001
	int total;

	static const int days_in_month[13];        // for not leap year
	static const int days_in_month_leap[13];   // for leap year
	static std::string format;
};

#endif // DATE_H
