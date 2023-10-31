#ifndef UNTITLED_SLOT_H
#define UNTITLED_SLOT_H
#include "Student.h"

class Slot{
public:
    Slot(std::string ccode, std::string weekday,std::string start, std::string duration,std::string type);
    std::vector<Slot> schedule;

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
};



#endif //UNTITLED_SLOT_H
