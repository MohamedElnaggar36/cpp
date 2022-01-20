#include<iostream>
using namespace std;
int main()
{
    int Size, num, row, col;
    cout << "Enter a size: ";
    cin >> Size;
    // check that its not odd;
    if(Size % 2 == 0){
        cout << "\tInvalid input not odd number !!\n";
    }
    else{
        for(num = 1; num <= Size*Size; num++){
            if(num == 1){
                col = Size/2 + 1;
                row = 1;
            }
            else if((num - 1) % Size == 0){
                row ++;
            }
            else{
                row--;
                col--;
                if(row == 0){
                    row = Size;
                }
                if(col == 0){
                    col = Size;
                }
            }
            cout << num << " in "<< " ( " << row << " , " << col << " ) " << "\n";
        }
    }
}
