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

  // ----------
  // VARIABLES
  // NOTE: In this project, we distinguish "date" as a specific date like the
  // 10th versus "day" which refers to the whole day like 10th of August
  // ----------
  bool overlap = false;
  int numDaysWithEvents = 0;
  int currentDate = 0;
  int currentYear = 0;
  std::string date = "";
  std::string currentMonth = "";

  // Used for user date input
  std::string monthString = "";
  std::string dateString = "";
  std::string yearString = "";

  Print* printer = new Print(months); // printer for different calendar views


  // ---------------
  // INITIALIZATION
  // ---------------
  printBanner("banner.txt");
  initMonths(months);

  Day currentDay;
  numDaysWithEvents = getNumDaysWithEvents();
  Day* daysWithEvents = new Day[numDaysWithEvents];
  getDaysWithEvents(daysWithEvents, numDaysWithEvents);


  int menuOption = 0;
  while (menuOption != 7) {
    if (currentDay.isEmpty()) {
      do {
        std::cout << "\nPlease enter a current date (e.g. Aug/01/2016): " << std::endl;
        std::cout << "> ";
        std::cin >> date;

        // keep a record of the day in string type
        monthString = date.substr(0,3);
        dateString = date.substr(4,2);
        yearString = date.substr(7,4);

        // convert the date and year to integer representations
        currentMonth = monthString;
        currentDate = std::stoi(dateString);
        currentYear = std::stoi(yearString);
      } while(!currentDay.DateTest(currentMonth, currentDate, currentYear));
    }

    // Set the details about the currentDay
    currentDay.setDay(currentDate);
    currentDay.setMonth(currentMonth);
    currentDay.setYear(currentYear);

    printMenu();
    std::cout << "> Enter your selection: ";
    std::cin >> menuOption;

    // isdigit isn't working as expected
    // http://stackoverflow.com/questions/5655142/how-to-check-if-input-is-numeric-in-c
    if (!std::cin) { // user didn't input an integer
      // reset failbit
      std::cin.clear();
      // skip bad input
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      // next, request user reinput
      printMenu();
      std::cout << "> Bad entry. Please try again.\n";
      std::cout << "> Enter your selection: ";
      std::cin >> menuOption;
    }

    switch (menuOption) {
      case 1: {
        std::cout << "\n ___________" << std::endl;
        std::cout << "|___________|" << std::endl;
        std::cout << "|           |" << std::endl;
        std::cout << "|   " << yearString << "    |" << std::endl;
        std::cout << "|  " << monthString << " "<< dateString << "   |" << std::endl;
        std::cout << "|___________|" << std::endl;

        printer->printDetail(daysWithEvents, numDaysWithEvents, currentDay);
        break;
      }
      case 2: {
        printer->printWeek(currentDate, currentMonth, currentYear);
        break;
      }
      case 3: {
        std::string monthUserInput;
        std::cout << "\nPlease enter the name of the month (e.g. Aug): " << std::endl;
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
        std::string startDateInput, endDateInput, startTimeInput, endTimeInput;
        std::string name, desc, startMonth, endMonth;
        int startDate, endDate, startYear, endYear, startTime, endTime;

        std::cout << "\nEnter the following details: " << std::endl;
        std::cout << "Name: ";
        std::cin.ignore(1, '\n');
        getline(cin, name);
        std::cout << "Description: ";
        getline(cin, desc);
        
        std::cout << "Start Date (e.g. Aug/10/2016): ";
        getline(cin, startDateInput);
        std::cout << "End Date (e.g. Aug/10/2016): ";
        getline(cin, endDateInput);
        std::cout << "Start Time (e.g. 1730): ";
        getline(cin, startTimeInput);
        std::cout << "End Time (e.g. 1400): ";
        getline(cin, endTimeInput);

        char repeat;
        std::cout << "Repeat Event? (Y/N): ";
        std::cin >> repeat;

        int repeatSchedule;
        int repeatDays;
        if (repeat == 'Y' || repeat == 'y') {
          std::cout << "Repeat this event..." << std::endl;
          std::cout << "1. Weekly" << std::endl;
          std::cout << "2. Biweekly" << std::endl;
          std::cout << "3. Monthly" << std::endl;
          std::cout << "> Your selection: ";
          std::cin >> repeatSchedule;

          std::cout << "On which days should the event be repeated?" << std::endl;
          std::cout << "1. Mondays" << std::endl;
          std::cout << "2. Tuesdays" << std::endl;
          std::cout << "3. Wednesdays" << std::endl;
          std::cout << "4. Thursdays" << std::endl;
          std::cout << "5. Fridays" << std::endl;
          std::cout << "6. Saturdays" << std::endl;
          std::cout << "7. Sundays" << std::endl;
          std::cout << "> Your selection: ";
          std::cin >> repeatDays;
        }


        // parse the date and times
        startDate = std::stoi(startDateInput.substr(4, 2));
        startMonth = startDateInput.substr(0, 3);
        startYear = std::stoi(startDateInput.substr(7, 4));

        endDate = std::stoi(endDateInput.substr(4, 2));
        endMonth = endDateInput.substr(0, 3);
        endYear = std::stoi(endDateInput.substr(7, 4));

        startTime = std::stoi(startTimeInput);
        endTime = std::stoi(endTimeInput);

        // Create an Event instance
        Event event(name, desc, startDate, startYear, startMonth, endDate, endYear, endMonth, startTime, endTime);

        // Store the event to file
        std::cout << event.getName() << std::endl;


        // std::cin.ignore(1, '\n');
        // getline(cin, detail);
        // std::cout << "The added detail is: " << detail << std::endl;
        // currentDay.setDetail(detail);
        // if (!currentDay.contain(daysWithEvents, numDaysWithEvents)) {
        //   daysWithEvents[numDaysWithEvents - 1].setDay(currentDate);
        //   daysWithEvents[numDaysWithEvents - 1].setMonth(currentMonth);
        //   daysWithEvents[numDaysWithEvents - 1].setYear(currentYear);
        //   daysWithEvents[numDaysWithEvents - 1].setDetail(detail);
        // } else {
        //   currentDay.updateArr(daysWithEvents,numDaysWithEvents);
        // }
        // storeEvents(daysWithEvents, numDaysWithEvents, currentDay, overlap);
        break;
      }
      case 6: {
        removeEvents(daysWithEvents, numDaysWithEvents, date, currentDay);
        break;
      }
    }
  }

  std::cout << std::endl;
  printBanner("bannerRobot.txt");
  return 0;
}
