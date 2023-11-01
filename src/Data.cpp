#include "Data.h"



void Data:: addAllStudents(Student student) {
    this->allStudents.insert(student);
}

void Data:: printAllStudents(){

    for (auto x: allStudents){

        std:: cout << x.getname() << " " << x.getupcode() << std:: endl;
    }
}