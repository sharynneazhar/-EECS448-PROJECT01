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
    bool note;//Does it have a note/description?
    
    public:
    Day();
    Day(const int Date, char Week, bool note);
    void setDate(const int Date);
    void setWeek(const char Week);
    void setNote(bool note);
    int getDate();
    char getWeek();
    bool getNote();
    //set and get functions
    
};

#endif