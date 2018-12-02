#include "Date.h"
#include "test.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cerr;

int main()
{
	cout << " --------- countTotal(), countDate() tests --------- " << endl;
	// test_diff();
	// test_problem();

	test_full_dates(1950, 2050);			// ok
	// test_full_dates(1, 100000);			// ok
	// test_full_dates(1, 1000000);			// ok (13 minutes)

	cout << " --------- setFormat(), operator<<() tests --------- " << endl;

	Date d;
	d.setDate("25 12 1961");
	cout << d << endl;
	Date::setFormat("%y - %d - %m");
	cout << d << endl;
	Date::setFormat("Month: %m, Date: %d, Year: %y.");
	cout << d << endl;

	cout << Date::format << endl;

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

	cout << Date::format << endl;

	if (!Date::setFormat("%y %m %d"))
		cerr << "error: Wrong format" << endl;
	cout << Date::format << endl;


	
	return 0;
}