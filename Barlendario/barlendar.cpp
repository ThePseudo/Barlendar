#include "barlendar.h"

tm getBarlendarTime(time_t in_time) //ms from 1/1/1970
{
	tm result;
	localtime_s(&result, &in_time);
	calendarToBarlendar(&result);
	return result;
}

void calendarToBarlendar(tm *in_time)
{
	int yearday, month = -1, monthday;
	yearday = in_time->tm_yday;
	for (yearday = in_time->tm_yday; yearday >= 0; yearday -= 28)
	{
		++month;
	}
	monthday = yearday + 28;
	in_time->tm_mday = monthday;
	in_time->tm_mon = month; // 0-11
	in_time->tm_wday = monthday % 7; // 0-7
}
