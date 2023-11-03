#include "Menu.h"

using namespace std;

void Menu::run(){
    mainMenu();
}
void Menu::mainMenu(){
    int opção = 0;

    cout << "__________________________________________\n";
    cout << "|                MainMenu                |\n";
    cout << "|        Choose one of the options       |\n";
    cout << "|________________________________________|\n";
    cout << "|      1. STUDENTS:                      |\n";
    cout << "|      2. SCHEDULE:                      |\n";
    cout << "|      3. REGISTERED STUDENTS:           |\n";
    cout << "|      4. REQUEST:                       |\n";
    cout << "|      5. SAVE AND QUIT:                 |\n";
    cout << "|      6. QUIT WITHOUT SAVING:           |\n";
    cout << "|________________________________________|\n";
    cout << "Your option:";
    cin >> opção;

    Data objStudent = Data();
    readStudents(objStudent);
    switch(opção){

        case 1:
            MenuStudents(objStudent);
            break;
        case 2:
            MenuSchedule();
            mainMenu();
            break;
        case 3:
            resgisteredStudents(objStudent);
            //mainMenu();
            break;
        case 4:
            //Request();
            mainMenu();
            break;
        case 5:
            break;
    }
}

void Menu::readStudents(Data &obj){

    ifstream input("../input/students_classes.csv");
    if(!input.is_open()){
        //perror("Error opening file"); -> acho que só deviamos usar uma
        cout << "Error: Unable to open file 2 \n";}
    string line;
    getline(input, line);

    while (getline(input, line))
    {
        istringstream in (line);
        string name_, number, uCode, classCode;
        getline(in,number,',');
        getline(in,name_,',');
        getline(in,uCode,',');
        getline(in,classCode,',');

        Student s = Student(name_, number);
        ClassAndUC c = ClassAndUC(classCode, uCode);

        obj.addAllStudents(s);
        obj.addStudentsClasses(c, s);

    }

    input.close();
}


void Menu::MenuStudents(Data &obj) {
    //readStudents(obj);
    cout << "__________________________________________\n";
    cout << "|              StudentsMenu              |\n";
    cout << "|________________________________________|\n";
    cout << "|                                        |\n";
    cout << "|      1.All Students                    |\n";
    cout << "|      2.Search by UC                    |\n";
    cout << "|      3.Search by Class                 |\n";
    cout << "|      4.Search by Year                  |\n";
    cout << "|________________________________________|\n";
    cout << "Your option:";
    int option = 0;
    std:: cin >> option;

    if(option == 1){
            obj.printAllStudents();
    }
    else if (option == 2){
            string uc_;
            cout << "Insert UC: ";
            cin >> uc_;
            obj.searchByUc(uc_);

    }
    else if (option == 3){
            string class_;
            cout << "Insert Class: ";
            cin >> class_;
            obj.searchByClass(class_);

    }
    else if (option == 4){
        char year;
        cout << "Insert year:";
        cin >> year;
        int n = 0;
        obj.searchByYear(year,n, 0);
    }
}


void Menu::MenuSchedule() {
    int opção = 0;
    cout << "__________________________________________\n";
    cout << "|              ScheduleMenu              |\n";
    cout << "|________________________________________|\n";
    cout << "|      1.Class Schedule                  |\n";
    cout << "|      2.Student Schedule                |\n";
    cout << "|________________________________________|\n";
    cin >> opção;
    switch (opção) {
        case 1:
            cout << "Class:";
            Classfind();
            break;
        case 2:
            cout<< "UpCode:";
            Stfind();
            break;
        case 3:
            break;
    }
}

void Menu::Classfind(){
    vector<pair<UC,Class>> classuc;
    vector<Slot> schedule;
    ifstream input("../input/classes.csv");
    if(!input.is_open()){
        cout << "Error: Unable to open file 1 \n";
    }
    string line;
    getline (input, line);
    while(getline(input, line)){
        istringstream in (line);
        string classCode, ucCode, weekday, start, duration, type;
        getline(in,classCode, ',');
        getline(in, ucCode, ',');
        getline(in, weekday, ',');
        getline(in,start,',');
        getline(in, duration, ',');
        getline(in, type, ',');
        UC u1 = UC(ucCode);
        Class c1 = Class(classCode);
        pair<UC,Class> copy = Student::createpair(u1, c1);
        classuc.push_back(copy);
        Slot slot = Slot(ucCode, classCode, weekday,start,duration,type);
        schedule.push_back(slot);
    }
    string cl;
    cin >> cl;
    Schedule::createschedulec(classuc, schedule, cl);
    input.close();
}

void Menu::Stfind() {
    vector<Student> classucst;
    ifstream input("../input/students_classes.csv");
    if(!input.is_open()){
        cout << "Error: Unable to open file 2 \n";}
    string line;
    getline(input, line);

    while (getline(input, line))
    {
        istringstream in (line);
        string name_, number, uCode, cCode;

        getline(in,number,',');
        getline(in,name_,',');
        getline(in,uCode,',');
        getline(in,cCode,',');

        Student copy = Student(uCode, cCode, number);
        classucst.push_back(copy);

    }
    vector<Slot> schedule;
    ifstream input2("../input/classes.csv");
    if(!input2.is_open()){
        cout << "Error: Unable to open file 1 \n";
    }
    string line2;
    getline (input2, line2);
    while(getline(input2, line2)){
        istringstream in (line2);
        string classCode, ucCode, weekday, start, duration, type;
        getline(in,classCode, ',');
        getline(in, ucCode, ',');
        getline(in, weekday, ',');
        getline(in,start,',');
        getline(in, duration, ',');
        getline(in, type, ',');

        Slot slot = Slot(ucCode, classCode, weekday,start,duration,type);
        schedule.push_back(slot);
    }
    string st;
    cin >> st;
    Schedule::createschedules(classucst, schedule, st);

    input.close();
    input2.close();
}

    void Menu::MenuUC(){

        cout << "__________________________________________\n";
        cout << "|                 UCMenu                 |\n";
        cout << "|________________________________________|\n";
        readUC();
    }
    void Menu::readUC(){
        list<UC> ucs;
        ifstream input("../input/classes_per_uc.csv");
        if(!input.is_open())
            cout << "Error: Unable to open file 3 \n";
        string line;
        getline (input, line);
        while(getline(input, line)){
            istringstream in (line);
            string classCode, ucCode;
            getline(in,classCode,',');
            getline(in, ucCode, ',');

            UC u = UC(ucCode);
            ucs.push_back(u);
        }
        for (auto x: ucs){
            cout << x << endl;
        }
        input.close();

}

void Menu::resgisteredStudents(Data &obj){

    cout << "__________________________________________\n";
    cout << "|          Registered Students           |\n";
    cout << "|________________________________________|\n";
    cout << "|                                        |\n";
    cout << "|      1.Search by UC                    |\n";
    cout << "|      2.Search by Class                 |\n";
    cout << "|      3.Search by Year                  |\n";
    cout << "|________________________________________|\n";
    cout << "Your option:";

    int option = 0;
    cin >> option;
    if(option == 1){
        cout << "Insert UC: ";
        string uc;
        cin >> uc;
        cout << obj.ucOccupation(uc);
    }
    else if (option == 2){
        cout << "Insert Class: ";
        string class_;
        cin >> class_;
        cout << obj.classOccupation(class_);
    }
    else if(option == 3){
        cout << "Insert Year: ";
        char year;
        cin >> year;
        cout << obj.yearOccupation(year);
    }
}
