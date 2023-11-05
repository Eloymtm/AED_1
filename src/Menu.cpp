
#include "Menu.h"

using namespace std;

void Menu::run(){
    Data objStudent = Data();
    readStudents(objStudent);
    objStudent.addStudentsPerUc();
    mainMenu(objStudent);

}
void Menu::mainMenu(Data &objStudent){
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


        switch(opção){

            case 1:
                MenuStudents(objStudent);
                wait(objStudent);
                break;
           // case 2:

                //MenuTurmas();
               // MenuStudents();
               // mainMenu();
                //break;
        case 2:
            MenuSchedule(objStudent);
            wait(objStudent);
            break;
        case 3:
            resgisteredStudents(objStudent);
            wait(objStudent);
            break;
        case 4:

            request();
            mainMenu(objStudent);
            wait(objStudent);
            break;
        case 5:
            // chamar função que guarda requests  se houver requests
            break;
        case 6:
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
    cout << "|      5.At least n Uc's:                |\n";
    cout << "|      6.UCs with more Students:         |\n";
    cout << "|________________________________________|\n";
    cout << "Your option:";
    int option = 0;
    std:: cin >> option;

    /*while(true){
        switch(option){
            case 1:
            {
                obj.printAllStudents();
                break;
            }
            case 2:
            {
                string uc_;
                cout << "Insert UC:";
                cin >> uc_;
                obj.searchByUc(uc_);
                break;
            }
            case 3:
            {
                string class_;
                cout << "Insert Class: ";
                cin >> class_;
                obj.searchByClass(class_);
                break;
            }
            case 4:
            {
                char year;
                cout << "Insert year:";
                cin >> year;
                int n = 0;
                obj.searchByYear(year,n, 0);
                break;
            }
            case 5:
            {
                int o;
                cout << "Number of n Uc's:";
                cin >> o;
                obj.UCcount(obj);
                obj.nNumbers(o);
                break;
            }
            case 6:
                int n;
                cout << "Number of Uc's: ";
                cin >> n;
                obj.nUcsWithStudentsPerUc(n);
                break;
        }
    }*/
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
            string class_, uc;
            cout << "Insert Class: ";
            cin >> class_;
            cout << "Insert UC: ";
            cin >> uc;
            obj.searchByClass(class_, uc);

    }
  else if (option == 4){
        char year;
        cout << "Insert year:";
        cin >> year;
        int n = 0;
        obj.searchByYear(year,n, 0);
    }
    else if(option == 5){
        int o;
        cout << "Number of n Uc's:";
        cin >> o;
        obj.UCcount(obj);
        obj.nNumbers(o);
    }
    else if (option == 6)
    {
        int n;
        cout << "Number of Uc's: ";
        cin >> n;
        obj.nUcsWithStudentsPerUc(n);
    }

    
}


void Menu::MenuSchedule(Data& obj) {
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
            Classfind(obj);
            break;
        case 2:
            cout<< "UpCode:";
            Stfind(obj);
            break;
        case 3:
            break;
    }
}

void Menu::Classfind(Data &obj){
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
    obj.createschedulec(classuc, schedule, cl);
    input.close();
}

void Menu::Stfind(Data &obj) {
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
    //vector<Slot> schedule;
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
    obj.createschedules(classucst, schedule, st);

    input.close();
    input2.close();
}


        /*void Menu::MenuTurmas(){
            cout << "__________________________________________\n";
            cout << "|              ClassesMenu               |\n";
            cout << "|________________________________________|\n";
            readTurmas();

        }*/
        /*void Menu::readTurmas(){
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
                    Slot slot = Slot(classCode, weekday,start,duration,type);
                    schedule.push_back(slot);
                }
                string cl;
                cin >> cl;
                Schedule::createvector(classuc, schedule, cl);

                for (auto x: classuc){
                    cout << x.first << " " << x.second <<endl;
                }
                for (auto y: schedule){
                    cout << y.getccode() << " " << y.getweekday() << " " << y.getstart() << " " << y.getduration() << " " << y.gettype() << endl;}
                input.close();
            }*/
    void Menu::MenuUC(){

        cout << "__________________________________________\n";
        cout << "|                 UCMenu                 |\n";
        cout << "|________________________________________|\n";
        readUC();

    }
    void Menu::readUC(){
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
            ucs1.push_back(u);
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


void Menu:: request(){

    cout << "__________________________________________\n";
    cout << "|          Student Requests              |\n";
    cout << "|________________________________________|\n";
    cout << "|                                        |\n";
    cout << "|      1.Add UC                          |\n";
    cout << "|      2.Add Class                       |\n";
    cout << "|      3.Remove UC                       |\n";
    cout << "|      4.Remove Class                    |\n";
    cout << "|      5.SWitch UC                       |\n";
    cout << "|      6.SWitch Class                    |\n";
    cout << "|________________________________________|\n";
    cout << "Your option:";
    int option;
    cin >> option;

    if (option == 1){
        string ucode, new_uc;
        cout << "Student Code: " << endl;
        cin >> ucode;
        cout << "UC to add: " << endl;
        cin >> new_uc;

    }
}

void Menu::saveStudent(){
                ofstream output("../input/classes.csv");
                output.clear();
                output << "ClassCode,UcCode,Weekday,StartHour,Duration,Type\n";
                for(int i = 0;i < classuc.size();i++){
                    output << classuc[i].second.getclassCode() << " "<< classuc[i].first.getUC()<<  " " << schedule[i].getweekday() << " "<< schedule[i].getstart()<< " " << schedule[i].getduration()<< " " << schedule[i].gettype() << endl;
                }
                output.close();
    }

void Menu::wait(Data &objStudent) {
        string o;
    cout << "Press ENTER to continue...";
    cin.get(); // Aguarda a entrada de uma tecla
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    mainMenu(objStudent);
}

