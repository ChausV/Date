#include "Date.h"
#include "test.h"
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::cerr;
using std::cin;

int main()
{
	cout << " ------------------ overall tests ------------------ " << endl;

	Date d1;
	cout << "Default Date: d1 = " << d1 << endl;
	cout << "Default format: " << d1.getFormat() << endl;

	d1.setDate("01 12 2018");
	cout << "Set date with setDate(). d1 = " << d1 << endl;
	Date::setFormat("%y.%m.%d");
	cout << "New format is: " << d1.getFormat() << endl;
	cout << "Now d1 = " << d1 << endl;

	d1.modify(31);
	cout << "Modify with 31 day. d1 = " << d1 << endl;
	d1.modify(-32);
	cout << "Modify with -32 days. d1 = " << d1 << endl;

	Date::setFormat("%d %m %y");
	cout << endl;

	cout << " --------- countTotal(), countDate() tests --------- " << endl;
	// test_diff();
	// test_problem();

	test_full_dates(2000, 2000);		// ok
	// test_full_dates(1, 100000);		// ok
	// test_full_dates(1, 1000000);		// ok (13 minutes. was before i add input validation)
	// test_full_dates(1500, 2500);		// ok (3 minutes with input validation)
	// test_full_dates(1, 5000);		// ok (14 minutes with input validation)

	cout << " --------- setFormat(), operator<<() tests --------- " << endl;

	Date d;
	d.setDate("25 12 1961");
	cout << d << endl;
	Date::setFormat("%y - %d - %m");
	cout << d << endl;
	Date::setFormat("Month: %m, Date: %d, Year: %y.");
	cout << d << endl;

	// negative setFormat() tests
	test_format_neg();

	if (!Date::setFormat("%y %m %d"))
		cerr << "error: Wrong format" << endl;

	cout << " ---------------- operator>>() tests --------------- " << endl;

	// "20c04a1975"
	// Date::setFormat("%dc%ma%yb");

	/*
	cout << "Current date: " << d << endl;
	cout << "Current format: " << Date::getFormat() << endl;
	cin >> d;
	cout << "Your date: " << d << endl;
	Date::setFormat("%d.%m.%y");
	cout << "Current format: " << Date::getFormat() << endl;
	cin >> d;
	cout << "Your date: " << d << endl;
	*/

	cout << " ---------------- operator-() tests ---------------- " << endl;
	Date::setFormat("%d/%m/%y");

	Date dl, dr;
	dl.setDate("23/06/1999");
	dr.setDate("23/06/2000");
	cout << dl << " - " << dr << " = " << dl - dr << "    (2000 is leap year)" << endl;
	cout << dr << " - " << dl << " = " << dr - dl << endl;
	dl.setDate("23/06/2001");
	cout << dl << " - " << dr << " = " << dl - dr << endl;
	cout << dr << " - " << dl << " = " << dr - dl << endl;
	cout << dr << " - " << dr << " = " << dr - dr << endl;

	dl.setDate("01/01/2042");
	dr.setDate("31/12/2041");
	cout << dl << " - " << dr << " = " << dl - dr << endl;
	cout << dr << " - " << dl << " = " << dr - dl << endl;
	
	return 0;
}