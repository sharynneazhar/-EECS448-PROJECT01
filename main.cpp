/**
* @author Andrew Thomas, Katie Hrenchir, Mac Crider, Yehan Li
* @file main.cpp
* @since 10 September 2016
* @brief Main runtime of the Calendar project.
*/

#include "Print.h"
#include "Day.h"
#include "Month.h"


#include <iostream>
using namespace std;
#include <string>
#include <fstream>


  Month months[10]; //create array of length 10 (Aug thru May for academic year)

//-----------------------------------------------------------------------------
void initMonths() //intitalizes month object array
{


  months[0].setMonthName("Aug"); //August, 31 days long, starts on Monday
  months[0].setNumDays(31);
  months[0].setStartDay(1);

  months[1].setMonthName("Sep"); //September, 30 days long, starts on Thursday
  months[1].setNumDays(30);
  months[1].setStartDay(4);

  months[2].setMonthName("Oct"); //October, 31 days long, starts on Saturday
  months[2].setNumDays(31);
  months[2].setStartDay(6);

  months[3].setMonthName("Nov"); //November, 30 days long, starts on Tuesday
  months[3].setNumDays(30);
  months[3].setStartDay(2);

  months[4].setMonthName("Dec"); //December, 31 days long, starts on Thursday
  months[4].setNumDays(31);
  months[4].setStartDay(4);

  months[5].setMonthName("Jan"); //January, 31 days long, starts on Sunday
  months[5].setNumDays(31);
  months[5].setStartDay(0);

  months[6].setMonthName("Feb"); //February, 28 days long, starts on Wednesday
  months[6].setNumDays(28);
  months[6].setStartDay(3);

  months[7].setMonthName("Mar"); //March, 31 days long, starts on Wednesday
  months[7].setNumDays(31);
  months[7].setStartDay(3);

  months[8].setMonthName("Apr"); //April, 30 days long, starts on Saturday
  months[8].setNumDays(30);
  months[8].setStartDay(6);

  months[9].setMonthName("May"); //May, 31 days long, starts on Monday
  months[9].setNumDays(31);
  months[9].setStartDay(1);
}

//----------------------------------------------------------------------------------------
void PrintYear ()
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


void PrintCalendar (int menuType, int monthNumber)
{
  /*
    menuType=1 => Month view calendar
    menuType=2 => Week view calendar
    menuType=3 => Single day calendar
  */
  std::cout << "\n\n";
  if(menuType==1)   //Month view calendar
  {
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


  else if(menuType==2)    //Week view calendar
  {
    int firstDay = months[monthNumber].getStartDay();
    int totalDays = months[monthNumber].getNumDays();
    std::cout << " Sun  Mon  Tue  Wed  Thu  Fri Sat  " << std::endl;

  }


  else if(menuType==3)    //Single day calendar
  {

  }

}


//-----------------------------------------------------------------------------
void WeekDisplay(int D, int M) //it works!!!!!!OMG!I cannot believe the complexity of this function!!!!
    {
      int count=months[M].getStartDay();
      for(int i=1; i<=months[M].getNumDays(); i++)
        { 
          if(D==i)
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
      if(D+(7-count)>months[M].getNumDays())
      {
        int Num=0;
        std::cout << " Sun  Mon  Tue  Wed  Thu  Fri  Sat  " << std::endl;
        for(int i=0 ; i<7 ; i++)
      {
            //date of sunday in the week surrounding the current day.
        if(D-count+i<=months[M].getNumDays())
        {
            std::cout << "  " << D-count+i<<" ";
            Num=Num+1;
        }
        else
        {
          for(int i=1; i<=(7-Num); i++)
          {
            std::cout << "  " <<i<<"  ";
          }
          i=100;
        }
      }
    }
    else if(D-count<0)
    {  
      if((M==0&&D<2))
        {
          std::cout << "Part of this week is in July, display is out of range!!!" << std::endl;
        }
        else
        {
          int LastMonDay=months[M-1].getNumDays();
          std::cout << " Sun  Mon  Tue  Wed  Thu  Fri  Sat  " << std::endl;
          for(int i=0; i<=count-D; i++)
          {
            cout<<"  "<<LastMonDay+(D-count)+i<<" ";
          }
          for(int i=1; i<=(7-count); i++)
          {
            cout<<"  "<<i<<" ";
          }
        }
    }
    else
      {
        std::cout << " Sun  Mon  Tue  Wed  Thu  Fri  Sat  " << std::endl;
        for(int i=0 ; i<7 ; i++){
            //date of sunday in the week surrounding the current day.
                std::cout << "  " << D-count+i<<" ";
      }
    }
}
//Two casese: 1,the current week is in one month 2, the current week is in two months.
//D+ (7-count)>total mumber of days in that month-> display days included in the next month.


//---------------------------------------------------------------------------------------

void PrintWeek (int CDay, string CMonth, int CYear)
{
  cout<<"Current Year: "<< CYear <<"     Current Month: "<< CMonth <<endl;
  if(CMonth=="Aug")
    {
        WeekDisplay(CDay,0);
    }
    else if(CMonth=="Sep")
    {
        WeekDisplay(CDay,1);
    }
    else if(CMonth=="Oct")
    {
        WeekDisplay(CDay,2);
    }
    else if(CMonth=="Nov")
    {
        WeekDisplay(CDay,3);
    }
     else if(CMonth=="Dec")
    {
        WeekDisplay(CDay,4);
    }
    else if(CMonth=="Jan")
    {
        WeekDisplay(CDay,5);
    }
     else if(CMonth=="Feb")
    {
        WeekDisplay(CDay,6);
    }
    else if(CMonth=="Mar")
    {
        WeekDisplay(CDay,7);
    }
     else if(CMonth=="Apr")
    {
        WeekDisplay(CDay,8);
    }
    else if(CMonth=="May")
    {
        WeekDisplay(CDay,9);
    }
}
//-----------------------------------------------------------------------------
int main (int argc, char** argv)
{
  bool repeat = true;
	//temp for testing purposes


  std::cout << "\nWelcome to KAMYcal" << std::endl;
  int menuSelect = 0;
  //Variables blow are used for setting a current day
  int CurrentDay=0;
  int CurrentYear=0;
  string date="";
  string CurrentMonth="";
  //Variables above are used for setting a current day
  initMonths(); //initialize months
  Day CurrentDate;  // create a day object. It's used for setting a current day.

	PrintYear();
	cout<< "\n\n";
	PrintCalendar(1, 8);
	cout<<"\n\n";
	PrintCalendar(1,9);


  cout<<"\nPlease enter a current date(e.g., Aug/01/2016): "<<endl;
  cin>>date;

  CurrentMonth= date.substr(0,3);
  CurrentDay=std::stoi(date.substr(5,6));
  CurrentYear=std::stoi(date.substr(8,11)) + 2000;

 if(CurrentDate.DateTest(CurrentMonth, CurrentDay, CurrentYear))
  {

   PrintWeek(CurrentDay, CurrentMonth, CurrentYear);
  }// check if the user's input is correct and print week calendar


  while (repeat)
  {
    std::string monthUserInput;
    std::cout << "\nPlease enter the name of the month (e.g., Aug): " << std::endl;
    std::cin >> monthUserInput;

    std::string temp;
    for (int i=0 ; i<10 ; i++)
    {
      temp = months[i].getMonthName();
      if(temp==monthUserInput){
        PrintCalendar(1, i);
        break;
      }

      if(i==9){
        std::cout << "\nMonth name is invalid." << std::endl;
      }

    }

    //switch based off of first character of string to set month
  }

}
