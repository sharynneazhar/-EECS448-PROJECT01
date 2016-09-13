/**
* @author Andrew Thomas, Katie Hrenchir, Mac Crider, Yehan Li
* @file main.cpp
* @since 10 September 2016
* @brief Main runtime of the Calendar project.
*/

#include "Day.h"

#include <iostream>
#include <string>
#include <fstream>

int main (int argc, char** argv)
{
  bool repeat = true;
  cout<<"Welcome to KAMYcal"<<endl;
  int menuSelect = 0;

  while (repeat)
  {
    cout<<"Please enter the name of the month:";
    string month;
    cin>>month;

    //switch based off of first character of string to set month
  }

}


void PrintCalendar (int menuType)
{
  /*
    menuType=1 => Month view calendar
    menuType=2 => Week view calendar
    menuType=3 => Single day calendar
  */
  cout << "\n\n";
  if(menuType==1)   //Month view calendar
  {

  }
  else if(menuType==2)    //Week view calendar
  {

  }
  else if(menuType==3)    //Single day calendar
  {

  }

}
