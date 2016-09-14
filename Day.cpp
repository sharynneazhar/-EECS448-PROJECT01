/**
* @author Katie Hrenchir, Mac Crider, Yehan Li
* @file Day.cpp
* @since 10 September 2016
* @brief Functionality of the Day class. Used as a node for the Month class.
*/

#include "Day.h"

Day:: Day(const int Date, int Year, char Week, bool Note)
{
    date=Date;
    week=week;
    note=Note;
    year=Year;
}

Day:: Day()
{
    date=0;
    week=0;
    note=false;
    year=0;
}

void Day:: setDay(int Date)
{
    date=Date;
}

void Day:: setWeek(char Week)
{
    week=Week;
}

void Day:: setNote(bool Note)
{
     note=Note;
}

void Day:: setYear(int Year)
{
    year=Year;
}

void Day:: setMonth(std::string Month)
{
    month=Month;
}

int Day:: getYear()
{
    return(year);
}

<<<<<<< HEAD
int Day:: getDate() 
=======
int Day:: getDay()
>>>>>>> 60203141af6ef3ec1bb22d8b436341a2c49fdf3d
{
    return(date);
}

char Day:: getWeek()
{
    return(week);
}

std::string Day:: getMonth()
{
    return month;
}

bool Day:: getNote()
{
    return(note);
}

bool Day:: DateTest(std::string month, int day, int year)
{
   if(day>0 && day<32 && year>2015 && year<2018)
  {
    if(month=="Aug")
    {
        return true;
    }
    else if(month=="Sep")
    {
        return true;
    }
    else if(month=="Oct")
    {
        return true;
    }
    else if(month=="Nov")
    {
        return true;
    }
     else if(month=="Dec")
    {
        return true;
    }
    else if(month=="Jan")
    {
        return true;
    }
     else if(month=="Feb")
    {
        return true;
    }
    else if(month=="Mar")
    {
        return true;
    }
     else if(month=="Apr")
    {
        return true;
    }
    else if(month=="May")
    {
        return true;
    }
    else
    {
        return false;
        std::cout<<"Please input the month as what is demonstrated in the examples."<<std::endl;
    }
    //check the format of user's input of Current date.
  }
  else
  {
      std::cout<<"Please input valid day and year."<<std::endl;
      return false;
  }
}
