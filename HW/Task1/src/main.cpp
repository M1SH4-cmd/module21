#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
using namespace std;

struct employee {
    string name;
    double cash;
    string payday;
    time t;

    void printEmployee(){
        printf("%s %s %s", name, cash, payday);
    }
};

struct time{
    int day;
    int month;
    int year;
};

bool checkTime (time t)
{
    if (t.day < 0 || t.day > 31) return false;
    if (t.month < 1 || t.month > 12) return false;
    if (t.year < 2024 || t.year > 9999) return false;
}

int main()
{
    cout << "Enter command:" << endl;
    string command;
    cin >> command;

    if (command == "add") {
        ofstream file("..\\list.txt", ios::app);
        cout << "Type EXIT to exit" << endl;

        while(true) {
            employee man;
            cout << "\nEnter your employees first and second names:\t";
            getline(cin, man.name);
            if (man.name == "EXIT") return 0;
            file << man.name;

            cout << "\nEnter time of payment (DD MM YYYY):\t";
            time t;
            cin >> t.day >> t.month >> t.year;
            if (!checkTime(t)) {
                cout << "Invalid time" << endl;
                continue;
            }
            file << t;

            cout << "\nEnter cash ammount:\t";
            cin >> man.cash;
            file << man.cash << endl;
        }
    file.close();
    } else if (command == "list"){
        vector<employee> employees;
        ifstream file("..\\list.txt");
        for(int i = 0; !file.eof(); i++){
            employee worker;
            file >> worker.name;
            file >> worker.time;
            file >> worker.cash;
            employees[i].push_back(worker);
        }
        file.close();
    }
}