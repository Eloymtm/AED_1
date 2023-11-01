#ifndef UNTITLED_DATA_H
#define UNTITLED_DATA_H

#include <iostream>
#include <set>
#include "Student.h"

class Data {
public :
    std::set<Student> allStudents;

    void addAllStudents(Student student);

    void printAllStudents();

};



#endif //UNTITLED_DATA_H