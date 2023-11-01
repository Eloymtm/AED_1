#ifndef UNTITLED_DATA_H
#define UNTITLED_DATA_H

#include <iostream>
#include <set>
#include <map>
#include "Student.h"
#include "ClassandUc.h"

class Data {
public :
    std::set<Student> allStudents;
    std::multimap <ClassAndUC, Student> studentClasses;
    std:: map <UC, Class> ucClass;
    void addAllStudents(Student student);
    void printAllStudents();
    void addStudentsClasses(ClassAndUC uc, Student student);
    void searchbyUc(std::string UC);
    //void addUcClass(UC uc, Class class_);
};



#endif //UNTITLED_DATA_H
