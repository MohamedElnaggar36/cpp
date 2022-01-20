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

int add(int num1, int num2){
    return num1 + num2;
}
int subtract(int num1, int num2){
    return num1 - num2;
}
int multiply(int num1, int num2){
    return num1 * num2;
}
int divide(int num1, int num2){
    if(num2 == 0)
        return 0;
    else
        return num1 / num2;
}

void addScreen(){
    system("CLS");
    int number1, number2;
    cout << "Enter 2 numbers to be added\n";

    cout << "First Number: ";
    cin >> number1;

    cout << "Second Number: ";
    cin >> number2;
    cout << "Result: " << add(number1, number2);
    gotoxy(10, 10);
    cout << "PRESS HOME TO RETURN >>\n";
    gotoxy(10, 11);
    cout << "OR PRESS ENTER TO RETRY THE PROCESS >>";
}

void subScreen(){
    system("CLS");
    int number1, number2;
    cout << "Enter 2 numbers to be subtracted\n";

    cout << "First Number: ";
    cin >> number1;

    cout << "Second Number: ";
    cin >> number2;
    cout << "Result: " << subtract(number1, number2);
    gotoxy(10, 10);
    cout << "PRESS HOME TO RETURN >>\n";
    gotoxy(10, 11);
    cout << "OR PRESS ENTER TO RETRY THE PROCESS >>";
}

void multiScreen(){
    system("CLS");
    int number1, number2;
    cout << "Enter 2 numbers to be multiplied\n";

    cout << "First Number: ";
    cin >> number1;

    cout << "Second Number: ";
    cin >> number2;
    cout << "Result: " << multiply(number1, number2);
    gotoxy(10, 10);
    cout << "PRESS HOME TO RETURN >>\n";
    gotoxy(10, 11);
    cout << "OR PRESS ENTER TO RETRY THE PROCESS >>";
}

void dividScreen(){
    system("CLS");
    int number1, number2;
    cout << "Enter 2 numbers to be divided\n";

    cout << "First Number: ";
    cin >> number1;

    cout << "Second Number: ";
    cin >> number2;
    cout << "Result: " << divide(number1, number2);
    gotoxy(10, 10);
    cout << "PRESS HOME TO RETURN >>\n";
    gotoxy(10, 11);
    cout << "OR PRESS ENTER TO RETRY THE PROCESS >>";
}

void showMenu(){
    int x = 5;
    int y = 5;
    bool selected = true;
    gotoxy(5,5);
    cout << "1. Add";
    gotoxy(5,6);
    cout << "2. Subtract";
    gotoxy(5,7);
    cout << "3. Multiply";
    gotoxy(5,8);
    cout << "4. Divide";
    gotoxy(5,9);
    cout << "5. Exit";
    while(selected){
    char ch = getch();
    if((int)ch == -32){
        ch = getch();
        switch(ch){
        case 72:
            gotoxy(x,y-1);
            y--;
            break;
        case 80:
            gotoxy(x,y+1);
            y++;
            break;
        case 71:
            system("CLS");
            showMenu();
            }
            while(y < 5){
                y++;
                gotoxy(5,5);
            }
            while(y > 9){
                y--;
                gotoxy(5,9);
            }
        }
    else if((int)ch == 13){
            if (y == 5){
                gotoxy(7,12);
                cout << "add";
                addScreen();
            }
            else if(y == 6){
                gotoxy(7,12);
                cout << "subtract";
                subScreen();
            }
            else if(y == 7){
                gotoxy(7,12);
                cout << "Multiply";
                multiScreen();
            }
            else if (y == 8){
                gotoxy(7,12);
                cout << "Divide";
                dividScreen();
            }
            else if(y == 9){
                exit(0);
            }
        }
    }
}

int main(){
    showMenu();
    return 0;
}

