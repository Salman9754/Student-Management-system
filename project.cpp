#include <iostream>
#include <fstream>

using namespace std;

class temp {
    string rollNum, name, fName, address, search;
    fstream file;

public:
    void addStu();
    void viewStu();
    void searchStu();
} obj;

typedef string Str;
typedef fstream FStream;

int main() {
    while (true) {
        char choice;
        cout << "\n";
        cout << "1- Add Student Record\n";
        cout << "2- View All Student Record\n";
        cout << "3- Search Student Record\n";
        cout << "4- Exit\n";
        cout << "-- ";
        cin >> choice;
        switch(choice) {
            case '1':
                obj.addStu();
                break;
            case '2':
                obj.viewStu();
                break;
            case '3':
                obj.searchStu();
                break;
            case '4':
                return 0;
            default:
                cout << "Invalid Choice...!\n";
        }
    }
}

void temp::addStu() {
    Str rollNum, name, fName, address;
    cout << "Enter Student Roll Number : ";
    cin.ignore();
    getline(cin, rollNum);
    cout << "Enter Student Name : ";
    getline(cin, name);
    cout << "Enter Student Father Name : ";
    getline(cin, fName);
    cout << "Enter Student Address : ";
    getline(cin, address);

    FStream file;
    file.open("stuData.txt", ios::out | ios::app);
    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    file << rollNum << "*";
    file << name << "*";
    file << fName << "*";
    file << address << endl;

    file.close();
}

void temp::viewStu() {
    Str rollNum, name, fName, address;
    FStream file;
    file.open("stuData.txt", ios::in);
    while (getline(file, rollNum, '*')) {
        getline(file, name, '*');
        getline(file, fName, '*');
        getline(file, address, '\n');
       cout<<endl;
        cout << "Student Roll Number : " << rollNum;
        cout<<endl;
        cout << "Student Name : " << name;
      cout <<endl;
        cout << "Student Father Name : " << fName;
        cout<<endl;
        cout << "Student Address : " << address;
    }
    file.close();
}

void temp::searchStu() {
    Str rollNum, name, fName, address;
    FStream file;
    cout << "Enter Student Roll Number : ";
    cin.ignore();
    getline(cin, search);
    file.open("stuData.txt", ios::in);
    while (getline(file, rollNum, '*')) {
        getline(file, name, '*');
        getline(file, fName, '*');
        getline(file, address, '\n');
        if (rollNum == search) {
            cout << endl;
            cout << "Student Roll Number: " << rollNum;
            cout<<endl;
            cout << "Student Name: " << name;
            cout<<endl;
            cout << "Student Father Name : " << fName;
            cout<<endl;
            cout << "Student Address : " << address;
        }
    }
    file.close();
}