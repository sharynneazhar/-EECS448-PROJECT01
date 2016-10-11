/**
* @author Sharynne Azhar
* @file Helper.h
* @since 05 October 2016
* @brief Header of the file container helper functions
*/

#ifndef HELPER_H
#define HELPER_H

#include "Month.h"
#include "Print.h"
#include "Day.h"
#include "Month.h"
#include "Event.h"
#include "NoteReader.h"

#include <string>
#include <iostream>
#include <fstream>

/**
*	@pre None.
*	@post Outputs the banner to the console
*	@return None.
*/
void printBanner(std::string filename);

/**
*	@pre None.
*	@post Outputs the menu to the console
*	@return None.
*/
void printMenu();

/**
*	@pre None.
*	@post Initializes the months to the values for the 2016/2017 academic year
*	@return None.
*/
void initMonths(Month months[10]);

/**
* @pre None.
* @post Read through the file to check how many days have details.
* @return Number of days with details.
*/
int getNumDaysWithEvents();

/**
* @pre None.
* @post Builds a Day array with days from the input file with the details
* @return None.
*/
void getDaysWithEvents(Day* daysWithEvents, int size);

/**
* @pre None.
* @post Stores the events to the output file
* @return None.
*/
void storeEvents(Day *daysWithEvents, int size, Day currentDay, bool overlap);

/**
* @pre None.
* @post Removes events from a day
* @return None.
*/
void removeEvents(Day *daysWithEvents, int size, std::string date, Day currentDay);

#endif
