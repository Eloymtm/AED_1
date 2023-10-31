#include "Student.h"

using namespace std;

Student::Student(string name,string upcode){
    this->name = name;
    this->upcode = upcode;
}
UC::UC(std::string uCode) {
    this->uCode = uCode;
}
Class::Class(std::string classCode) {
    this->classCode = classCode;
}
string Student::getname(){
    return this->name;
}
string UC::getUC(){
    return this->uCode;
}
string Student::getupcode(){
    return this->upcode;
}
pair<UC,Class> Student::createpair(UC u1, Class c1){
    return make_pair(u1, c1);
}
ostream& operator<<(std::ostream& os, const UC& uc) {
    os << "UC value: " << uc.uCode;
    return os;
}
ostream& operator<<(std::ostream& os, const Class& c) {
    os << "UC value: " << c.classCode;
    return os;
}
Slot::Slot(string weekday,string start,string duration, string type) {
    this->weekday = weekday;
    this->start = start;
    this->duration = duration;
    this->type = type;
}
string Slot::getweekday(){
    return this->weekday;
}
string Slot::getstart(){
    return this->start;
}
string Slot::getduration(){
    return this->duration;
}
string Slot::gettype(){
    return this->type;
}