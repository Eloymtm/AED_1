#ifndef UNTITLED_MENU_H
#define UNTITLED_MENU_H

#include <iostream>
#include <set>
#include <string>
#include <fstream>
#include <sstream>
#include "Student.h"
#include "Slot.h"
#include "Schedule.h"
#include <list>
using namespace std;
class Menu {
public:
    void mainMenu();
    void run();
    void MenuUC();
    void MenuStudents();
    void readStudents();
    void MenuTurmas();
    void readTurmas();
    void readUC();
    vector<pair<UC,Class>> classuc;
    vector<Student> student;
    set<UC> ucs;
};


#endif //UNTITLED_MENU_H
