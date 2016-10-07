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
	if (notePresent()) {
		NoteReader* noteReader = nullptr;
		return noteReader->readNote();
	}

  return "There's no note for today!";
}


bool Day:: DateTest(std::string month, int day, int year)
{
     //only 2016 and 2017 are valid years
     if(year == 2016) {
          //limits months for 2016 to August through December and correct number of days
          if(month == "Aug") {
               if(day > 0 && day < 32) {
                    return true;
               } else {
                   std::cout<<"Please input valid day."<<std::endl;
                   return false;
               }
          } else if(month == "Sep") {
               if(day > 0 && day < 31) {
                    return true;
               } else {
                   std::cout<<"Please input valid day."<<std::endl;
                   return false;
               }
          } else if(month == "Oct") {
               if(day > 0 && day < 32) {
                    return true;
               } else {
                   std::cout<<"Please input valid day."<<std::endl;
                   return false;
               }
          } else if(month == "Nov") {
               if(day > 0 && day < 31) {
                    return true;
               } else {
                   std::cout<<"Please input valid day."<<std::endl;
                   return false;
               }
          } else if(month == "Dec") {
               if(day > 0 && day < 32) {
                    return true;
               } else {
                   std::cout<<"Please input valid day."<<std::endl;
                   return false;
               }
          } else {
               std::cout<<"Please input valid month corresponding with 2016."<<std::endl;
               return false;
          }
     } else if(year == 2017) {
          //limits valid months for 2017 to January through May and correct number of days
          if(month == "Jan") {
               if(day > 0 && day < 32) {
                    return true;
               } else {
                   std::cout<<"Please input valid day."<<std::endl;
                   return false;
               }
          } else if(month == "Feb") {
               if(day > 0 && day < 29) {
                    return true;
               } else {
                   std::cout<<"Please input valid day."<<std::endl;
                   return false;
               }
          } else if(month == "Mar") {
               if(day > 0 && day < 32) {
                    return true;
               } else {
                   std::cout<<"Please input valid day."<<std::endl;
                   return false;
               }
          } else if(month == "Apr") {
               if(day > 0 && day < 31) {
                    return true;
               } else {
                   std::cout<<"Please input valid day."<<std::endl;
                   return false;
               }
          } else if(month == "May") {
               if(day > 0 && day < 32) {
                    return true;
               } else {
                   std::cout<<"Please input valid day."<<std::endl;
                   return false;
               }
          } else {
               std::cout<<"Please input valid month corresponding with 2017."<<std::endl;
               return false;
          }
     } else {
         std::cout<<"Please input valid year, 2016 or 2017."<<std::endl;
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
  for(int i=0; i<size-1; i++) {
    if (date == DayArr[i].getDate() && month == DayArr[i].getMonth()) {
      i=size+1;
      return true;
    } else {
      i=size+1;
      return false;
    }
  }
  return false;
}

void Day:: updateArr(Day *DayArr, int size)
{
    for(int i=0; i<size; i++)
    {
         if(date==DayArr[i].getDate() && month==DayArr[i].getMonth())
         {
            detail=DayArr[i].getDetail() + '\n' + detail;
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
