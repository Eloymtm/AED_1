#include "Data.h"



void Data:: addAllStudents(Student student) {
    this->allStudents.insert(student);
}

void Data:: printAllStudents(){

    for (auto x: allStudents){

        std:: cout << x.getname() << " " << x.getupcode() << std:: endl;
    }
}

void Data:: addStudentsClasses(ClassAndUC const classes, Student student)
{
    this->studentClasses.insert(std::pair<ClassAndUC, Student> (classes, student));
}

void Data:: searchByUc(std::string UC){
    for(auto x: studentClasses)
    {
        if(x.first.getUcCode() == UC)
            std:: cout << x.second.getname() << std:: endl;
    }
}
void Data:: searchByClass(std::string class_){
    for(auto x: studentClasses)
    {
        if(x.first.getClassCode() == class_)
            std:: cout << x.second.getname() << std:: endl;
    }
}

/*void Data::searchByYear(std::string year){
    int y = 0;
    for(auto x: studentClasses)
    {
        if(x.first.getUcCode() == UC and x.first.getClassCode() == )

    }
}*/
