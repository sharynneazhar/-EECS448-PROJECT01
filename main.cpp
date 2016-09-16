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

//-----------------------------------------------------------------------------
int main (int argc, char** argv)
{
  bool repeat = true;
	//temp for testing purposes

  std::cout << "\nWelcome to KAMYcal" << std::endl;
  //Variables blow are used for setting a current day
  int CurrentDay=0;
  int CurrentYear=0;
  string date="";
  string CurrentMonth="";
  //Variables above are used for setting a current day
  initMonths(); //initialize months
  Day CurrentDate;  // create a day object. It's used for setting a current day.

  Print* printer = new Print(months);
	
	//printer -> printYear();
	//printer -> printMonth(4);
	//WeekDisplay(2, 3);
	printer -> printWeek(10, "Sep", 2016);

  cout<<"\nPlease enter a current date(e.g., Aug/01/2016): "<<endl;
  cin>>date;

  //discerns the date from the user's string
  CurrentMonth= date.substr(0,3);
  CurrentDay=std::stoi(date.substr(5,6));
  CurrentYear=std::stoi(date.substr(8,11)) + 2000;

 if(CurrentDate.DateTest(CurrentMonth, CurrentDay, CurrentYear))
  {

   //PrintWeek(CurrentDay, CurrentMonth, CurrentYear);
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
        printer -> printMonth(i);
        break;
      }

      if(i==9){
        std::cout << "\nMonth name is invalid." << std::endl;
      }

    }

    //switch based off of first character of string to set month
  }

}
