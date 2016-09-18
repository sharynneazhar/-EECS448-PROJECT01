/**
* @author Andrew Thomas, Katie Hrenchir, Mac Crider, Yehan Li
* @file Day.h
* @since 10 September 2016
* @brief Header of the Day class. Used as a node for the Month class.
*/

#ifndef DAY_H
#define DAY_H

#include <string>
#include <iostream>
#include <fstream>

#include "NoteReader.h"
 using namespace std;

class Day
{
    private:
    int date; //date
    int year; //year
    int week;// day of the week
    std::string month; //name of the month
    string detail;
    bool note;//Does it have a note/description?

    public:
    /**
    *  @pre None.
    *  @post Constructs a Day class object with 0 date, 0 year, 0 week, and 'false' note
    *  @return Day class object
    *
    */
    Day();

    /**
    *  @pre None.
    *  @post Constructs a Day class object with the given arguments for date, year, week, and note
    *  @return Day class object
    *
    */
    Day(const int Date, const int Year, int Week, std::string month, bool note);

    void setDetail(string De);
    bool WriteDetail(Day *DayArr, int size);//write detals to a txt file;
    string getDetail();//get the detail of a day.
    /**
    *  @pre None.
    *  @post Sets the date variable.
    *  @return None.
    *
    */
    void setDay(int Date);

    /**
    *  @pre None.
    *  @post Sets the week variable.
    *  @return None.
    *
    */
    void setWeek(int Week);

    /**
    *  @pre None.
    *  @post Sets the month variable.
    *  @return None.
    *
    */
    void setMonth(std::string month);

    /**
    *  @pre None.
    *  @post Sets the year variable.
    *  @return None.
    *
    */
    void setYear(const int Year);

    /**
    *  @pre None.
    *  @post Sets the note variable.
    *  @return None.
    *
    */
    void setNote(bool note);

    /**
    *  @pre None.
    *  @post None.
    *  @return Date value
    *
    */
    int getDate();

    /**
    *  @pre None.
    *  @post None.
    *  @return Week value
    *
    */
    int getWeek();

    /**
    *  @pre None.
    *  @post None.
    *  @return Returns the month variable (string).
    *
    */
    std::string getMonth();

    /**
    *  @pre None.
    *  @post None.
    *  @return Year value
    *
    */
    int getYear();

    /**
    *  @pre None.
    *  @post None.
    *  @return Note value
    *
    */
    bool notePresent();

    /**
    *  @pre There is a note present (note == true)
    *  @post None.
    *  @return The string of notes for the day
    *
    */
    std::string getNote();

    //set and get functions

    /**
    *  @pre None.
    *  @post None.
    *  @return Bool for if the input date is a valid calendar date
    *
    */
    bool DateTest(std::string month, int day, int year);
    bool isEmpty();

};

#endif
