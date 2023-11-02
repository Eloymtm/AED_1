#include "Schedule.h"

class stack;

using namespace std;

Schedule::Schedule(string uccode, string weekday, string start, string duration, string type) {
    this->uccode = uccode;
    this->weekday = weekday;
    this->start = start;
    this->duration = duration;
    this->type = type;
}
string Schedule::getuccode() {
    return this->uccode;
}
string Schedule::getweekday(){
    return this->weekday;
}
string Schedule::getstart(){
    return this->start;
}
string Schedule::getduration(){
    return this->duration;
}
string Schedule::gettype(){
    return this->type;
}
void Schedule::createschedulec(vector<std::pair<UC, Class>> classuc, vector<Slot> schedule, string cl){
    vector<Schedule> schedulef;
    for(auto x: classuc){
        if(x.second.getclassCode() == cl) {
            for (auto y: schedule) {
                if (y.getccode() == cl) {
                    Schedule sch = Schedule(x.first.getUC(), y.getweekday(), y.getstart(), y.getduration(), y.gettype());
                    schedulef.push_back(sch);
                    break;
                }
            }
        }
    }
    for(auto x : schedulef){
        cout<< x.getuccode() << " " << x.getweekday() << " " << x.getstart() << " " << x.getduration() << " " << x.gettype() << endl;
    }
}

void Schedule::createschedules(std::vector<Student> classucst, std::vector<Slot> schedule, std::string st){
    vector<Schedule> schedulef;
    for(auto x: classucst){
        if(x.getupcode() == st) {
            for (auto y: schedule) {
                if (y.getccode() == x.getccode() && y.getuccode() == x.getuccode()) {
                    Schedule sch = Schedule(x.getuccode(), y.getweekday(), y.getstart(), y.getduration(), y.gettype());
                    schedulef.push_back(sch);
                }
            }
        }
    }
    for(auto x : schedulef){
        cout<< x.getuccode() << " " << x.getweekday() << " " << x.getstart() << " " << x.getduration() << " " << x.gettype() << endl;
    }
}


