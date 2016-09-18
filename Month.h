/**
* @author Andrew Thomas, Katie Hrenchir, Mac Crider, Yehan Li
* @file Month.h
* @since 15 September 2016
* @brief Header of the Month class. A container for Day nodes, varies in size, name, and starting day of the week
*/

#ifndef MONTH_H
#define MONTH_H

#include "Day.h"

#include <string>
#include <iostream>
#include <fstream>

class Month
{
    private:
      std::string monthName;/*!< name of the month */
      int startDay;//the day of the week in which the month begins
                   //int 0 thru 6
                   // e.g., 0 = Sunday, 1 = Monday, etc.
      int numDays;//total number of days in the month


    public:
      /**
      *  @pre None.
      *  @post Constructs a Month class object with an empty string name, no days in the month, and it starts on a Sunday
      *  @return Month class object
      *
      */
      Month();

      /**
      *  @pre None.
      *  @post Constructs a Month class object with the corresponding arguments for monthName, numDays, and startDay
      *  @return Month class object
      *
      */
      Month(const std::string MonthName, int NumDays, int StartDay);

      /**
      *  @pre None.
      *  @post Sets monthName to the argument
      *  @return None.
      *
      */
      void setMonthName(const std::string MonthName);

      /**
      *  @pre None.
      *  @post Sets numDays to the argument
      *  @return None.
      *
      */
      void setNumDays(const int NumDays);

      /**
      *  @pre None.
      *  @post Sets startDay to the argument
      *  @return None.
      *
      */
      void setStartDay(const int StartDay);

      void initDays();

      /**
      *  @pre None.
      *  @post None.
      *  @return monthName value
      *
      */
      std::string getMonthName();

      /**
      *  @pre None.
      *  @post None.
      *  @return numDays value
      *
      */
      int getNumDays();

      /**
      *  @pre None.
      *  @post None.
      *  @return startDay value
      *
      */
      int getStartDay();

	  Day* days;

};

#endif
