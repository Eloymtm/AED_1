#include "Schedule.h"
using namespace std;

Schedule::Schedule(string ccode, string weekday, string start, string duration, string type) {
    this->ccode = ccode;
    this->weekday = weekday;
    this->start = start;
    this->duration = duration;
    this->type = type;
}
string Schedule::getccode() {
    return this->ccode;
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
void Schedule::createvector(vector<std::pair<UC, Class>> classuc, vector<Slot> schedule, string cl){
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
        cout<< x.getccode() << " " << x.getweekday() << " " << x.getstart() << " " << x.getduration() << " " << x.gettype() << endl;
    }
}
