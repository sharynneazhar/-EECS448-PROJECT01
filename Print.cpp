/**
* @author Andrew Thomas, Katie Hrenchir, Mac Crider, Yehan Li
* @file Print.cpp
* @since 15 September 2016
* @brief Functionality of the Print class. Handles printing of various calendar views to the console
*/

#include "Print.h"

Print::Print() {}

Print::Print(Month monthsArr[]) {
	months = monthsArr;
}

void Print::printYear() {
	for (int j = 0; j <= 9; j++) {
		int firstDay = months[j].getStartDay();
		int totalDays = months[j].getNumDays();

		std::cout << "\n\n" << "\e[1m " << months[j].getMonthName() << "\e[0m" << std::endl;
		std::cout << "\n Sun  Mon  Tue  Wed  Thu  Fri Sat  " << std::endl;

		for (int i = 0; i < 7; i++) {
			//print first line of calendar
			if (i >= firstDay) {
				noteCheck(i - firstDay + 1, j);
				std::cout << "  " << i-firstDay+1 << "\e[0m" ;
				if (i == 6) {
					std::cout<< "\n";
				} else {
					std::cout<< "  ";
				}
			} else {
				//5 spaces total: 3 for the day width, and 1 on either end
				std::cout << "     ";
			}
		}

		//prints the remaining lines of the calendar
		int tempDay = 0;
		for (int i = (7 - firstDay + 1); i <= totalDays; i++){
			if (i < 10) {//spacing for single digit numbers:
				noteCheck(i, j);
				std::cout << "  " << i <<"\e[0m" << "  ";
			} else { //spacing for double digit numbers:
				noteCheck(i, j);
				std::cout << " "  << i <<"\e[0m" << "  ";
			}
			tempDay++;
			if (tempDay > 6) {
				std::cout << "\n";
				tempDay = 0;
			}
		}

	}
}

void Print::printMonth(int monthNumber) {
	std::cout << "\n\n";
	int firstDay = months[monthNumber].getStartDay();
	int totalDays = months[monthNumber].getNumDays();
	std::cout << " Sun  Mon  Tue  Wed  Thu  Fri Sat  " << std::endl;

	for (int i = 0; i < 7; i++) {
		//print first line of calendar
		if (i >= firstDay) {
			std::cout << "  " << i - firstDay + 1;
			if (i == 6) {
				std::cout << "\n";
			} else {
				std::cout << "  ";
			}
		} else {
			//5 spaces total: 3 for the day width, and 1 on either end
			std::cout << "     ";
		}
	}

	//prints the remaining lines of the calendar
	int tempDay = 0;
	for (int i = (7 - firstDay + 1); i <= totalDays; i++) {
		if (i < 10) { //spacing for single digit numbers:
			std::cout << "  " << i << "  ";
		} else { //spacing for double digit numbers:
			std::cout << " "  << i << "  ";
		}
		tempDay++;
		if (tempDay > 6){
			std::cout << "\n";
			tempDay = 0;
		}
	}
}

void Print::noteCheck(int date, int monthNumber) {
	Day* daysArr = months[monthNumber].getDays();
	if (daysArr[date + 1].notePresent() == true ) {
		//std::cout<< "\e[31m" ;
	}
	//delete daysArr;
}

void Print::printWeek(int currentDay, std::string currentMonth, int currentYear) {
	std::cout << "\n------------------------------------\n";
	std::cout << "Current Year: " << currentYear << std::endl;
	std::cout << "Current Month: " << currentMonth << std::endl;
	std::cout << "------------------------------------\n";

	if (currentMonth == "Aug") {
		weekDisplay(currentDay,0);
	} else if (currentMonth == "Sep") {
		weekDisplay(currentDay,1);
	} else if (currentMonth == "Oct") {
		weekDisplay(currentDay,2);
	} else if (currentMonth == "Nov") {
		weekDisplay(currentDay,3);
	} else if (currentMonth == "Dec") {
		weekDisplay(currentDay,4);
	} else if (currentMonth == "Jan") {
		weekDisplay(currentDay,5);
	} else if (currentMonth == "Feb") {
		weekDisplay(currentDay,6);
	} else if (currentMonth == "Mar") {
		weekDisplay(currentDay,7);
	} else if (currentMonth == "Apr") {
		weekDisplay(currentDay,8);
	} else if (currentMonth == "May") {
		weekDisplay(currentDay,9);
	}
	std::cout << "------------------------------------\n";
}

void Print::weekDisplay(int date, int month) {
	int count = months[month].getStartDay();
	for (int i = 1; i <= months[month].getNumDays(); i++) {
		if (date == i) {
			i = 100;
		} else {
			if (count < 6) {
				count++;
			} else {
				count = 0;
			}
		}
	}

	if (date + (7 - count) > months[month].getNumDays()) {
		int Num = 0;
		std::cout << " Sun  Mon  Tue  Wed  Thu  Fri  Sat " << std::endl;
		for (int i = 0; i < 7; i++) {
			//date of sunday in the week surrounding the current day.
			if (date - count + i <= months[month].getNumDays()) {
				std::cout << "   " << date - count+i<<"  ";
				Num++;
			} else {
				for (int i = 1; i <= (7 - Num); i++) {
					std::cout << "   " << i << "   ";
				}
				i = 100;
			}
		}
	} else if (date - count < 0) {
		if (month == 0 && date < 2) {
			std::cout << "Part of this week is in July, display is out of range!!!" << std::endl;
		} else {
			int LastMonDay = months[month-1].getNumDays();
			std::cout << " Sun  Mon  Tue  Wed  Thu  Fri  Sat  " << std::endl;
			for (int i = 0; i <= count - date; i++) {
				std::cout << "  " << LastMonDay + (date - count) + i << "  ";
			}
			for (int i = 1; i <= (7 - count); i++) {
				std::cout << "  " << i << "  ";
			}
		}
	} else {
		std::cout << " Sun  Mon  Tue  Wed  Thu  Fri  Sat  " << std::endl;
		for (int i = 0 ; i < 7 ; i++) {
			//date of sunday in the week surrounding the current day.
			if (date - count + i < 1) {
				std::cout << "     ";
			} else {
				std::cout << "  " << date-count+i<<"  ";
			}
		}
	}
	std::cout << std::endl;
}
//Two casese: 1,the current week is in one month 2, the current week is in two months.
//D+ (7-count)>total mumber of days in that month-> display days included in the next month.


void Print::printDay(int day, int month) {
	// error checking for an invalid date
	if (day < 0 || day > months[month].getNumDays() || month < 0 || month > 10) {
		std::cout << "Invalid date chosen\n";
		return;
	}

	// pull the week variable from the day in question and translate that into a word to output to the console
	switch (months[month].days[day - 1].getWeek()) {
		case 0:
			std::cout<<"Sunday, ";
			break;
		case 1:
			std::cout<<"Monday, ";
			break;
		case 2:
			std::cout<<"Tuesday, ";
			break;
		case 3:
			std::cout<<"Wednesday, ";
			break;
		case 4:
			std::cout<<"Thursday, ";
			break;
		case 5:
			std::cout<<"Friday, ";
			break;
		case 6:
			std::cout<<"Saturday, ";
			break;
		default:
			std::cout<<"Invalid date chosen\n";
			return;
	}

	//pulls the input month for the name of the month for output into the console
	switch (month) {
		case 0:
			std::cout<<"August ";
			break;
		case 1:
			std::cout<<"September ";
			break;
		case 2:
			std::cout<<"October ";
			break;
		case 3:
			std::cout<<"November ";
			break;
		case 4:
			std::cout<<"December ";
			break;
		case 5:
			std::cout<<"January ";
			break;
		case 6:
			std::cout<<"February ";
			break;
		case 7:
			std::cout<<"March ";
			break;
		case 8:
			std::cout<<"April ";
			break;
		case 9:
			std::cout<<"May ";
			break;
		default:
			std::cout<<"Invalid date chosen\n";
			break;
	}

	//pulls the input date for output into the console
	std::cout << day << ", ";

	//correlates the month variable for outputting the year to the console
	if (month <= 4) {
		std::cout<<"2016\n\n";
	} else {
		std::cout<<"2017\n\n";
	}

	//pulls the note bool from the specific Day object in question to output either a notification that there is no note on the date yet or the notes for the date
	if (months[month].days[day - 1].notePresent()) {
		std::cout << "Notes for today:\n" << months[month].days[day - 1].getNote();
	} else {
		std::cout << "No notes for this date";
	}
}

void Print::printDetail(Day* daysWithEvents, int size, Day currentDay) {
	bool dateMatch, monthMatch;
	std::cout << "\nToday's Agenda";
	std::cout << "\n---------------\n";
	for (int i = 0; i < size - 1; i++) {
		dateMatch = currentDay.getDate() == daysWithEvents[i].getDate();
		monthMatch = currentDay.getMonth() == daysWithEvents[i].getMonth();
		if (dateMatch && monthMatch) {
			std::cout << "-" << daysWithEvents[i].getDetail() << std::endl;
			i = size + 1;
		} else {
			std::cout << "-" << currentDay.getDetail() << std::endl;
			i = size + 1;
		}
	}
}
