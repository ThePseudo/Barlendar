#pragma once

#include <time.h>

/*
* In the BarLendar, each month [January -> December] has 28 days.
* There is a 14th month made of 1 or 2 days (bisestile year) leftover, that is the "new-year month".
* Each month is exactly 4 weeks long. 
* Month days are counted 0-27, week days 0-7, months 0-13. The remaining measures are intact.
*/

tm getBarlendarTime(time_t in_time);
void calendarToBarlendar(tm *in_time);
void barlendarToCalendar(tm *in_time);
time_t getTimeFromBarlendar(tm in_time);