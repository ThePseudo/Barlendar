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
	int yearday, month = 0;
	yearday = in_time->tm_yday;
	for (yearday = in_time->tm_yday; yearday >= 28; yearday -= 28)
	{
		++month;
	}
	in_time->tm_mday = yearday;
	in_time->tm_mon = month; // 0-13
}

void barlendarToCalendar(tm * in_time)
{
	time_t result = getTimeFromBarlendar(*in_time);
	localtime_s(in_time, &result);
}

time_t getTimeFromBarlendar(tm in_time)
{
	//const int months31[] = { 0, 2, 4, 6, 7, 9, 11 };
	//const int months30[] = { 3, 5, 8, 10 };
	time_t result, seconds = 0;
	time_t yearsInMs;
	int monthDay = 0, month, yearday = in_time.tm_yday;
	char bisestile = ((in_time.tm_year + 1900) % 400) && !((in_time.tm_year + 1900) % 4);
	for (month = 0; month < 12; ++month)
	{
		monthDay = yearday; // copying old value
		if (month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 9 || month == 11)
		{
			yearday -= 31;
		}
		else if (month == 3 || month == 5 || month == 8 || month == 10)
		{
			yearday -= 30;
		}
		else if (bisestile)
		{
			yearday -= 29;
		}
		else
		{
			yearday -= 28;
		}
		if (yearday < 0) break;
	}
	tm time_commodity = { 0 };
	time_commodity.tm_year = in_time.tm_year;
	time_commodity.tm_mday = monthDay + 1;
	time_commodity.tm_mon = month;
	time_commodity.tm_yday = in_time.tm_yday;
	time_commodity.tm_hour = in_time.tm_hour;
	time_commodity.tm_min = in_time.tm_min;
	time_commodity.tm_sec = in_time.tm_sec;
	time_commodity.tm_wday = in_time.tm_wday;
	time_commodity.tm_isdst = in_time.tm_isdst;
	yearsInMs = mktime(&time_commodity);
	result = yearsInMs;
	return result;
}
