/**
* @author Sharynne Azhar
* @file helper.cpp
* @since 05 October 2016
* @brief File containing helper methods
*/

#include "helper.h"

void printBanner(std::string filename) {
	std::ifstream file(filename);
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
  std::cout << "\n==============================" << std::endl;
  std::cout << "1) Display the current day" << std::endl;
  std::cout << "2) Display the current week" << std::endl;
  std::cout << "3) Display the current month" << std::endl;
  std::cout << "4) Display the current year" << std::endl;
  std::cout << "5) Create an event" << std::endl;
  std::cout << "6) Remove an event" << std::endl;
  std::cout << "7) Quit" << std::endl;
  std::cout << "==============================" << std::endl;
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
  string check="";
  std::ifstream inp;
  inp.open("events.txt");

  while(!inp.eof()) {
    std::getline(inp, check);
    if(check.length() > 0) {
	    num++;//counts line as long as the line is not empty
    }
  }
  inp.close();
  return num;
}

void getDaysWithEvents(Day* daysWithEvents, int size) {
  std::ifstream inputFile;
  string Month = "";
  string Detail = "";
  int Day = 0;
  int Year = 0;
  int arrPos=0;
  string events;

  inputFile.open("events.txt");

  if (inputFile.good()) {
	  while(!inputFile.eof()) {
		std::getline(inputFile, events);//getting events one line at a time
		if(events.length() > 0) { //ignores empty lines
			Year = std::stoi(events.substr(0,4));//based on start date
			Month =  events.substr(4,3);//based on start date
			Day = std::stoi(events.substr(7,2));//based on start date
			for(int i=10; i<events.length(); i++) {//details are the rest of the info
				Detail = Detail + events.at(i);
			}
			//fills array
			daysWithEvents[arrPos].setDay(Day);
			daysWithEvents[arrPos].setMonth(Month);
	          daysWithEvents[arrPos].setYear(Year);
	          daysWithEvents[arrPos].setDetail(Detail);
			arrPos++;//moves through array
			Detail="";//clears all info in the detail string for the next event
		}
	  }
  }
  inputFile.close();
}

void storeEvents(Event event) {
  std::ofstream outputFile;
  outputFile.open("events.txt", std::ios_base::app);
	outputFile << event.getStartDate().year << event.getStartDate().month << event.getStartDate().day << ","
						 << event.getEndDate().year << event.getEndDate().month << event.getEndDate().day << ","
						 << event.getStartTime() << ","
						 << event.getEndTime() << ","
						 << event.getName() << ","
						 << event.getDesc() << ",";

	if (event.getRepeatSchedule() != "") {
		outputFile << event.getRepeatSchedule() << ","
							 << event.getRepeatDays() << ",";
	}
	outputFile << "\n";
  outputFile.close();
}

void removeEvents(Day *daysWithEvents, int size, std::string date, Day currentDay) {
  std::string month = date.substr(0,3);
  int day = std::stoi(date.substr(4,5));
  bool doneDeleted=false;
  std::string parsing="";
  ifstream theFile;
  ofstream newFile;
  theFile.open("events.txt");
  newFile.open("temp.txt");
  while(!theFile.eof()) {
	  std::getline(theFile, parsing);//gets events one line at a time
	  if(parsing.length() > 0) {//ignores empty lines
		  if(parsing.substr(4,3) == month && std::stoi(parsing.substr(7,2)) == day) {//checks that the event's start date matches current date
		  															//if so, ignores that event
     		  doneDeleted = true;
     	  } else {//otherwise, transfers event to the new file
     		  newFile<<parsing<<'\n';
     	  }
	  }
  }
  newFile.close();
  theFile.close();
  std::remove("events.txt");//deletes old event text file
  rename("temp.txt", "events.txt");//renames new file with the name of the old file
  if(doneDeleted == false)//prints error message if no note was found
  {
	  std::cout<< "No note was found on that date.\n";
  }
}
