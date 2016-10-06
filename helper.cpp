/**
* @author Sharynne Azhar
* @file helper.cpp
* @since 05 October 2016
* @brief File containing helper methods
*/

#include "helper.h"

void printBanner() {
	std::ifstream file("banner.txt");
	std::string lines = "";
	if (file) {
		while (file.good()) {
			std::string eachLine;
			std::getline (file , eachLine);
			eachLine += "\n";
			lines += eachLine;
		}
		std::cout << lines;
	} else {
		std::cout << "Couldn't read file.";
	}
}

void printMenu() {
  std::cout << "\n=============================" << std::endl;
  std::cout << "1) Display the current day" << std::endl;
  std::cout << "2) Display the current week" << std::endl;
  std::cout << "3) Display the current month" << std::endl;
  std::cout << "4) Display the current year" << std::endl;
  std::cout << "5) Create an event" << std::endl;
  std::cout << "6) Remove an event" << std::endl;
  std::cout << "7) Quit" << std::endl;
  std::cout << "=============================" << std::endl;
}

void initMonths(Month months[10]) {
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

int getNumDaysWithEvents() {
  int num = 0;
  char check=' ';
  std::ifstream inp;
  inp.open("Detail.txt");

  while(!inp.eof()) {
    while(check != '\n' && !inp.eof()) {
      check = inp.get();
    }
    check = ' ';
    num++;
  }

  inp.close();
  return num;
}

void getDaysWithEvents(Day* DayArr, int size) {
  std::ifstream inputFile;
  string Month = "";
  string Detail = "";
  int Day = 0;
  int Year = 0;
  char x = ' ';

  inputFile.open("Detail.txt");

  if (inputFile.good()) {
    for (int i = 0; i < size; i++) {
      if (x != '\n') {
        inputFile >> Month >> Day >>Year;
        while( x != '\n' && !inputFile.eof()) {
          x = inputFile.get();
          if (x != '\n') {
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

void storeEvents(Day *DayArr, int size, Day CurrentDate, bool overlap) {
  std::ofstream outputFile;
  outputFile.open("Detail.txt");

  for (int i = 0; i < size; i++) {
    if (DayArr[i].getMonth() != "" || DayArr[i].getDate() != 0 || DayArr[i].getYear() != 0) {
      outputFile << DayArr[i].getMonth() << " " << DayArr[i].getDate() << " " << DayArr[i].getYear() << " " << DayArr[i].getDetail() << '\n';
    }
  }

  outputFile.close();
}

/**
* @pre None.
* @post Removes events from a day
* @return None.
*/
void removeEvents(Day *DayArr, int size, std::string date, Day CurrentDate) {
  std::string month = date.substr(0,3);
  int day = std::stoi(date.substr(4,5));
  for (int i = 0; i < size; i++) {
    if (DayArr[i].getMonth() == month && DayArr[i].getDate() == day) {
      std::cout << DayArr[i].getDetail() << std::endl;
      DayArr[i].setDetail("");
      std::cout<< DayArr[i].getDetail() << std::endl;
      storeEvents(DayArr, size, CurrentDate, false);
      return;
    }
  }
  std::cout<< "No note was found on that date.\n";
}
