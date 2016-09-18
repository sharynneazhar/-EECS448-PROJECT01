/**
* @author Andrew Thomas, Katie Hrenchir, Mac Crider, Yehan Li
* @file Month.cpp
* @since 10 September 2016
* @brief Functionality of the Month class. A container for Day nodes, varies in size, name, and starting day of the week
*/

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

void Month:: initDays()
{
  int dayOfWeek = getStartDay();
	days = new Day[ getNumDays() ];
  for (int i = 0; i < getNumDays(); i++)
  {
    Day[i].setMonth(getMonthName());
    Day[i].setDay(i+1);
    Day[i].setWeek(dayOfWeek);
    dayOfWeek++;
    if (dayOfWeek > 7)
    {
      dayOfWeek = 0;
    }
  }

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
