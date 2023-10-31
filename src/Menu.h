#ifndef UNTITLED_MENU_H
#define UNTITLED_MENU_H

#include <iostream>
#include <set>
#include <string>
#include <fstream>
#include <sstream>
#include "Student.h"
using namespace std;
class Menu {
public:
    void mainMenu();
    void run();
    void MenuStudents();
    void readStudents();
    void MenuTurmas();
    void readTurmas();
    vector<pair<UC,Class>> classuc;
    vector<Student> student;
};


#endif //UNTITLED_MENU_H
