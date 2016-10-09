/**
* @author Andrew Thomas, Katie Hrenchir, Mac Crider, Yehan Li
* @file Print.h
* @since 15 September 2016
* @brief Header of the Print class. Handles printing of various calendar views to the console
*/

#ifndef PRINT_H
#define PRINT_H

#include <string>
#include <iostream>
#include <fstream>

#include "Month.h"
#include "Day.h"

class Print {

	public:
		Print();

		/**
		*	@pre An array of Month class objects is available.
		*	@post Constructs a Print class object with the named Month array.
		*	@return Print class object.
		*/
		Print(Month monthsArr[]);

		/**
		*	@pre None.
		*	@post A standardized printout of the entire school year to the console
		*	@return None.
		*/
		void printYear();

		/**
		*	@pre None.
		*	@post A standardized printout of the chosen month to the console.
		*	@return None.
		*/
		void printMonth(int monthNumber);

		/**
		*	@pre None.
		*	@post Checks the days array for notes
		*	@return None.
		*/
		void noteCheck(int date, int monthNumber);

		/**
		*	@pre None.
		*	@post Sets up weekDisplay for the input date
		*	@return None.
		*/
		void printWeek(int currentDay, std::string currentMonth, int currentYear);

		/**
		*	@pre None.
		*	@post A standardized printout of the week (Sunday-Saturday) the chosen day is in to the console.
		*	@return None.
		*/
		//make this a private function?
		void weekDisplay(int date, int month);

		/**
		*	@pre None.
		*	@post Outputs the input date in the format "Sunday, January 1, 2017" and reports the notes attached to the day or the lask of notes to the console.
		*	@return None.
		*/
		void printDay(int day, int month);

		/**
		*	@pre None.
		*	@post Outputs the details of the date to the console.
		*	@return None.
		*/
		void printDetail(Day *daysWithEvents, int size, Day CurrentDay);

		//!> Array of Month objects
		Month* months;


};

#endif
