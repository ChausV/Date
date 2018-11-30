#include "Date.h"
#include <sstream>

Date::Date(const std::string & str)
{
	std::stringstream ss(str);
	ss >> day >> month >> year;
}

std::ostream & operator<<(std::ostream & out, const Date & date)
{
	out << date.day << " " << date.month << " " << date.year;
	return out;
}
