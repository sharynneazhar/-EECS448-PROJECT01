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

class Print
{

	public:
	Print(Month monthsArr[]); //will take in multi dimensional array of months/days?
	void printYear();
	void printMonth(int monthNumber);
	void printWeek();
	void printDay();

	Month* months;

};

#endif
