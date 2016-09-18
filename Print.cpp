/**
* @author Andrew Thomas, Katie Hrenchir, Mac Crider, Yehan Li
* @file Print.cpp
* @since 15 September 2016
* @brief Functionality of the Print class. Handles printing of various calendar views to the console
*/

#include "Print.h"

Print:: Print(Month monthsArr[])
{
	months = monthsArr;

}

//destructor?

//-----------------------------------------------------------------------------

void Print:: printYear()
{

  for(int i=0; i<=9; i++)
  {
      int firstDay = months[i].getStartDay();
      int totalDays = months[i].getNumDays();

	  std::cout << "\n\n" << months[i].getMonthName() << std::endl;
      std::cout << "\n Sun  Mon  Tue  Wed  Thu  Fri Sat  " << std::endl;

      for(int i=0 ; i<7 ; i++){
      //print first line of calendar
        if(i>=firstDay){

          std::cout << "  " << i-firstDay+1  ;

			if(i==6){
				std::cout<< "\n";
			} else {
				std::cout<< "  ";
			}
        }
        else{
          //5 spaces total: 3 for the day width, and 1 on either end
          std::cout << "     ";
          //           " Sun ";
          //           "  4  ";
        }
      }

		//prints the remaining lines of the calendar
      int tempDay = 0;
      for(int i=(7-firstDay+1) ; i<=totalDays ; i++){
        if(i<10){//spacing for single digit numbers:
          std::cout << "  " << i << "  ";
        }
        else{ //spacing for double digit numbers:
          std::cout << " "  << i << "  ";
        }
        tempDay++;
        if(tempDay>6){
          std::cout << "\n";
          tempDay=0;
        }
      }

  }

}

//-----------------------------------------------------------------------------

void Print:: printMonth(int monthNumber)
{
std::cout << "\n\n";

  int firstDay = months[monthNumber].getStartDay();
  int totalDays = months[monthNumber].getNumDays();
  std::cout << " Sun  Mon  Tue  Wed  Thu  Fri Sat  " << std::endl;

  for(int i=0 ; i<7 ; i++){
  //print first line of calendar
    if(i>=firstDay){

      std::cout << "  " << i-firstDay+1  ;

		if(i==6){
			std::cout<< "\n";
		} else {
			std::cout<< "  ";
		}
    }
    else{
      //5 spaces total: 3 for the day width, and 1 on either end
      std::cout << "     ";
      //           " Sun ";
      //           "  4  ";
    }
  }

	//prints the remaining lines of the calendar
  int tempDay = 0;
  for(int i=(7-firstDay+1) ; i<=totalDays ; i++){
    if(i<10){//spacing for single digit numbers:
      std::cout << "  " << i << "  ";
    }
    else{ //spacing for double digit numbers:
      std::cout << " "  << i << "  ";
    }
    tempDay++;
    if(tempDay>6){
      std::cout << "\n";
      tempDay=0;
    }
  }


}

//-----------------------------------------------------------------------------


void Print:: printWeek(int currentDay, std::string currentMonth, int currentYear)
{
  std::cout<<std::endl;
  std::cout<<"Current Year: "<< currentYear <<"Current Month: "<< currentMonth <<std::endl;
  if(currentMonth=="Aug")
    {
        weekDisplay(currentDay,0);
    }
    else if(currentMonth=="Sep")
    {
        weekDisplay(currentDay,1);
    }
    else if(currentMonth=="Oct")
    {
        weekDisplay(currentDay,2);
    }
    else if(currentMonth=="Nov")
    {
        weekDisplay(currentDay,3);
    }
     else if(currentMonth=="Dec")
    {
        weekDisplay(currentDay,4);
    }
    else if(currentMonth=="Jan")
    {
        weekDisplay(currentDay,5);
    }
     else if(currentMonth=="Feb")
    {
        weekDisplay(currentDay,6);
    }
    else if(currentMonth=="Mar")
    {
        weekDisplay(currentDay,7);
    }
     else if(currentMonth=="Apr")
    {
        weekDisplay(currentDay,8);
    }
    else if(currentMonth=="May")
    {
        weekDisplay(currentDay,9);
    }


}

//-----------------------------------------------------------------------------

void Print:: weekDisplay(int date, int month)
//it works!!!!!!OMG!I cannot believe the complexity of this function!!!!
{


      int count= months[month].getStartDay();
      for(int i=1; i<=months[month].getNumDays(); i++)
        {
          if(date==i)
          {
            i=100;
          }
          else
          {
            if(count<6)
            {
              count=count+1;
            }
            else
            {
              count=0;
            }
          }

        }
      if(date+(7-count)>months[month].getNumDays())
      {
        int Num=0;
        std::cout << " Sun  Mon  Tue  Wed  Thu  Fri  Sat  " << std::endl;
        for(int i=0 ; i<7 ; i++)
      {
            //date of sunday in the week surrounding the current day.
        if(date-count+i<=months[month].getNumDays())
        {
            std::cout << "   " << date-count+i<<"  ";
            Num=Num+1;
        }
        else
        {
          for(int i=1; i<=(7-Num); i++)
          {
            std::cout << "   " <<i<<"   ";
          }
          i=100;
        }
      }
    }
    else if(date-count<0)
    {
      if((month==0&&date<2))
        {
          std::cout << "Part of this week is in July, display is out of range!!!" << std::endl;
        }
        else
        {
          int LastMonDay=months[month-1].getNumDays();
          std::cout << " Sun  Mon  Tue  Wed  Thu  Fri  Sat  " << std::endl;
          for(int i=0; i<=count-date; i++)
          {
           std::cout<<"  "<<LastMonDay+(date-count)+i<<"  ";
          }
          for(int i=1; i<=(7-count); i++)
          {
            std::cout<<"  "<<i<<"  ";
          }
        }
    }
    else
      {
        std::cout << " Sun  Mon  Tue  Wed  Thu  Fri  Sat  " << std::endl;
        for(int i=0 ; i<7 ; i++){
            //date of sunday in the week surrounding the current day.
                std::cout << "  " << date-count+i<<"  ";
      }
    }
}
//Two casese: 1,the current week is in one month 2, the current week is in two months.
//D+ (7-count)>total mumber of days in that month-> display days included in the next month.

//-----------------------------------------------------------------------------

void Print:: printDay(int day, int month)
{
	switch (month[month].days[day-1].getWeek())
	{
		case ()
	}
}
