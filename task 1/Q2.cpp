#include <iostream>
using namespace std;
int checking(int *arr, int size)
{
    int *temp = arr;
    int total=0;
    cout<<temp<<endl;
    cout<<*temp<<endl;
    for (temp; temp < arr + size; temp++)
    {
        total += *temp;
    }
    cout<<total<<endl;
    return total;
}
int main()
{
    int arr[5] = {8, 4, 3, 2, 1};
    int num;
    int *numptr = &num;
    int *arrPtr = arr;
    cout << "Enter the number\n";
    cin >> num;

    int (*ptrfunc)(int *, int);
    ptrfunc = &checking;
    int result;
    result = ptrfunc(arrPtr, 5);
    cout<<result<<endl;
    if (result == *numptr)
    {
        cout << "The sum of array is equal to the given number\n";
    }
    else
    {
        cout << "The sum is not equal to the given number\n";
    }

    return 0;
}