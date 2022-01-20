#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
using namespace std;

void gotoxy( int column, int line ){

    COORD coord;
    coord.X = column;
    coord.Y = line;

    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);

}

char* goLeft(char* pcur, char* pst){
    pcur--;
    if(pcur < pst)
        pcur = pst;
    return pcur;
}
char* goRight(char* pcur, char* pend){
    pcur++;
    if(pcur > pend)
        pcur = pend;
    return pcur;
}
char* increaseLine(char* pcur, char*pend){
    if(pcur > pend)
        pend++;
    return pend;
}
char* increaseCurrent(char* pcur){
    pcur++;
    return pcur;
}

void printLine(char* pst){
    //print line
    system("CLS");
    for(int i=0; *(pst + i) != '\0'; i++)
    {
        cout << *(pst + i);
    }
}

void lineEditor(int lineSize){
    char *startp = new char[lineSize];
    char *currentp;
    char *endp;
    char ch;
    int flag = 1;
    if(startp != NULL)
    {
        currentp = startp;
        endp = startp;
        while(flag)
        {
            ch = getch(); //check first input character
            if(ch == -32)
            {
                ch = getch();
                switch (ch)
                {
                case 75:
                    // Left Arrow Clicked
                    currentp = goLeft(currentp, startp);
                    break;
                case 77:
                    // Right Arrow Clicked
                    currentp = goRight(currentp, endp);
                    break;
                case 71:
                    // Home Clicked
                    currentp = startp;
                    break;
                case 79:
                    // End Clicked
                    currentp = endp;
                    break;
                }
                gotoxy((currentp - startp), 1);
            }
            else    //normal key
            {
                if(ch > 32 && ch < 128)
                {
                    cout << ch;
                    *(startp + (currentp - startp)) = ch;
                    currentp = increaseCurrent(currentp);
                    endp = increaseLine(currentp, endp);  //increase line if full
                }
                else if(ch == 13)
                {
                    *(startp + (endp - startp)) = '\0';
                    flag = 0;
                }
                else if(ch == 27)
                {
                    // ESC clicked
                    *startp = '\0';
                    flag = 0;
                }
                else if(ch == 8)
                {

                    *currentp = '\0';
                    cout << '\0';
                    endp = currentp;

                    currentp = goLeft(currentp, startp);

                    gotoxy((currentp - startp), 1);
                }
            }
        }
    }

    printLine(startp);
}
int main()
{
    int lineSize;
    cout << "Enter Line Size: ";
    cin >> lineSize;
    lineEditor(lineSize);

    return 0;
}
