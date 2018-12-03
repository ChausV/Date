Class for storing the calendar dates.
Main idea is to operate with dates represented as number of days
from 01.01.0001.
Gregorian calendar. Leap years support. No calendar reforms handling
(like migration from Julian to Gregorian calendar at 1918 in Russia).
Proleptic dates (from 1-st year till 1581-th year) are supported.
B.C. dates (negative dates, dates before 01.01.0001) are not tested.
Behavior for dates after 1000000-th year not tested.
Validation accepts years from 1 till 1000000.
Date format can be provided by user with format string. Format string
has three mandatory specificators %d, %m, %y (for day, month and year).
