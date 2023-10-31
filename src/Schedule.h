#ifndef UNTITLED_SCHEDULE_H
#define UNTITLED_SCHEDULE_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include "Menu.h"

class Schedule{
public:
    Schedule(std::string ccode, std::string weekday, std::string start, std::string duration, std::string type);
    std::string getweekday();
    std::string getstart();
    std::string getduration();
    std::string gettype();
    std::string getccode();
    std::string ccode;
    std::string weekday;
    std::string start;
    std::string duration;
    std::string type;
    static void createvector(std::vector<std::pair<UC, Class>> classuc, std::vector<Slot> schedule, std::string cl);
};
#endif //UNTITLED_SCHEDULE_H
