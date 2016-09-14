#ifndef DAY_H
#define DAY_H

#include <string>
#include <iostream>
#include <fstream>

class Day
{
    private:
    int date;//date
    int year;//year
    char week;// day of the week
	std::string month;
    bool note;//Does it have a note/description?
    
    public:
    Day();
    Day(const int Date, const int Year, char Week, bool note);
	void setDay(int Date);
    void setDate(const int Date);
    void setWeek(const char Week);
	void setMonth(std::string month);
    void setYear(const int Year);
    void setNote(bool note);

    int getDate();
    char getWeek();
	std::string getMonth();
    int getYear();

    bool getNote();
    //set and get functions

    bool DateTest(std::string month, int day, int year);
    
};

#endif
