#include "Data.h"
#include <utility>

void Data:: addAllStudents(Student student) {
    this->allStudents.insert(student);
    this->student.push_back(student);
}

void Data:: addSchedule(Slot s){
    this->schedule.push_back(s);
}
void Data:: printS(){
    for (auto x: schedule){
        std::cout << x.gettype() << std::endl;
    }
}

void Data:: printAllStudents(){

    for (auto x: allStudents){

        std:: cout << x.getname() << " " << x.getupcode() << std:: endl;
    }
}

void Data:: addStudentsClasses(ClassAndUC classes, Student student)
{
    this->studentClasses.insert(std::pair<ClassAndUC, Student> (classes, student));
}

void Data:: addStudentsPerUc(){
    for(auto x: studentClasses){
        std::string temp = x.first.getUcCode();

        mStudentsPerUC.insert(std::pair <UC, int>(temp, ucOccupation(temp)));
    }
}
void Data:: addStudentsPerClass(){
    for(auto x : studentClasses)
    {
        mStudentsPerClass.insert(std::pair<ClassAndUC, int>(x.first , classOccupation(x.first.getClassCode())));
    }

}

void Data:: searchByUc(std::string UC){
    int found = 0;
    for(auto x: studentClasses)
    {
        if(x.first.getUcCode() == UC){
            std:: cout << x.second.getname() << std:: endl;
            found = 1;
        }
    }
    if (found == 0)
        std::cout << "Not Found" << std::endl;
}
void Data:: searchByClass(std::string class_, std::string uc){
    int found = 0;
    for(auto x: studentClasses)
    {
        if(x.first.getClassCode() == class_ and x.first.getUcCode() == uc){
            std:: cout << x.second.getname() << std:: endl;
            found = 1;
        }
    }
    if(found == 0)
        std::cout << "Not Found" << std::endl;
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

void Data::searchByYear(char year, int &n, int flag){
    std :: set<std::string> studentsyear;
    int found =0;
    for(auto x: studentClasses)
    {
        std::string class_  = x.first.getClassCode();
        if(class_[0] == year)
        {
            studentsyear.insert(x.second.getname());
            found = 1;
        }
    }
    if(flag == 0){
        for(auto x : studentsyear)
            std:: cout << x << std:: endl;
    }
    else
        n = studentsyear.size();
    if(found == 0)
        std::cout << "Not Found" << std::endl;
}

int Data:: ucOccupation(std::string uc){
    int count = 0;
    for (auto x: studentClasses){
        if (x.first.getUcCode() == uc)
            count++;
    }
    return count;
}

int Data:: classOccupation(std::string class_){
    int count = 0;
    std::set<std::string> s;
    for (auto x: studentClasses){
        if (x.first.getClassCode() == class_)
            s.insert(x.second.getupcode());
    }
    return s.size();

}

int Data::yearOccupation(char year){
    int n = 0;
    searchByYear(year, n, 1);
    return n;
}

void Data::nUcsWithStudentsPerUc(int n){
    std::vector<std::pair<UC, int>> studentsPerUC(mStudentsPerUC.begin(), mStudentsPerUC.end());
    std::sort(studentsPerUC.begin(), studentsPerUC.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });
    for (int i = 0; i < n && i < studentsPerUC.size(); i++) {
        std::cout << "UC : " << studentsPerUC[i].first << ", has " << studentsPerUC[i].second << " students" <<std::endl;
    }

}
void Data:: studentsPerClasses(std:: string Class){
    std::vector<std::pair<ClassAndUC, int>> studentPerClass(mStudentsPerClass.begin(), mStudentsPerClass.end());
    std::sort(studentsPerUC.begin(), studentsPerUC.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });
    for (int i = 0; i < i < studentsPerUC.size(); i++) {
        std::cout << "UC : " << studentsPerUC[i].first << ", has " << studentsPerUC[i].second << " students" <<std::endl;
    }
}

void Data::createschedulec(std::vector<Slot> schedule, std::string cl){
    for(auto x: studentClasses){
        if(x.first.getClassCode() == cl) {
            for (auto y: schedule) {
                if (y.getccode() == cl) {
                    Schedule sch = Schedule(y.getuccode(), y.getweekday(), y.getstart(), y.getduration(), y.gettype());
                    schedulef.push_back(sch);
                }
            }
            break;
        }
    }

}
void Data::createschedules(std::vector<Student> classucst, std::vector<Slot> schedule, std::string st){

    for(auto x: classucst){
        if(x.getupcode() == st) {
            for (auto y: schedule) {
                if (y.getccode() == x.getccode() && y.getuccode() == x.getuccode()) {
                    Schedule sch = Schedule(x.getuccode(), y.getweekday(), y.getstart(), y.getduration(), y.gettype());
                    schedulef.push_back(sch);
                }
            }
        }
    }
    for(auto x : schedulef){
        std::cout<< x.getuccode() << " " << x.getweekday() << " " << x.getstart() << " " << x.getduration() << " " << x.gettype() << std::endl;
    }
}

int Data:: ucsPerStudent(std::string studentCode){
    int count = 0;
    for(auto x: studentClasses){
        if(x.second.getupcode() == studentCode)
            count++;
    }
    return count;
}


void Data::readTurmas(std::string uc, std::vector<Slot> &slots){
    std::ifstream input("../input/classes.csv");
    if(!input.is_open()){
        std::cout << "Error: Unable to open file 1 \n";
    }
    std::string line;
    getline (input, line);
    while(getline(input, line)){
        std::istringstream in (line);
        std::string classCode, ucCode, weekday, start, duration, type;
        getline(in,classCode, ',');
        getline(in, ucCode, ',');
        getline(in, weekday, ',');
        getline(in,start,',');
        getline(in, duration, ',');
        getline(in, type, ',');
        Slot s = Slot(ucCode, classCode, weekday,start,duration,type);
        if(ucCode == uc)
            slots.push_back(s);
    }
    input.close();
}


void Data::requestAddUc(std::string studentCode, std::string new_uc ) {
    int ucs = ucsPerStudent(studentCode);
    for (auto x: studentClasses) {
        if (x.second.getupcode() == studentCode and x.first.getUcCode() == new_uc) {
            std::cout << "Request Denied: Student already enrolled in this UC" << std::endl;
            return;
        }
    }
    bool studentExists = 0;
    for (auto x: allStudents) {
        if (x.getupcode() == studentCode)
            studentExists = 1;
    }
    if (!studentExists)
        std::cout << "Request Denied: Student not found" << std::endl;

    if (ucs >= 7) {
        std::cout << "Request Denied: Student already enrolled in 7 UC's" << std::endl;
        return;
    }
    int spaceInClass = 0;
    std::list<ClassAndUC> availableClasses;
    //student can only be enrolled to class if there are less than 30 students in that class
    for (auto x: studentPerClass) {
        if (x.first.getUcCode() == new_uc and x.second < 30) {
            availableClasses.push_back(x.first);
            spaceInClass++;
        }
    }
    if (spaceInClass == 0) {
        std::cout << "Request Denied: No Class with vacancies " << std::endl;
        return;
    }
    bool possible = 0;
    std:: vector<Slot> slots;

    for (auto x: availableClasses){
        readTurmas(x.getUcCode(), slots);
        for(auto x: schedulef){
            //if(x.getuccode() == new_uc)
        }
        if (possible == 1){
            //fica ja nesta turma e sai da função tem e de guardar a UC nova e mudar no vetor
            //mudar em studentsClasses
            break;
        }
    }

}



//void addUcClass(UC uc, Class class_)

