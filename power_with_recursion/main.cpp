#include <iostream>

using namespace std;

int calculatePower(int num, int pow){
    if(pow != 0){
        return (num*calculatePower(num, pow-1));
    }
    else{
        return 1;
    }
}

int main()
{
    int base, power;
    cout << "Enter Base Number: ";
    cin >> base;
    cout << "Enter Power: ";
    cin >> power;
    cout << "Result of " << base << "^" << power << " = " << calculatePower(base, power);
    return 0;
}
