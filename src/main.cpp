#include "Date.h"
#include "test.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cerr;
using std::cin;

int main()
{
	cout << " --------- countTotal(), countDate() tests --------- " << endl;
	// test_diff();
	// test_problem();

	test_full_dates(1999, 2001);		// ok
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
	if (!Date::setFormat("% %m %d"))
		cerr << "error: Wrong format" << endl;
	if (!Date::setFormat("%y % %d"))
		cerr << "error: Wrong format" << endl;
	if (!Date::setFormat("%y %m %"))
		cerr << "error: Wrong format" << endl;
	if (!Date::setFormat("%y %m %d %y"))
		cerr << "error: Wrong format" << endl;
	if (!Date::setFormat("%y %m %d %m"))
		cerr << "error: Wrong format" << endl;
	if (!Date::setFormat("%y %m %d %d"))
		cerr << "error: Wrong format" << endl;
	if (!Date::setFormat("%y%m %d"))
		cerr << "error: Wrong format" << endl;
	if (!Date::setFormat("%y %m%d"))
		cerr << "error: Wrong format" << endl;
	if (!Date::setFormat("%y%d %m"))
		cerr << "error: Wrong format" << endl;


	if (!Date::setFormat("%y %m %d"))
		cerr << "error: Wrong format" << endl;

	cout << " --------- operator>>() tests --------- " << endl;

	// "20c04a1975"
	// cin >> d;

	Date::setFormat("%dc%ma%yball");

	// cin >> d;
	
	return 0;
}