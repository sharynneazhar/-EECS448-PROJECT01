/**
* @author Erin Coots
* @file Event.h
* @since 10 October 2016
* @brief Header of the Event class.
*/

#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

struct Date {
  int day;
  string month;
  int year;
};

class Event{

    private:
      string name;
      string description;
      struct Date startDate;
      struct Date endDate;
      int startTime;
      int endTime;
      string repeatSchedule;
      string repeatDays;

      //string repeatSchedule;
      //string repeatDays;

    public:
      /**
      *  @pre None.
      *  @post Constructs a Event class object with empty name and description,
      *        empty start and end date, 0 start and end times
      *  @return Event class object
      */
      Event();

      /**
      *  @pre None.
      *  @post Constructs a Event class object with the given arguments for name,
      *        description, start and end dates, start and end times
      *  @return Event class object
      */
      Event(string n, string desc, const int sd, const int sy, string sm,
        const int ed, const int ey, string em, const int start, const int end);

      /**
      *  @pre None.
      *  @post Sets the name variable.
      *  @return None.
      */
      void setName(string n);

      /**
      *  @pre None.
      *  @post None.
      *  @return Name value
      */
      string getName();

      /**
      *  @pre None.
      *  @post Sets the description variable.
      *  @return None.
      */
      void setDesc(string desc);

      /**
      *  @pre None.
      *  @post None.
      *  @return Description value
      */
      string getDesc();

      /**
      *  @pre None.
      *  @post Sets the start date variable.
      *  @return None.
      */
      void setStartDate(int day, string month, int year);

      /**
      *  @pre None.
      *  @post None.
      *  @return Start date value
      */
      struct Date getStartDate();

      /**
      *  @pre None.
      *  @post Sets the end date variable.
      *  @return None.
      */
      void setEndDate(int day, string month, int year);

      /**
      *  @pre None.
      *  @post None.
      *  @return End date value
      */
      struct Date getEndDate();

      /**
      *  @pre None.
      *  @post Sets the start time variable.
      *  @return None.
      */
      void setStartTime(const int start);

      /**
      *  @pre None.
      *  @post None.
      *  @return Start time value
      */
      int getStartTime();

      /**
      *  @pre None.
      *  @post Sets the end time variable.
      *  @return None.
      */
      void setEndTime(const int end);

      /**
      *  @pre None.
      *  @post None.
      *  @return End time value
      */
      int getEndTime();

      /**
      *  @pre None.
      *  @post Sets the repeating schedule (weekly, biweekly, monthly)
      *  @return None.
      */
      void setRepeatSchedule(string sched);

      /**
      *  @pre None.
      *  @post None.
      *  @return The repeating schedule
      */
      string getRepeatSchedule();

      /**
      *  @pre None.
      *  @post Sets the repeating days (mondays, tuesdays, etc)
      *  @return None.
      */
      void setRepeatDays(string day);

      /**
      *  @pre None.
      *  @post None.
      *  @return The repeating days
      */
      string getRepeatDays();

      /**
      *  @pre None.
      *  @post None.
      *  @return Bool for if the Event is empty
      */
      bool isEmpty();

};

#endif
