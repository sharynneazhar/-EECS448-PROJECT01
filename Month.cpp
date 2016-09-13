#include "Month.h"

Month:: Month(const std::string MonthName, int NumDays, int StartDay)
{
    monthName = MonthName;
    numDays = NumDays;
    startDay = StartDay;
    
}


Month:: Month()
{
    monthName = "";
    startDay = 0;
    numDays = 0;
}


void Month:: setMonthName(const std::string MonthName)
{
    monthName = MonthName;
}

void Month:: setNumDays(const int NumDays)
{
    numDays = NumDays;
}

void Month:: setStartDay(const int StartDay)
{
    startDay = StartDay;
}


std::string Month:: getMonthName()
{
    return(monthName);
}


int Month:: getNumDays()
{
    return(numDays);
}


int Month:: getStartDay()
{
    return(startDay);
}
