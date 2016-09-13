/**
* @author Andrew Thomas, Katie Hrenchir, Mac Crider, Yehan Li
* @file main.cpp
* @since 10 September 2016
* @brief Main runtime of the Calendar project.
*/

#include "Day.h"
#include "Month.h"

#include <iostream>
#include <string>
#include <fstream>



//-----------------------------------------------------------------------------
void initMonths() //intitalizes month object array
{
  Month months[10]; //create array of length 10 (Aug thru May for academic year)

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
  months[8].setStartDay(7);

  months[9].setMonthName("May"); //May, 31 days long, starts on Monday
  months[9].setNumDays(31);
  months[9].setStartDay(1);
}

//-----------------------------------------------------------------------------
int main (int argc, char** argv)
{
  bool repeat = true;
  std::cout << "Welcome to KAMYcal" << std::endl;
  int menuSelect = 0;
  initMonths(); //initialize months

  while (repeat)
  {
    std::string monthUserInput;
    std::cout << "Please enter the name of the month (e.g., Aug): " << std::endl;
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
      std::cout << " Sun  Mon  Tue  Wed  Thu  Fri " << std::endl;


      for(int i=0 ; i<7 ; i++){
      //print first line of calendar
        if(i<firstDay){
          //5 spaces total: 3 for the day width, and 1 on either end
          std::cout << "     ";
          //           " Sun ";
          //           "  4  ";
        }
        else{
          std::cout << "  " << i-firstDay+1 << "  " << std::endl;
        }
      }

      int tempDay = 0;
      for(int i=(7-firstDay+1) ; i<=totalDays ; i++){
        if(i<10){//spacing for single digit numbers:
          std::cout << "  " << i << "  ";
        }
        else{ //spacing for double digit numbers:
          std::cout << " "  << i << "  ";
        }
        tempDay++;
        if(tempDay>5){
          std::cout << "\n";
          tempDay=0;
        }
      }

  }


  else if(menuType==2)    //Week view calendar
  {

  }


  else if(menuType==3)    //Single day calendar
  {

  }


}
