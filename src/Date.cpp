#include "Date.h"
#include <sstream>
#include <regex>

static void readYMD(char * input, char * format, int * y, int * m, int * d);

/*

	std::stringstream ss(str);
	ss >> day >> month >> year;

	std::stringstream ss;
	ss << d << " " << m << " " << y;

*/
Date::Date() : day(0), month(0), year(0), total(0)
{}

bool Date::setDate(const std::string & input)
{
	// check input to match format
	std::string format(Date::format);
	format.replace(format.find("%d"), 2, "\\d+");
	format.replace(format.find("%m"), 2, "\\d+");
	format.replace(format.find("%y"), 2, "\\d+");
	if (!std::regex_match(input, std::regex(format)))
		return false;

	// TODO: think about more elegant approach
	int y, m, d;
	readYMD(const_cast<char*>(input.c_str()),
			const_cast<char*>(Date::format.c_str()), &y, &m, &d);

	if (y < 1 || d < 1 || m < 1 || m > 12)
		return false;
	int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (m != 2 && d > months[m])
		return false;
	if (m == 2 && ((yearIsLeap(y) && d > (months[m] + 1)) || (!yearIsLeap(y) && d > months[m])))
		return false;
	// TODO think about this limitation
	if (y > 1000000)
		return false;

	day = d;
	month = m;
	year = y;
	countTotal();

	return true;
}

std::string Date::getDate() const
{

	std::string result(Date::format);
	result.replace(result.find("%d"), 2, std::to_string(day));
	result.replace(result.find("%m"), 2, std::to_string(month));
	result.replace(result.find("%y"), 2, std::to_string(year));

	return result;
}

void Date::countTotal()
{
	int result {0};

	int y = year - 1;
	result = y * 365 + (y / 4) - (y / 100) + (y / 400);
	result += Date::days_in_month[month - 1];
	if (month > 2 && yearIsLeap(y + 1))
		++result;
	result += day - 1;
	total = result;
}

void Date::countDate()
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

	day = d;
	month = m;
	year = y;
}

bool Date::yearIsLeap(int year) const
{
	return (!(year % 400) || (!(year % 4) && year % 100));
}

std::ostream & operator<<(std::ostream & out, const Date & date)
{
	out << date.getDate() << std::endl;
	return out;
}

static void readYMD(char * input, char * format, int * y, int * m, int * d)
{
	while (*input == *format && *input)
	{
		++input;
		++format;
	}
	if (!*input)
		return ;
	size_t shift = 0;
	int tmp = std::stoi(std::string(input), &shift);
	input += shift;
	++format;
	if (*format == 'd') *d = tmp;
	if (*format == 'm') *m = tmp;
	if (*format == 'y') *y = tmp;
	++format;

	readYMD(input, format, y, m, d);
}

std::istream & operator>>(std::istream & in, Date & date)
{
	std::string input;
	std::getline(in, input);
	if (!in.good())
	{
		std::cerr << "istream error" << std::endl;
		exit(1);
	}

	date.setDate(input);

	return in;
}

bool Date::setFormat(const std::string & format)
{
	size_t d_pos = format.find("%d");
	size_t m_pos = format.find("%m");
	size_t y_pos = format.find("%y");

	if (d_pos == std::string::npos ||
		m_pos == std::string::npos ||
		y_pos == std::string::npos ||
		d_pos != format.rfind("%d") ||
		m_pos != format.rfind("%m") ||
		y_pos != format.rfind("%y") ||
		(d_pos > m_pos ? d_pos - m_pos : m_pos - d_pos) == 2 ||
		(d_pos > y_pos ? d_pos - y_pos : y_pos - d_pos) == 2 ||
		(y_pos > m_pos ? y_pos - m_pos : m_pos - y_pos) == 2 )
	{
		return false;
	}

	Date::format = format;
	return true;
}

std::string Date::getFormat()
{
	return Date::format;
}

const int Date::days_in_month[13] = 
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

const int Date::days_in_month_leap[13] = 
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

std::string Date::format = "%d %m %y";
