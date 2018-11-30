#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>

class Date
{
public:
	Date() = delete;
	Date(const std::string & str);
	~Date() = default;

	friend std::ostream & operator<<(std::ostream & out, const Date & date);

private:
	int day;
	int month;
	int year;
};

#endif // DATE_H
