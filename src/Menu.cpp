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

        switch(opção){

            case 1:
                MenuStudents();
                break;
            case 2:
                MenuTurmas();
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
        /*cout << "__________________________________________\n";
        cout << "|              1. ENGLISH:               |\n";
        cout << "|             2. PORTUGUESE:             |\n";
        cout << "|________________________________________|\n";
        cin >> language;
        if(language == 2){
            cout << "__________________________________________\n";
            cout << "|             MenuPrincipal              |\n";
            cout << "|     Escolha uma das seguintes opções   |\n";
            cout << "|________________________________________|\n";
            cout << "|      1. VER ESTUDANTES:                |\n";
            cout << "|      2. VER TURMAS:                    |\n";
            cout << "|      3. VER UC:                        |\n";
            cout << "|      3. PEDIDO DE MUDANÇA:             |\n";
            cout << "|      4. GUARDAR E SAIR:                |\n";
            cout << "|      5. SAIR SEM SALVAR:               |\n";
            cout << "|________________________________________|\n";
            cout << "A tua opção:\n";
            cin >> opção;
        }
        if(language == 1){*/

       // }

    void Menu::MenuStudents() {
        cout << "__________________________________________\n";
        cout << "|              StudentsMenu              |\n";
        cout << "|________________________________________|\n";
        readStudents();
    }
    void Menu::readStudents(){
        ifstream input("../input/students_classes.csv");
        if(!input.is_open()){
            perror("Error opening file");
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
            student.push_back(s);
        }
        for (auto x: student){
            cout << x.getname() << " " << x.getupcode() << endl;
        }
        input.close();
    }
    void Menu::MenuTurmas(){
        cout << "__________________________________________\n";
        cout << "|              ClassesMenu               |\n";
        cout << "|________________________________________|\n";
        readTurmas();

}
        void Menu::readTurmas(){
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
                    Slot slot = Slot(weekday,start,duration,type);
                    schedule.push_back(slot);
                }
                for (auto x: classuc){
                    cout << x.first << " " << x.second <<endl;
                }
                for (auto y: schedule){
                    cout << y.getweekday() << y.getstart() << y.getduration() << y.gettype() << endl;
                }
                input.close();
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