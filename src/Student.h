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
    Student();
    std::string getname() const;
    std::string getupcode();
    //void addToAllStudents ();
    //void printAllStudents();

    std::set<std::string> ucs;
    //std:: set <Student> allStudents;
    std::vector<std::pair<UC,Class>> classuc;
    static std::pair<UC,Class> createpair(UC u1, Class c1);
    bool operator<(const Student& s) const;
    //std::vector<std::Slot> schedule;
};


#endif //UNTITLED_STUDENT_H
