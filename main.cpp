/**
* @author Andrew Thomas, Katie Hrenchir, Mac Crider, Yehan Li
* @file main.cpp
* @since 10 September 2016
* @brief Main runtime of the Calendar project.
*/

#include "Print.h"
#include "Day.h"
#include "Month.h"
#include "NoteReader.h"
#include "helper.h"

#include <iostream>
#include <string>
#include <fstream>


//!> array of length 10 (Aug thru May for academic year)
Month months[10];

/**
* @pre None.
* @post Initializes the months array to the srandard values for the 2016/2017 academic year
* @return None.
*/
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

/**
* @pre None.
* @post Read through the file to check how many days have details. What should be the size of the day array.
* @return Number of days with details.
*/
int DetailNum()
{
  int num=0;
  char check=' ';
  std::ifstream inp;
  inp.open("Detail.txt");
  while(!inp.eof())
  {
    while(check != '\n' && !inp.eof())
    {
      check = inp.get();
    }
    check=' ';
    num = num + 1;
  }
  inp.close();
  return num;
}

/**
* @pre None.
* @post Builds a Day array with days from the input file with the details
* @return None.
*/
void readNote(Day *DayArr, int size)
{
  string Month = "";
  string Detail = "";
  int Day = 0;
  int Year = 0;
  std::ifstream inputFile;
  inputFile.open("Detail.txt");
  char x = ' ';
  if (inputFile.good())
  {
    for (int i = 0; i < size; i++)
    {
      if (x != '\n')//the order of reading files.
      {
        inputFile >> Month >> Day >>Year;
        while( x != '\n' && !inputFile.eof())
        {
          x = inputFile.get();
          if (x != '\n')
          {
            Detail = Detail + x;
          }
        }
      }
      DayArr[i].setDay(Day);
      DayArr[i].setMonth(Month);
      DayArr[i].setYear(Year);
      DayArr[i].setDetail(Detail);
      x = ' ';
      Detail = "";
      Month = "";
      Day = 0;
      Year = 0;
    }
  }
  inputFile.close();
}

/**
* @pre None.
* @post Writes the program's Day array objects with notes to the output file
* @return None.
*/
void writeNote(Day *DayArr, int size, Day CurrentDate, bool overlap)
{
  std::ofstream outputFile;
  outputFile.open("Detail.txt");
  for (int i = 0; i < size; i++)
  {
    if (DayArr[i].getMonth() != "" || DayArr[i].getDate() != 0 || DayArr[i].getYear() != 0)
    {
      outputFile << DayArr[i].getMonth() << " " << DayArr[i].getDate() << " " << DayArr[i].getYear() << " " << DayArr[i].getDetail() << '\n';
    }
  }

  outputFile.close();
}

/**
* @pre None.
* @post Removes a note from a day
* @return None.
*/
void removeNote(Day *DayArr, int size, std::string date, Day CurrentDate)
{
  std::string month = date.substr(0,3);
  int day = std::stoi(date.substr(4,5));
  for (int i=0; i < size; i++) {
    if (DayArr[i].getMonth() == month && DayArr[i].getDate() == day) {
      std::cout << DayArr[i].getDetail() << std::endl;
      DayArr[i].setDetail("");
      std::cout<< DayArr[i].getDetail() << std::endl;
      writeNote(DayArr, size, CurrentDate, false);
      return;
    }
  }

  std::cout<< "No note was found on that date.\n";
}

/**
* @pre None.
* @post The KAMYcal program will have run to user termination.
* @return None.
*/
int main(int argc, char** argv) {
  printBanner();
  initMonths();

  // Variables below are used for setting a current day
  int option = 0;
  int CurrentDay = 0;
  int CurrentYear = 0;
  int arrSize = 0;
  bool overlap = false;
  string date = "";
  string CurrentMonth = "";

  Day CurrentDate;  // create a day object. It's used for setting a current day.
  Print* printer = new Print(months);

  arrSize = DetailNum();
  Day *DayArr = new Day[arrSize];
  readNote(DayArr, arrSize);

  while (option != 7) {
    if (CurrentDate.isEmpty()) {
      do
      {
        std::cout << "\nPlease enter a current date(e.g., Aug/01/2016): " << std::endl;
        std::cout << "> ";
        std::cin >> date;
        //discerns the date from the user's string
        CurrentMonth = date.substr(0,3);
        CurrentDay = std::stoi(date.substr(4,5));
        CurrentYear = std::stoi(date.substr(8,11)) + 2000;
      } while(!CurrentDate.DateTest(CurrentMonth, CurrentDay, CurrentYear));
    }
    CurrentDate.setDay(CurrentDay);
    CurrentDate.setMonth(CurrentMonth);
    CurrentDate.setYear(CurrentYear);
    printMenu();
    std::cout << "\nEnter your selection:";
    std::cin >> option;

    switch (option) {
      case 1: {
        std::cout << CurrentDay << "/" << CurrentMonth << "/" << CurrentYear << endl;
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
        writeNote(DayArr, arrSize, CurrentDate, overlap);
        break;
      }
      case 6: {
        removeNote(DayArr, arrSize, date, CurrentDate);
        break;
      }
    }
  }

  std::cout << "\n\nThanks for using KAMYcal!\n\n" << std::endl;
  return 0;
}
