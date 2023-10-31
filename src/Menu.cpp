#include "Menu.h"





int language;
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
        cout << "|      2. CLASSES:                       |\n";
        cout << "|      3. UC:                            |\n";
        cout << "|      3. REQUEST:                       |\n";
        cout << "|      4. SAVE AND QUIT:                 |\n";
        cout << "|      5. QUIT WITHOUT SAVING:           |\n";
        cout << "|________________________________________|\n";
        cout << "Your option:\n";
        cin >> opção;

        Data objStudent = Data();
        switch(opção){

            case 1:
                MenuStudents(objStudent);
                break;
            case 2:
                //MenuTurmas();
                break;
            case 3:
                MenuUC();
                break;
            case 4:
                //Request();
                break;
            case 5:
                language = 1;
                break;

        }
    }




void Menu::readStudents(Data &obj){

    //vector <Student> students;
    //set<Student> allStudents;
    ifstream input("../input/students_classes.csv");
    if(!input.is_open()){
        //perror("Error opening file"); -> acho que só deviamos usar uma
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

        Student s = Student(name_, number);
        obj.addAllStudents(s);
        //students.push_back(s);
        //allStudents.insert(s);

    }

    input.close();
}


void Menu::MenuStudents(Data &obj) {
    readStudents(obj);
    cout << "__________________________________________\n";
    cout << "|              StudentsMenu              |\n";
    cout << "|________________________________________|\n";
    cout << "|                                        |\n";
    cout << "|      1.All Students                    |\n";
    cout << "|      2.Search by UC                    |\n";
    cout << "|      3.Search by Class                 |\n";
    cout << "|      4.Search by Year                  |\n";
    cout << "|________________________________________|\n";

    int opção = 0;
    std:: cin >> opção;
    switch(opção){

        case 1:
            obj.printAllStudents();
            break;
        case 2:
            //MenuTurmas();
            break;
        case 3:
            //MenuUC();
            break;
        case 4:
            //Request();
            break;
        case 5:
            break;

    }

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