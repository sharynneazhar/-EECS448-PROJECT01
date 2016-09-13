#ifndef MONTH_H
#define MONTH_H

#include "Day.h"

#include <string>
#include <iostream>
#include <fstream>

class Month
{
    private:
      string monthName;//name of the month
      int startDay;//the day of the week in which the month begins
                   //int 0 thru 6
                   // e.g., 0 = Sunday, 1 = Monday, etc.
      int numDays;//total number of days in the month

    public:
      Month();
      Month(const string MonthName, int NumDays, int StartDay);
      void setMonthName(const string MonthName);
      void setNumDays(const int NumDays);
      void setStartDay(const int StartDay);
      string getMonthName();
      int getNumDays();
      int getStartDay();

};

#endif
