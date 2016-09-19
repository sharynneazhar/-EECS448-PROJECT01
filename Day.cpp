/**
* @author Andrew Thomas, Katie Hrenchir, Mac Crider, Yehan Li
* @file Day.cpp
* @since 10 September 2016
* @brief Functionality of the Day class. Used as a node for the Month class.
*/

#include "Day.h"
using namespace std;
Day:: Day(const int Date, int Year, int Week, std::string month, bool Note)
{
    date=Date;
    week=Week;
    month = month;
    note=Note;
    year=Year;
    detail="";
}

Day:: Day()
{
    date=0;
    week=0;
    month = "";
    note=false;
    year=0;
    detail="";
}

void Day:: setDay(int Date)
{
    date=Date;
}

void Day:: setWeek(int Week)
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

int Day:: getDate()
{
    return(date);
}

int Day:: getWeek()
{
    return(week);
}

std::string Day:: getMonth()
{
    return month;
}

bool Day:: notePresent()
{
    return(note);
}

std::string Day:: getNote()
{
	if(!notePresent() ) {
		std::cout<<"There's no note for today!";
	} else {
		NoteReader* noteReader;
		return noteReader -> readNote();
	}
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

void Day:: setDetail(string De)//just set the detail of a day
{
    detail=De;
}

bool Day:: contain(Day *DayArr, int size)//check if there are some exiting notes on this day
//(if the date and month of the current day is as same as one of the objects in the array<I created a day array in main>),
//if there is an exsting note, just do string(detail) addtion.
{
    for(int i=0; i<size-1; i++)
    {
        if(date==DayArr[i].getDate() && month==DayArr[i].getMonth())
        {
            i=size+1;
            return true;
        }
        else
        {
            i=size+1;
            return false;
        }
    }
}

void Day:: updateArr(Day *DayArr, int size)
{
    for(int i=0; i<size; i++)
    {
         if(date==DayArr[i].getDate() && month==DayArr[i].getMonth())
         {
            detail=DayArr[i].getDetail()+detail;
            DayArr[i].setDetail(detail);
            i=size+1;
         }
    }
}

string Day:: getDetail()
{
    return detail;
}

bool Day:: isEmpty()
{
    if(month=="")
    {
        return true;
    }
    else
    {
        return false;
    }
}
