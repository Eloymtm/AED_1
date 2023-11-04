#ifndef UNTITLED_DATA_H
#define UNTITLED_DATA_H

#include <iostream>
#include <set>
#include <map>
#include "Student.h"
#include "ClassandUc.h"
#include <vector>
#include <utility>
#include <list>
#include <algorithm>



class Data {
public :
    std::vector<Student> student;
    std::set<Student> allStudents;
    std::multimap <ClassAndUC, Student> studentClasses;
    std::map <UC, Class> ucClass;
    std::map<UC, int> mStudentsPerUC;
    std::vector<std::pair<UC, int>>studentsPerUC;
    std::map<ClassAndUC, int> mStudentsPerClass;
    std::vector<std::pair<ClassAndUC, int>>  studentPerClass;
    std::vector<std::pair<Student, int>> count;
    void addAllStudents(Student student);
    void printAllStudents();
    void UCcount(Data &obj);
    void nNumbers(int o);
    void addStudentsClasses(ClassAndUC uc, Student student);
    void addStudentsPerUc();
    void addStudentsPerClass();
    void searchByUc(std::string UC);
    void searchByClass(std::string class_, std:: string uc);
    void searchByYear(char year, int &n, int flag);
    int ucOccupation(std::string uc);
    int classOccupation(std::string class_);
    int yearOccupation(char year);
    void nUcsWithStudentsPerUc(int n);
    void studentsClassesPerClasses(std:: string Class);
    int ucsPerStudent(std::string studentCode);
    void requestAddUc(std::string studentCode, std::string new_uc );




    //void addUcClass(UC uc, Class class_);
};



#endif //UNTITLED_DATA_H

