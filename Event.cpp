/**
* @author Erin Coots
* @file event.cpp
* @since 10 October 2016
* @brief Functionality of the event class.
*/

#include "Event.h"

using namespace std;

Event::Event(){
    name = "";
    description = "";
    startTime = 0;
    endTime = 0;
}

Event::Event(string n, string desc, const int sd, const int sy, string sm,
  const int ed, const int ey, string em, const int start, const int end){
    name = n;
    description = desc;
    startDate.day = sd;
    startDate.month = sm;
    startDate.year = sy;
    endDate.day = ed;
    endDate.month = em;
    endDate.year = ey;
    startTime = start;
    endTime = end;
}

void Event::setName(string n){
    name = n;
}

string Event::getName(){
    return name;
}

void Event::setDesc(string desc){
    description = desc;
}

string Event::getDesc(){
    return description;
}

void Event::setStartDate(int day, string month, int year){
    startDate.day = day;
    startDate.month = month;
    startDate.year = year;
}

struct Date Event::getStartDate(){
    return startDate;
}

void Event::setEndDate(int day, string month, int year){
    endDate.day = day;
    endDate.month = month;
    endDate.year = year;
}

struct Date Event::getEndDate(){
    return endDate;
}

void Event::setStartTime(const int start){
    startTime = start;
}

int Event::getStartTime(){
    return startTime;
}

void Event::setEndTime(const int end){
    endTime = end;
}

int Event::getEndTime(){
    return endTime;
}

void setRepeatSchedule(string sched) {
    repeatSchedule = sched;
}

int getRepeatSchedule() {
    return repeatSchedule;
}

void setRepeatDays(string day) {
    repeatDays = day;
}

int getRepeatDays() {
    return repeatDays;
}

bool Event::isEmpty(){
    if(name == ""){
      return true;
    }
    else{
      return false;
    }
}
