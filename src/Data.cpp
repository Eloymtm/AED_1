#include "Data.h"
#include <utility>

void Data:: addAllStudents(Student student) {
    this->allStudents.insert(student);
    this->student.push_back(student);
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
void Data::UCcount(Data &obj){
    int u = 0,p = 0,max = 0;
    for(auto x : student){
        u++;
        if(x != student[0]){
        if(x.getname() != student[u-2].getname()){
            std::pair<Student, int> studentPair1 = std::make_pair(x, p);
            p = 0;
            count.push_back(studentPair1);
        }
        p++;
        if(max < p){
            max = p;
        }
        }
    }

}
void Data::nNumbers(int o){
    int sum = 0;
    for(auto x : count){
        if(x.second >= o){
            sum++;
        }
    }
    std::cout << sum<< std::endl;
}
bool Student::operator!=(Student s){
    if(this->getname() != s.getname()){
        return true;
    }
    return false;
}
/*void Data::searchByYear(std::string year){
    int y = 0;
    for(auto x: studentClasses)
    {
        if(x.first.getUcCode() == UC and x.first.getClassCode() == )

    }
}*/
