#include <iostream>
using namespace std;
void display(int arr[], int size)
{
    int *ptr = arr;
    // cout<<ptr<<endl;
    // cout<<*ptr;

    for (ptr; ptr <= arr + size - 1; ptr++)
    {
        cout << *ptr << endl;
    }
    // ptr--;
    // for (ptr; ptr <= arr + size; ptr++)
    // {
    //     cout << *++ptr<<endl;
    // }
}
int main()
{
    int arr[5] = {4, 2, 3, 8, 7};
    display(arr, 5);

    return 0;
}