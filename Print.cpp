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

//a destructor goes here!!


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

void Print:: printWeek()
{

}

void Print:: printDay()
{

}
