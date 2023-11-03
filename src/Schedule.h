#ifndef UNTITLED_SCHEDULE_H
#define UNTITLED_SCHEDULE_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include "Menu.h"
#include <stack>

class Schedule{
public:
    Schedule(std::string uccode, std::string weekday, std::string start, std::string duration, std::string type);
    std::string getweekday();
    std::string getstart();
    std::string getduration();
    std::string gettype();
    std::string getuccode();
    std::string uccode;
    std::string weekday;
    std::string start;
    std::string duration;
    std::string type;
    static void createschedulec(std::vector<std::pair<UC, Class>> classuc, std::vector<Slot> schedule, std::string cl);
    static void createschedules(std::vector<Student> classucst, std::vector<Slot> schedule, std::string st);
    static std::stack<Schedule> scheduleStack;
};
#endif //UNTITLED_SCHEDULE_H
