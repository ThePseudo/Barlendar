#pragma once

#include <time.h>

/*
* In the BarLendar, each month [January -> December] has 28 days.
* There is a 13th month made of 1 or 2 days (bisestile year) leftover, that is the "new-year month".
* Each month is exactly 4 weeks long. 
* Month days are counted 0-27, week days 0-7, months 0-12. The remaining measures are intect
*/

tm getBarlendarTime(time_t in_time);
void calendarToBarlendar(tm *in_time);