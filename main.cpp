/**
* @author Andrew Thomas, Katie Hrenchir, Mac Crider, Yehan Li
* @file main.cpp
* @since 10 September 2016
* @brief Main runtime of the Calendar project.
*/


#include "helper.h"

#include <iostream>
#include <string>
#include <fstream>

//!> array of length 10 (Aug thru May for academic year)
Month months[10];

/**
* @pre None.
* @post The KAMYcal program will have run to user termination.
* @return None.
*/
int main(int argc, char** argv) {
  printBanner();
  initMonths(months);

  // Variables below are used for setting a current day
  int option = 0;
  int CurrentDay = 0;
  int CurrentYear = 0;
  int arrSize = 0;
  bool overlap = false;
  std::string date = "";
  std::string CurrentMonth = "";

  // Used for user date input
  std::string monthString = "";
  std::string dateString = "";
  std::string yearString = "";

  Day CurrentDate;  // create a day object. It's used for setting a current day.
  Print* printer = new Print(months);

  arrSize = getNumDaysWithEvents();
  Day* DayArr = new Day[arrSize];
  getDaysWithEvents(DayArr, arrSize);

  while (option != 7) {
    if (CurrentDate.isEmpty()) {
      do
      {
        std::cout << "\nPlease enter a current date(e.g., Aug/01/2016): " << std::endl;
        std::cout << "> ";
        std::cin >> date;

        monthString = date.substr(0,3);
        dateString = date.substr(4,2);
        yearString = date.substr(7,4);

        CurrentMonth = monthString;
        CurrentDay = std::stoi(date.substr(4,5));
        CurrentYear = std::stoi(date.substr(8,11)) + 2000;
      } while(!CurrentDate.DateTest(CurrentMonth, CurrentDay, CurrentYear));
    }
    CurrentDate.setDay(CurrentDay);
    CurrentDate.setMonth(CurrentMonth);
    CurrentDate.setYear(CurrentYear);
    printMenu();
    std::cout << "> Enter your selection: ";
    std::cin >> option;

    switch (option) {
      case 1: {
        std::cout << "\n\n ___________" << std::endl;
        std::cout << "|___________|" << std::endl;
        std::cout << "|           |" << std::endl;
        std::cout << "|   " << yearString << "    |" << std::endl;
        std::cout << "|  " << monthString << " "<< dateString << "   |" << std::endl;
        std::cout << "|___________|" << std::endl;

        printer->printDetail(DayArr, arrSize, CurrentDate);
        break;
      }
      case 2: {
        printer->printWeek(CurrentDay, CurrentMonth, CurrentYear);
        break;
      }
      case 3: {
        std::string monthUserInput;
        std::cout << "\nPlease enter the name of the month (e.g., Aug): " << std::endl;
        std::cin >> monthUserInput;
        std::string temp;
        for (int i = 0 ; i < 10 ; i++) {
          temp = months[i].getMonthName();
          if (temp == monthUserInput) {
            printer->printMonth(i);
            break;
          }
          if(i == 9) {
            std::cout << "\nMonth name is invalid." << std::endl;
          }
        }
        break;
      }
      case 4: {
        printer->printYear();
        break;
      }
      case 5: {
        string detail = "";
        std::cout << "What do you want to add to the current day?" << std::endl;
        std::cin.ignore(1, '\n');
        getline(cin, detail);
        std::cout << "The added detail is: " << detail << std::endl;
        CurrentDate.setDetail(detail);
        if (!CurrentDate.contain(DayArr, arrSize)) {
          DayArr[arrSize - 1].setDay(CurrentDay);
          DayArr[arrSize - 1].setMonth(CurrentMonth);
          DayArr[arrSize - 1].setYear(CurrentYear);
          DayArr[arrSize - 1].setDetail(detail);
        } else {
          CurrentDate.updateArr(DayArr,arrSize);
        }
        storeEvents(DayArr, arrSize, CurrentDate, overlap);
        break;
      }
      case 6: {
        removeEvents(DayArr, arrSize, date, CurrentDate);
        break;
      }
    }
  }

  std::cout << "\n\nThanks for using KAMYcal!\n\n" << std::endl;
  return 0;
}
