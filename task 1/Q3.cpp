#include <iostream>
using namespace std;

void swapping(int arr[], int size)
{
    int *arrptr = arr;

    for (arrptr; arrptr < arr + size; arrptr += 2)
    {
        int *tempptr = new int;
        *tempptr = *arrptr;
        *arrptr = *(arrptr + 1);
        *(arrptr + 1) = *tempptr;
        cout << *arrptr << endl << *(arrptr + 1) << endl;
        // arrptr = (arrptr + 1);
        delete tempptr;  
    }
}

int main()
{
    int arr[6] = {2, 1, 4, 3, 6, 5};

    void (*ptrfunction)(int*, int);
    ptrfunction = &swapping;

    ptrfunction(arr, 6);
    cout << "Array after swapping\n";
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}