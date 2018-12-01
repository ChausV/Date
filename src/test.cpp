#include "Date.h"
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;

void testDate1(const std::string & str)
{
	Date d;
	d.setDate(str);
	cout << d << endl;
	cout << d.countDate() << endl;
	cout << "-------------------------------";
	if (str == d.countDate())
		cout << "[OK]" << endl;
	else
		cout << "Error!" << endl;
	// cout << endl;
}

void testDateQuiet(const std::string & str)
{
	Date d;
	d.setDate(str);
	if (str != d.countDate())
	{
		cout << "--------------------  Error!" << endl;
		cout << d << endl;
		cout << d.countDate() << endl;
		cout << endl;
	}
}

bool isLeap(int year)
{
	return (!(year % 400) || (!(year % 4) && year % 100));
}

void test_diff()
{
	testDate1("1 1 1");
	testDate1("2 1 1");
	testDate1("3 1 1");
	testDate1("10 1 1");
	testDate1("31 1 1");
	testDate1("1 2 1");
	testDate1("11 2 1");
	testDate1("27 2 1");
	testDate1("28 2 1");
	testDate1("1 3 1");
	testDate1("11 3 1");
	testDate1("30 3 1");
	testDate1("31 3 1");

	testDate1("1 1 2");
	testDate1("30 11 2018");
	testDate1("1 1 400");
	testDate1("1 1 401");
	testDate1("1 1 407");
	testDate1("1 1 801");
	testDate1("30 12 2005");
	testDate1("1 1 5");
	testDate1("20 6 1985");


	testDateQuiet("31 3 1");
	testDateQuiet("29 2 1");

	testDate1("29 2 1");
}

void test_problem()
{
	testDate1("29 2 4");
	testDate1("31 12 4");
	testDate1("1 1 6");
	testDate1("29 2 8");
	testDate1("31 12 8");
	testDate1("4 4 4");
}

/*
** takes range of years and checks every date in this range.
** outputs in case of error.
*/
void test_full_dates(int y1, int y2)
{	
	int day_in_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int days;
	for(int y = y1; y <= y2; ++y)
	{
		for (int m = 1; m < 13; ++m)
		{
			days = day_in_month[m];
			if (m == 2 && isLeap(y))
				++days;
			for (int d = 1; d <= days; ++d)
			{
				std::stringstream ss;
				ss << d << " " << m << " " << y;
				testDateQuiet(ss.str());
				// if (m == 2 && d > 28)
				// 	cout << d << " " << m << " " << y << endl;
			}
		}
	}
}