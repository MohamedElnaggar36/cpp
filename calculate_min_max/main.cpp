#include <iostream>

using namespace std;

int main()
{
    int max_num, min_num;

    int arr[5];
    cout << "Enter 5 elements of Array : \n";
    for(int i = 0; i < 5; i++){
        cin >> arr[i];
    }
    max_num = arr[0];
    min_num = arr[0];
    for(int i=1; i < 5; i++)
    {
        if(arr[i] > max_num)
            max_num = arr[i];
        if(arr[i] < min_num)
            min_num = arr[i];
    }

    cout<<"\nMax element = " << max_num << "\n";
    cout<<"Min element = " << min_num;
    return 0;
}
