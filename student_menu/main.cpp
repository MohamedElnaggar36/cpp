#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

void gotoxy( int column, int line ){

    COORD coord;
    coord.X = column;
    coord.Y = line;

    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);

}
struct student{
    int id;
    char name[50];
    int grads[5];
};

student addStudent(int stdId)
{
    //Method To Insert
    student students;
    cout << "student ID = ";
    students.id = stdId;
    cout << stdId << endl;

    cout << "Enter student name: ";
    cin >> students.name;

    for(int i = 0; i < 5; i++){
        cout << "Grad " << i + 1 << " = ";
        cin >> students.grads[i];

    }
    cout << "<< Added Successfully >>" << endl;
    return students;
}

void displayStudent(student students)
{
    //Method To Display
    cout << "ID = " << students.id << endl;
    cout << "Name = " << students.name << endl;
    for(int i = 0; i < 5; i++){
        cout << "Grad " << i + 1 << " = " << students.grads[i] << endl;
    }
    cout << "================================" << endl;
}

void displayMenu(){
    gotoxy(5,5);
    cout << "1. Add" << endl;
    gotoxy(5,6);
    cout << "2. Display" << endl;
    gotoxy(5,7);
    cout << "3. Display All" << endl;
    gotoxy(5,8);
    cout << "4. Exit" << endl;
}

int main(){
    cout << "Enter Students Total number: ";
    int num = 0;
    cin >> num;
    student *st = new student[num];
    int flag = 1;
    while(flag){
        displayMenu();
        int select;
        cin >> select;
        switch(select){
        case 1:
            system("CLS");
            gotoxy(10,10);
            cout << "Add";
            gotoxy(10, 11);
            int stdID;
            cout << "Student ID = ";
            cin >> stdID;
            if(stdID > num){
                cout << "More Than Total students number !!";
            }
            else{
               *(st+(stdID-1))=addStudent(stdID);
            }
            break;
        case 2:
            system("CLS");
            gotoxy(10,10);
            cout << "Display";
            gotoxy(10,11);
            int id;
            cout << "Enter student id to display: ";
            cin >> id;
            displayStudent(*(st+(id-1)));
            break;
        case 3:
            system("CLS");
            gotoxy(10,10);
            cout << "Display All" << endl;
            for(int i = 0; i < num; i++){
                displayStudent((st[i]));
            }
            break;
        case 4:
            system("CLS");
            gotoxy(10,10);
            cout << "Exit";
            gotoxy(10,11);
            return 0;
            break;
        }
    }


    return 0;
}
