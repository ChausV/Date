#include "Date.h"
#include "test.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	// test_diff();

	// test_problem();

	// test_full_dates(1, 14699);			// ok
	// test_full_dates(1, 100000);			// ok
	test_full_dates(1, 1000000);			// ok (13 minutes)
	
	return 0;
}