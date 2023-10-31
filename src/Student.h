#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H
#include <iostream>
#include <string>
#include <set>
#include <vector>

class UC{
public:
    std::string uCode;
    UC(std::string uCode);
    std::string getUC();
    friend std::ostream& operator<<(std::ostream& os, const UC& uc);

};
class Class{
public:
    std::string classCode;
    Class(std::string classCode);
    friend std::ostream& operator<<(std::ostream& os, const Class& c);
};

class Student {
public:
    std::string upcode;
    std::string name;
    Student(std::string name, std::string upcode);
    std::string getname();
    std::string getupcode();
    std::set<std::string> ucs;
    std::vector<std::pair<UC,Class>> classuc;
    static std::pair<UC,Class> createpair(UC u1, Class c1);
    //std::vector<std::Slot> schedule;
};
class Slot{
public:
    Slot(std::string weekday,std::string start, std::string duration,std::string type);
    std::vector<Slot> schedule;

    std::string getweekday();
    std::string getstart();
    std::string getduration();
    std::string gettype();
    std::string weekday;
    std::string start;
    std::string duration;
    std::string type;
};



#endif //UNTITLED_STUDENT_H
