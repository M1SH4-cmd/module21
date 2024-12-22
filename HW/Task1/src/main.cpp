#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool checkTime (string time)
{
    if ((time[2] != ':' || time[5] != ':') || (time.length() != 10)) return false;
    int day = stoi(time.substr(0, 2));
    int month = stoi(time.substr(3, 2));
    int year = stoi(time.substr(6, 4));
    if (day < 0 || day > 31) return false;
    if (month < 1 || month > 12) return false;
}

int main()
{
    cout << "Enter command:" << endl;
    string command;
    cin >> command;

    if (command == "add") {
        ofstream file("..\\list.txt", ios::app);
        string lineToAdd = "";
        string buffer;
        cout << "Type EXIT to exit" << endl;

        while(true) {
            cout << "\nEnter your employees first and second names:\t";
            getline(cin, buffer);
            if (buffer == "EXIT") return 0;
            lineToAdd += buffer;
            cout << "\nEnter cash ammount:\t";
            getline(cin, buffer);
            if (buffer == "EXIT") return 0;
            lineToAdd += buffer;
            cout << "\nEnter time of payment (DD:MM:YYYY):\t";
            getline(cin, buffer);
            if (!checkTime(buffer)) {
                cout << "Invalid time" << endl;
                continue;
            }
            if (buffer == "EXIT") return 0;
            lineToAdd += buffer;
            file << lineToAdd << endl;
        }
    file.close();
    } else if (command == "list"){
        ifstream file("..\\list.txt");
        while(!file.eof()){
            string employee;
            getline(file, employee, '\n');
            cout << employee;
        }
        file.close();
    }
}