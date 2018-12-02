#include "Date.h"
#include <sstream>

Date::Date() : day(0), month(0), year(0), total(0)
{}

bool Date::setDate(const std::string & str)
{
	std::stringstream ss(str);
	ss >> day >> month >> year;

	total = countTotal(day, month, year);

	return true;
}

int Date::countTotal(int d, int m, int y)
{
	int result {0};

	--y;
	result = y * 365 + (y / 4) - (y / 100) + (y / 400);
	result += Date::days_in_month[m - 1];
	if (m > 2 && yearIsLeap(y + 1))
		++result;
	result += d - 1;

	return result;
}

std::string Date::countDate()
{
	// this INT variable limits correct tests to 14699 year
	long long tot = total;

	// count years
	// bad accuracy because of integer division in initial formula
	int y = 400 * tot / (400 * 365 + 100 - 4 + 1);
	tot -= y * 365 + (y / 4) - (y / 100) + (y / 400);

	// crutch to fix bad accuracy
	bool fix = true;
	while (fix)
	{
		if (tot > 364 && (!yearIsLeap(y + 1) || !y))	// special case for y == 0
		{
			++y;
			tot -= 365;
			continue;
		}
		if (tot > 365 && yearIsLeap(y + 1))
		{
			++y;
			tot -= 366;
			continue;
		}
		fix = false;
	}
	++y;

	// count months
	int m {0};
	if (yearIsLeap(y))
	{
		for (int i = 1; i < 13; ++i)
		{
			if (Date::days_in_month_leap[i] > tot)
			{
				m = i - 1;
				tot -= days_in_month_leap[m];
				break;
			}
		}
	}
	else
	{
		for (int i = 1; i < 13; ++i)
		{
			if (Date::days_in_month[i] > tot)
			{
				m = i - 1;
				tot -= days_in_month[m];
				break;
			}
		}
	}
	++m;

	// count days
	int d {static_cast<int>(tot)};
	++d;

	std::stringstream ss;
	ss << d << " " << m << " " << y;

	return ss.str();
}

bool Date::yearIsLeap(int year)
{
	return (!(year % 400) || (!(year % 4) && year % 100));
}

std::ostream & operator<<(std::ostream & out, const Date & date)
{
	out << date.day << " " << date.month << " " << date.year << " --- " << date.total;
	return out;
}

int Date::days_in_month[13] = 
{
	0,
	Date::days_in_month[0] + 31,
	Date::days_in_month[1] + 28,
	Date::days_in_month[2] + 31,
	Date::days_in_month[3] + 30,
	Date::days_in_month[4] + 31,
	Date::days_in_month[5] + 30,
	Date::days_in_month[6] + 31,
	Date::days_in_month[7] + 31,
	Date::days_in_month[8] + 30,
	Date::days_in_month[9] + 31,
	Date::days_in_month[10] + 30,
	Date::days_in_month[11] + 31
};

int Date::days_in_month_leap[13] = 
{
	0,
	Date::days_in_month_leap[0] + 31,
	Date::days_in_month_leap[1] + 29,
	Date::days_in_month_leap[2] + 31,
	Date::days_in_month_leap[3] + 30,
	Date::days_in_month_leap[4] + 31,
	Date::days_in_month_leap[5] + 30,
	Date::days_in_month_leap[6] + 31,
	Date::days_in_month_leap[7] + 31,
	Date::days_in_month_leap[8] + 30,
	Date::days_in_month_leap[9] + 31,
	Date::days_in_month_leap[10] + 30,
	Date::days_in_month_leap[11] + 31
};
