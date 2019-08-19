#include "barlendar.h"

int main()
{
	tm bar, todayCalendar;
	time_t now = time(0), timeResult;
	localtime_s(&todayCalendar, &now);
	bar = getBarlendarTime(now);
	timeResult = getTimeFromBarlendar(bar);
	barlendarToCalendar(&bar);
	return 0;
}