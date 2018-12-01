#include "Date.h"
#include "test.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	test_diff();

	test_problem();

	test_full_dates(1, 14699);			// ok
	// test_full_dates(14700, 14710);		// not ok (one day difference)
	// test_full_dates(49900, 50000);		// not ok (one day difference)
	// test_full_dates(99990, 100000);		// ok
	// test_full_dates(1119990, 1120000);	// ok
	
	return 0;
}