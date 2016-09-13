#include "Day.h"

Day:: Day(const int Date, int Year, char Week, bool Note)
{
    date=Date;
    week=week;
    note=Note;
    year=Year;
}

Day:: Day()
{
    date=0;
    week=' ';
    note=false;
    year=0;
}

void Day:: setDate(int Date)
{
    date=Date;
}

void Day:: setWeek(char Week)
{
    week=Week;
}

void Day:: setNote(bool Note)
{
     note=Note;
}

void Day:: setYear(int Year)
{
    year=Year;
}

int Day:: GetYear()
{
    return(year);
}

int Day:: getDate() const
{
    return(date);
}

char Day:: getWeek() const
{
    return(week);
}

bool Day:: getNote()
{
    return(note);
}
